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

/*! Create ControlInfo object common to all announce messages.
EnterSwarmCommand createDefaultControlInfo(
    TorrentMetadata const& torrentMetadata,
    L3Address const& trackerAddress, int trackerPort) {
        // these parameters are default for all announce messages sent
    EnterSwarmCommand enterSwarmCommand;
    enterSwarmCommand.setTorrentMetadata(torrentMetadata);
    enterSwarmCommand.setTrackerAddress(trackerAddress);
    enterSwarmCommand.setTrackerPort(trackerPort);

    return enterSwarmCommand;
}*/

    //! Create the announce message that will be sent to the passed SwarmManager.
    cMessage * createAnnounceMsg(bool seeder, SwarmManager * swarmManager) {
        // create the message and set the control info
        cMessage *msg = new cMessage("Init");
        msg->setContextPointer(swarmManager);
        //USER_COMMAND_ENTER_SWARM -> 0
        if(seeder)
            msg->setKind(0); //Identificador de Semilla
        else
            msg->setKind(1); //Identificador de Par
        return msg;
    }



    //! Schedule the announce messages to all BitTorrent applications.
    void scheduleStartMessages(ClientController * self, simtime_t const& startTime,/*,simtime_t const& interarrivalTime,*/ long const numSeeders) {
        cTopology topo;
        topo.extractByProperty("peer");
        simtime_t enterTime = startTime;
        for (int i = 0; i < topo.getNumNodes(); ++i) {
            cModule *mod = topo.getNode(i)->getModule()->getSubmodule("swarmManager"); //Referencia al módulo swarm de cada par
            SwarmManager *swarmManager = (SwarmManager *)(mod);
            bool seeder = i < numSeeders;
            cMessage *msg = createAnnounceMsg(seeder,swarmManager);
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
            /*cXMLElementList contentList = profile->getChildrenByTagName("content");
            if (contentList.empty()) {
                throw cException("List of contents is empty. Check the xml file");
            }*/

            std::cerr << "Configuración del módulo ClientController :: Completo\n";
            EV<<"Configuración del módulo ClientController :: Completo\n";

            /*cXMLElementList::iterator it = contentList.begin();
            for (int num = 0; it != contentList.end(); ++it, ++num) {
                using boost::lexical_cast;

                char const* contentName = (*it)->getFirstChildWithTag("name")->getNodeValue();
                simtime_t interarrival = lexical_cast<double>((*it)->getFirstChildWithTag("interarrival")->getNodeValue());
                scheduleStartMessages(this, startTime, interarrival,numSeeders);
            }*/
            scheduleStartMessages(this, startTime,numSeeders);
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
            throw cException("This module doesn't process messages");
            std::cerr << "Erro ClientController :: This module doesn't process messages\n";
    }
    cModule *mod = (cModule *) msg->getContextPointer();
    if (mod == NULL) {
           std::cerr <<"Módulo SwarmManager, no encontrado\n";
           EV << "Módulo SwarmManager, no encontrado\n";
    }else{
        EV << "Enviando comando :: userCommand \n";
        std::cerr <<"Enviando comando :: userCommand \n";
        sendDirect(msg, mod, "userCommand");
    }
}

