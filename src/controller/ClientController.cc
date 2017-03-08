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

#include "ClientController.h"
#include "UserCommand_m.h"

#define simulation  (*cSimulation::getActiveSimulation())
using omnetpp::exponential;

Define_Module(ClientController);

// helper functions in anonymous workspace
namespace {

//! Create ControlInfo object common to all announce messages.
EnterSwarmCommand createDefaultControlInfo(
    TorrentMetadata const& torrentMetadata) {
    // these parameters are default for all announce messages sent
    EnterSwarmCommand enterSwarmCommand;
    enterSwarmCommand.setTorrentMetadata(torrentMetadata);
    return enterSwarmCommand;
}

    //! Create the announce message that will be sent to the passed SwarmManager.
    cMessage * createAnnounceMsg(EnterSwarmCommand const& defaultControlInfo, bool seeder, SwarmManager * swarmManager, int idDisplay) {
        // create the message and set the control info
        cMessage *msg = new cMessage("Init");
        msg->setContextPointer(swarmManager);
        //USER_COMMAND_ENTER_SWARM -> 0
        msg->setKind(USER_COMMAND_ENTER_SWARM); //Identificador de Semilla

        //Each new message needs a new control info
        //Update the seeder status in tje control info
        EnterSwarmCommand *enterSwarmCommand = defaultControlInfo.dup();
        enterSwarmCommand->setSeeder(seeder);
        enterSwarmCommand->setIdDisplay(idDisplay);
        msg->setControlInfo(enterSwarmCommand);
//        if(seeder)
//            msg->setKind(0); //Identificador de Semilla
//        else
//            msg->setKind(1); //Identificador de Par
        return msg;
    }



    //! Schedule the announce messages to all BitTorrent applications.
    void scheduleStartMessages(ClientController * self, simtime_t const& startTime,/*,simtime_t const& interarrivalTime,*/ long const numSeeders,EnterSwarmCommand const& defaultControlInfo) {
        cTopology topo;
        topo.extractByProperty("peer");
        simtime_t enterTime = startTime;
        for (int i = 0; i < topo.getNumNodes(); ++i) {
            cModule *mod = topo.getNode(i)->getModule()->getSubmodule("swarmManager"); //Referencia al módulo swarm de cada par
            SwarmManager *swarmManager = (SwarmManager *)(mod);
            bool seeder = i < numSeeders;
            cMessage *msg = createAnnounceMsg(defaultControlInfo,seeder,swarmManager,i);
            // The first peers set to seeders and start imediatelly
            if (seeder) {
                self->scheduleAt(enterTime, msg);
            } else {
                self->emitEnterTime(enterTime);
                self->scheduleAt(enterTime, msg);
            }
        }
    }
}
// Starting point of the simulation
void ClientController::initialize(int stage)
{
    if (stage == 0) {
            //Registro de la señal (para las estadísticas)
            this->enterTime_Signal = registerSignal("ClientController_EnterTimeSignal");
            counter = 0;
     } else if (stage == 3) {
            int numSeeders = par("numSeeders").longValue(); //Configuracion del número de semillas
            simtime_t startTime = par("startTime").doubleValue();
            // verify parameters
            if (numSeeders < 1) {
                throw cException("The number of seeders must be larger than 1");
            }

            // Read all contents from the xml file.
            cXMLElementList contentsList =
                    par("contents").xmlValue()->getChildrenByTagName("content");

            if (contentsList.empty()) {
                throw std::invalid_argument(
                        "List of contents is empty. Check the xml file");
            }
            cXMLElementList::iterator it = contentsList.begin();
            int key = 0;
            for (; it != contentsList.end(); ++it) {
                TorrentMetadata torrentMetadata;
                cXMLElement * child;

                // create the torrent metadata
                child = (*it)->getFirstChildWithTag("numOfPieces");
                torrentMetadata.numOfPieces = atoi(child->getNodeValue());
                child = (*it)->getFirstChildWithTag("numOfSubPieces");
                torrentMetadata.numOfSubPieces = atoi(child->getNodeValue());
                child = (*it)->getFirstChildWithTag("subPieceSize");
                torrentMetadata.subPieceSize = atoi(child->getNodeValue());
                torrentMetadata.infoHash = key;
                this->swarms[torrentMetadata.infoHash];
                // save a list of torrents for each video content
                std::string contentName((*it)->getAttribute("name"));
                this->contents[contentName] = torrentMetadata;
                key ++; //Identificador del contenido en un orden creciente: 0,1,2,..n
            }

            //Prueba con el contenido seleccionado
            TorrentMetadata const& torrentMetadata = this->contents.at("small");

            EnterSwarmCommand const& defaultControlInfo = createDefaultControlInfo(torrentMetadata);

            scheduleStartMessages(this, startTime,numSeeders,defaultControlInfo);
            this->updateStatusString();
        }
}

void ClientController::receiveSignal(cComponent* source, simsignal_t signalID,long l) {
}

ClientController::ClientController() {
}

ClientController::~ClientController() {
}

void ClientController::emitEnterTime(simtime_t enterTime) {
    emit(this->enterTime_Signal, enterTime);
}


void ClientController::printDebugMsg(std::string s) {
}

void ClientController::updateStatusString() {
}

void ClientController::subscribeToSignals() {
    subscribe("ContentManager_BecameSeeder", this);
}

int ClientController::numInitStages() const {
    return 4;
}

void ClientController::handleMessage(cMessage *msg)
{
    if (!msg->isSelfMessage()) {
            std::cerr << "Error ClientController :: This module doesn't process messages\n";
            throw cException("This module doesn't process messages");
    }
    cModule *mod = (cModule *) msg->getContextPointer();
    if (mod == NULL) {
           std::cerr <<"Módulo SwarmManager, no encontrado\n";
           EV << "Módulo SwarmManager, no encontrado\n";
    }else{
//        std::cerr <<"Enviando comando :: userCommand \n";
//        EV << "Enviando comando :: userCommand \n";
        sendDirect(msg, mod, "userCommand");
    }
}

