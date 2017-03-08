//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "BitTorrentClient.h"

#include <algorithm>
#include <iostream>
#include <iomanip>
//[EAM]#include <IPAddressResolver.h>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
//#include <UDPSocket.h>
//#include "Application_m.h"
//#include "PeerWire_m.h"
//#include "PeerWireMsgBundle_m.h"
//#include "PeerWireThread.h"
//#include "Choker.h"
//#include "ContentManager.h"
#include "SwarmManager.h"
//#include <INetworkProtocolControlInfo.h>
using omnetpp::cSimulation;
// Dumb fix because of the CDT parser (https://bugs.eclipse.org/bugs/show_bug.cgi?id=332278)
#ifdef __CDT_PARSER__
#undef BOOST_FOREACH
#define BOOST_FOREACH(a, b) for(a; b; )
#endif


// Helper functions
// helper functions in anonymous workspace
namespace {

//! Create ControlInfo object common to all announce messages.
    EnterSwarmCommand createDefaultControlInfo() {
        // these parameters are default for all announce messages sent
        EnterSwarmCommand enterSwarmCommand;
        // enterSwarmCommand.setTorrentMetadata(torrentMetadata);
        return enterSwarmCommand;
    }

    //! Create the announce message that will be sent to the passed SwarmManager.
    cMessage * createAnnounceMsg(EnterSwarmCommand const& defaultControlInfo, bool seeder, SwarmManager * swarmManager, int idDisplay) {
        // create the message and set the control info
        cMessage *msg = new cMessage("BitField");
        msg->setContextPointer(swarmManager);
        //USER_COMMAND_ENTER_SWARM -> 0
        msg->setKind(USER_COMMAND_ENTER_SWARM); //Identificador de Semilla

        //Each new message needs a new control info
        //Update the seeder status in tje control info
        EnterSwarmCommand *enterSwarmCommand = defaultControlInfo.dup();
        enterSwarmCommand->setSeeder(seeder);
        enterSwarmCommand->setIdDisplay(idDisplay);
        msg->setControlInfo(enterSwarmCommand);

        return msg;
    }



    //! Schedule the announce messages to all BitTorrent applications.
    void scheduleStartMessages(int idNode, BitTorrentClient * self, simtime_t const& startTime,long const numSeeders,
            EnterSwarmCommand const& defaultControlInfo) {
        cTopology topo;
        topo.extractByProperty("peer");
        simtime_t enterTime = startTime;

        cModule *mod = topo.getNode(idNode)->getModule()->getSubmodule("swarmManager"); //Referencia al módulo swarm de cada par
        SwarmManager *swarmManager = (SwarmManager *)(mod);
        bool seeder = false;
        cMessage *msg = createAnnounceMsg(defaultControlInfo,seeder,swarmManager,idNode);
        // The first peers set to seeders and start imediatelly
        self->scheduleAt(enterTime, msg);
    }
}


Define_Module(BitTorrentClient);

using inet::TCPSrvHostApp;

Register_Class(BitTorrentClient);

void BitTorrentClient::closeConnection(int infoHash, int peerId) const {
}

void BitTorrentClient::finishedDownload(int infoHash) {
}

void BitTorrentClient::sendHaveMessages(int infoHash, int pieceIndex) const {
}

void BitTorrentClient::sendPieceMessage(int infoHash, int peerId) const {
}

int BitTorrentClient::getLocalPeerId() const {
}

void BitTorrentClient::deleteSwarm(int infoHash) {
}

void BitTorrentClient::finish() {
}

void BitTorrentClient::findLocalNeighborhood() {
    //Considerando la posición actual del nodo, se identifica que pares se encuentran a "1-salto" (vecindario local)
    currentPosition(this->strCurrentNode.c_str(),&(this->peerX),&(this->peerY)); //Coordenada (x,y) del nodo actual
//    std::cerr << "Nodo :: " << this->localIdDisplay << " | Posición :: " <<  this->peerX << ", " << this->peerX <<"\n";
    int x2;
    int y2;
    int peerIdNode;
    int d = -1; //Distancia entre los pares (redondeo de entero)
    int x_ = -1;
    int y_ = -1;
    int r_ = -1;
    //Reutilizando variables
    this->strArgNode.clear();
    this->optNumtoStr.str("");

    for(int i=0; i<this->globalNumberOfPeers; i++){
        this->strArgNode = std::string("peer[");
        this->optNumtoStr << i;
        this->strArgNode.append(this->optNumtoStr.str());
        this->strArgNode.append("]");
        peerIdNode = getSimulation()->getModuleByPath(this->strArgNode.c_str())->getId();

        if(this->localPeerId != peerIdNode){ //Cuidamos que no se trate del par actual
            //Obtenemos coordenadas del par
//            std::cerr << "Nodo ::: " << this->strArgNode.c_str();
            currentPosition(this->strArgNode.c_str(),&x2,&y2);
            //Incluir validanciones
            x_ = std::pow((double)(x2-this->peerX),2);
            y_ = std::pow((double)(y2-this->peerY),2);
            d = std::sqrt((x_+y_));
            std::cerr << this->strCurrentNode.c_str() <<" -> Distancia :: " << d << "\n";
            //De acuerdo al umbral es como se permite el envio
            if(d <= this->communicationRange){ //Se permite la igualdad (considerar el error de redondeo*)
                //Enviando <<bitField>> del contenido que tiene una semilla
                //Conexión "Hello"!
                sendBroadcast(i);
            }
//          std::cerr << " | Posición :: " <<  x2 << ", " << y2 <<"\n";
            //Distancia entre el par actual y el par que estamos visitando
        }

        this->strArgNode.clear();
        this->optNumtoStr.str("");
    }
}

