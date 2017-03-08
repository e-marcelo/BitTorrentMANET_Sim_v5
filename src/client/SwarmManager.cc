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

#include "SwarmManager.h"

Define_Module(SwarmManager);

void SwarmManager::initialize()
{
    cModule *bitTorrentClient = getParentModule()->getSubmodule("bitTorrentClient");
    if(bitTorrentClient == NULL){
        std::cerr << "BitTorrentClient module not found\n";
    }else{
        this->bitTorrentClient = check_and_cast<BitTorrentClient *>(bitTorrentClient);
        //Identificador del nodo
        this->localPeerId = this->getParentModule()->getId();
    }
}

void SwarmManager::handleMessage(cMessage *msg)
{
    if(msg->arrivedOn("userCommand")){
        treatUser(msg);
//        std::cerr << "Torrente :: \tInfoHash = "<< this->contents.at("small").infoHash << " | Piezas = " <<this->contents.at("small").numOfPieces <<"\n";
    }
    if(msg->arrivedOn("peerBitField")){
        //Modo promiscuo!
        std::cerr << this->localPeerId << " | Recibiendo... \n";
    }
}

void SwarmManager::treatUser(cMessage* msg) {

    cObject *controlInfo = msg->getControlInfo();
    if(msg->getKind() == USER_COMMAND_ENTER_SWARM){
        EnterSwarmCommand *enterSwarmCommand = check_and_cast<EnterSwarmCommand *>(controlInfo);
//        std::cerr << "Recibiendo :: " << enterSwarmCommand->getTorrentMetadata().numOfPieces << " | Seed = " << enterSwarmCommand->getSeeder() << "\n";
        this->enterSwarm(enterSwarmCommand->getTorrentMetadata(),enterSwarmCommand->getSeeder(), enterSwarmCommand->getIdDisplay());
    }
    delete msg;
//    switch(msg->getKind()){
//        case 0://Semilla
////            std::cerr << "Hola soy semilla :: "<< this->localPeerId <<"\n";
//            bitTorrentClient->createSwarm(0,0,0,0,0);
//            break;
//        case 1://Sanguijuela
////            std::cerr << "Hola soy sanguijuela :: "<< this->localPeerId <<"\n";
//            bitTorrentClient->createSwarm(1,0,0,0,0);
//            break;
//        default:
//            std::cerr << "Comando no encontrado!\n";
//    }

}

void SwarmManager::enterSwarm(const TorrentMetadata& torrentInfo, bool seed,  int idDisplay) {
    //Iniciamos la creación del enjambre
    bitTorrentClient->createSwarm(torrentInfo.infoHash,torrentInfo.numOfPieces,torrentInfo.numOfSubPieces,torrentInfo.subPieceSize,seed, idDisplay);
}
