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
    }
}

void SwarmManager::treatUser(cMessage* msg) {

    switch(msg->getKind()){
        case 0://Semilla
            std::cerr << "Hola soy semilla :: "<< this->localPeerId <<"\n";
            break;
        case 1://Sanguijuela
            std::cerr << "Hola soy sanguijuela :: "<< this->localPeerId <<"\n";
            break;
        default:
            std::cerr << "Comando no encontrado!\n";
    }

}