void BitTorrentClient::currentPosition(const char* peer, int *x, int *y) {
    //Localización del nodo actual en el escenario de simulación
    //Leyenda del nodo actual
    std::string pos = getSimulation()->getModuleByPath(peer)->getDisplayString().str();
//    std::cerr << "Nodo :: " << pos <<"\n";
    //Separador de las propiedades de la leyenda del nodo
    boost::char_separator<char> sep(";");
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
    //Recorrido entre los parámetros de la leyenda del nodo
    tokenizer mytokenizer(pos,sep);
    for(auto& token: mytokenizer){
        this->strArgNode = token; //Primera posición
        break;

    }

    //    std::cerr << "Nodo :: " << this->idDisplay << " | Posición :: " <<  this->newArg <<"\n";
    //Separando coordenadas (x,y) del nodo actual de acuerdo a su leyenda en el escenario de simulación
    boost::char_separator<char> sepA("=");
    tokenizer mytokenizerA(this->strArgNode,sepA);
    //Posicion del par
    for(auto& token: mytokenizerA){
        pos = token; //Última posición
    }
    //Posicion en X , Y
    boost::char_separator<char> sepB(",");
    tokenizer mytokenizerB(pos,sepB);
    //Contador a cero (para reutilizarlo)
    this->count = 0;
    for(auto& token: mytokenizerB){
        if(this->count == 0){
            this->strArgNode = token;
            *x = std::atoi(this->strArgNode.c_str());
        }else{
            this->strArgNode = token;
            *y = std::atoi(this->strArgNode.c_str());
        }
        this->count++; //Solo dos posiciones son consideradas
    }
    //Variables reutilizables
    this->count = 0;
    this->strArgNode.clear();
    //    std::cerr << "Nodo :: " << this->localIdDisplay << " | Posición :: " <<  this->peerX << ", " << this->peerY <<"\n";

}

void BitTorrentClient::initialize(int stage)
{

      if (stage == 3) {
           // create a listening connection
          TCPSrvHostApp::initialized();
          this->swarmManager = check_and_cast<SwarmManager*>(getParentModule()->getSubmodule("swarmManager"));
          this->localPeerId = this->getParentModule()->getParentModule()->getId();
          this->localPort = par("localPort");
          this->globalNumberOfPeers = par("globalNumberOfPeers");
          this->communicationRange = par("communicationRange");
      }

}

BitTorrentClient::BitTorrentClient()/*: endOfProcessingTimer("End of processing"), doubleProcessingTimeHist(
"Piece processing time histogram"), snubbedInterval(0), timeoutInterval(0), keepAliveInterval(0), downloadRateInterval(0), uploadRateInterval(0), localPort(-1), localPeerId(-1), debugFlag(false), globalNumberOfPeers(0), numActiveConn(0), numPassiveConn(0), prevNumUnconnected(0), prevNumConnected(0) */
{
}


BitTorrentClient::~BitTorrentClient() {
}
void BitTorrentClient::createSwarm(int infoHash, int numOfPieces,
        int numOfSubPieces, int subPieceSize, bool newSwarmSeeding, int idDisplay) {
//        Enter_Method("addSwarm(infoHash: %d, %d)", infoHash, newSwarmSeeding);
        Enter_Method_Silent();
        //Configurar arreglo con el contenido digital
        this->localIdDisplay = idDisplay;
        //Cadena de caracteres que identifica al nodo en el escenario de simulación
        this->strCurrentNode = std::string("peer[");
        this->optNumtoStr << idDisplay;
        this->strCurrentNode.append(this->optNumtoStr.str());
        this->strCurrentNode.append("]");
//        std::cerr << this->strCurrentNode <<"\n";

        if(newSwarmSeeding){ //
//            this->localPeerId = infoHash;
            std::cerr << "Soy semilla \t -> ";
            findLocalNeighborhood();
//            helloMsgTimer = new cMessage("HelloMsgTimer");
//            scheduleAt(simTime() + 10, helloMsgTimer);
        }
//        currentPosition(this->strCurrentNode.c_str(),&(this->peerX),&(this->peerY)); //Coordenada (x,y) del nodo actual
//        std::cerr << "Nodo :: " << this->localIdDisplay << " | Posición :: " <<  this->peerX << ", " << this->peerX <<"\n";


}

void BitTorrentClient::handleMessage(cMessage *msg)
{
    if (!msg->isSelfMessage()) {
                std::cerr << "Error BitTorrentClient :: This module doesn't process messages\n";
    }
    cModule *mod = (cModule *) msg->getContextPointer();
    if (mod == NULL) {
        std::cerr <<"Módulo SwarmManager, no encontrado\n"; //Cambiar al modulo BitTorrent
        EV << "Módulo SwarmManager, no encontrado\n";
    }else{
        sendDirect(msg, mod, "peerBitField");
    }
}

void BitTorrentClient::sendBroadcast(int idNode/*cPacket *packet, const L3Address& destAddr, unsigned int timeToLive, double delay*/)
{
    //1.- Descubrir vecinos a un salto
    //2.- Conectar y enviar mensaje a los vecinos (prueba)
    EnterSwarmCommand const& defaultControlInfo = createDefaultControlInfo();
    scheduleStartMessages(idNode,this, simTime()+3,0,defaultControlInfo);
    //

}

int BitTorrentClient::numInitStages() {
}
