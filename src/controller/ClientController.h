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

#ifndef __BITTORRENT_CLIENTCONTROLLER_H_
#define __BITTORRENT_CLIENTCONTROLLER_H_
#include <omnetpp.h>
#include <cstdint>

using namespace omnetpp;
//#include <cListener.h>
#include <list>
using omnetpp::cListener;
using omnetpp::cMessage;
using omnetpp::simtime_t;
using omnetpp::cComponent;
using omnetpp::exponential;

//[EAM]#include <cXMLElement.h>
using omnetpp::cXMLElement;
#include <cstring>
#include <boost/lexical_cast.hpp>
//[EAM]#include <cTopology.h>
using omnetpp::cTopology;
//[EAM]#include "TrackerApp.h"
//[EAM]using namespace inet;
#include <L3Address.h>
#include <L3AddressResolver.h>
using inet::L3Address;
using inet::L3AddressResolver;
#include "PeerInfo.h"
class SwarmManager;



//Archivo con extensión *.torrent
struct TorrentMetadata {
    int numOfPieces;
    int numOfSubPieces;
    int subPieceSize;
    int infoHash;
};


typedef std::set<PeerInfo> SwarmPeerList;


/**
 * This module is responsible for controlling the Client's behavior: what content
 * to download, when to start downloading, how long should the seeding time be.
 */
class ClientController: public cSimpleModule, cListener {
public:
    //!cListener overloaded method
    void receiveSignal(cComponent *source, simsignal_t signalID, long l);
public:
    ClientController();
    virtual ~ClientController();
    void emitEnterTime(simtime_t enterTime);
private:
    //! Set to true to print debug messages
    bool debugFlag;
    //!@name Signals
    //@{
    simsignal_t enterTime_Signal; //! Emitted the instant a peer enters the swarm
    int counter;
    //@}
private:
    /*! Return the torrent metadata for the passed content. Must be called after
     * init stage 0.
     */ //TorrentMetadata getTorrentMetadata(const char* content);
    TorrentMetadata const& getTorrentMetaData(std::string contentName);
    std::map<std::string, TorrentMetadata> contents; //The key is the content name from XML file
    std::map<int, SwarmPeerList> swarms; // The key is the infoHash
    //! Print a debug message to clog.
    void printDebugMsg(std::string s);
    void updateStatusString();
    //!@name Signal registration and subscription methods
    //@{
    //! Subscribe to signals.
    void subscribeToSignals();
    //@}
protected:
    int numInitStages() const; //Note const in the numInitStages() declaration. If you forget it, by C++ rules you create a different function instead of redefining the existing one in the base class, thus the existing one will remain in effect and return 1.
    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);
};

#endif
