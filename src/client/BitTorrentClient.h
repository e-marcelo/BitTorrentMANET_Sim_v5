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

#ifndef __BTM_BITTORRENTCLIENT_H_
#define __BTM_BITTORRENTCLIENT_H_

#include <omnetpp.h>

using namespace omnetpp;




#include <omnetpp.h>
#include <TCPSrvHostApp.h>
#include <L3AddressResolver.h>
using inet::TCPSrvHostApp;
#include <boost/tuple/tuple_comparison.hpp>
#include "BitField.h"
//Separador de cadenas (para ubicar a cada nodo de acuerdo a su identificador en el escenario de simulación)
#include <boost/tokenizer.hpp>
using boost::tuple;
using boost::make_tuple;
using boost::tie;
//#include "PeerStatus.h"
using inet::L3Address;
using inet::L3AddressResolver;
//class PeerStatus;
//class PeerInfo;
//class PeerWireThread;
class SwarmManager;
class BitFieldMsg;
//class Choker;
//class ContentManager;




//! Vector of PeerStatus pointers.
//typedef std::vector<PeerStatus const*> PeerVector;
//! Tuple with connect information about a Peer. <PeerId, IpAddress, Port>
typedef tuple<int, L3Address, int> PeerConnInfo;
//! List of unconnected Peers
typedef std::list<PeerConnInfo> UnconnectedList;
//! Map of peer entries with peerId as key
//typedef std::map<int, PeerStatus> PeerMap;
//! Swarm (numActive, numPassive, PeerMap, UnconnectedList, seeding)
struct Swarm {
    int numActive;
    int numPassive;
//    PeerMap peerMap;
//    UnconnectedList unconnectedList;
    bool seeding;
    bool closing;
//    Choker * choker;
//    ContentManager* contentManager;
};
//! map of swarms with infoHash as key
typedef std::map<int, Swarm> SwarmMap;

// Iterators
//typedef PeerVector::iterator PeerVectorIt;
typedef UnconnectedList::iterator UnconnectedListIt;
//typedef PeerMap::iterator PeerMapIt;
//typedef PeerMap::const_iterator PeerMapConstIt;
typedef SwarmMap::iterator SwarmMapIt;
typedef SwarmMap::const_iterator SwarmMapConstIt;


/**
 * TODO - Generated class
 */
class BitTorrentClient : public TCPSrvHostApp
{
  public:
    BitTorrentClient();
    //! Delete the sockets and threads
    virtual ~BitTorrentClient();
//    void unchokePeer(int infoHash, int peerId);
    void closeConnection(int infoHash, int peerId) const;
    void finishedDownload(int infoHash);
//    void peerInteresting(int infoHash, int peerId) const;
//    void peerNotInteresting(int infoHash, int peerId) const;
    void sendHaveMessages(int infoHash, int pieceIndex) const;
    void sendPieceMessage(int infoHash, int peerId) const;
//    double updateUploadRate(int infoHash, int peerId,unsigned long totalUploaded);
    int getLocalPeerId() const;
    void createSwarm(int infoHash, int numOfPieces, int numOfSubPieces,int subPieceSize, bool newSwarmSeeding, int idDisplay);
    void deleteSwarm(int infoHash);
//    PeerVector getFastestToUpload(int infoHash) const;
//    PeerVector getFastestToDownload(int infoHash) const;
//    void chokePeer(int infoHash, int peerId);
    cDoubleHistogram doubleProcessingTimeHist;
//    std::list<PeerWireThread*>::iterator threadInProcessingIt;
//    void processNextThread();

  private:
    //Variable para el manejo de la pieza
    BitField clientBitField;

    std::string strCurrentNode;
    std::string strArgNode;
    std::ostringstream optNumtoStr;
    int count;
    int peerX;
    int peerY;

    void currentPosition(const char * peer, int *x, int *y);
    void findLocalNeighborhood();
//    cPacket* createHelloMessage();
    void sendBroadcast(int idNode/*cPacket *packet, const L3Address& destAddr, unsigned int timeToLive, double delay*/);

    // self messages
//    cMessage *helloMsgTimer = nullptr;    // timer to send hello messages (only if the feature is enabled)
//    std::list<PeerWireThread*> allThreads;
//    PeerStatus & getPeerStatus(int infoHash, int peerId);
//    bool canConnect(int infoHash, int peerId, bool active) const;
//    void removePeerFromSwarm(int infoHash, int peerId, int connId, bool active);
//    void setInterested(bool interested, int infoHash, int peerId);
//    void setOldUnchoked(bool oldUnchoke, int infoHash, int peerId);
//    void setSnubbed(bool snubbed, int infoHash, int peerId);
//    cMessage endOfProcessingTimer;
        //! Processing time histogram, used to generate values for the simulation
        //@}

        //! Contains the list of swarms mapped by their infoHash
//    SwarmMap swarmMap;
        /*!
         * Set with all active connections established or attempted by this Peer.
         * Peers are only removed from this list when the TCP connection closes.
//         *
//         * If there are connection slots available, the Client will actively connect
//         * with other Peers in two situations:
//         * 1) when an announce response arrives, or
//         * 2) an active connection is closed.
//         *
//         * Structure: [(infoHash, peerId),]
//         */
    SwarmManager *swarmManager;
//    std::set<std::pair<int, int> > activeConnectedPeers;
//        //!@name Timer intervals
//        //@{
//        //! The time, in seconds, to occur an snubbed timeout.
//    simtime_t snubbedInterval;
        //! The time, in seconds, to occur a message timeout.
//    simtime_t timeoutInterval;
//        //! The time, in seconds, to occur a keep-alive timeout.
//    simtime_t keepAliveInterval;
//        //! The time, in seconds, to occur a download rate timeout.
//    simtime_t downloadRateInterval;
//        //! The time, in seconds, to occur a upload rate timeout.
//    simtime_t uploadRateInterval;
//        //@}
//        //! The IP address of this Client.
    L3Address localIp;
//        //! The port of this Client.
    int localPort;
    int communicationRange;
//        //! The peerId of this Client.
//

//    TCPSocket * socket;
//
    int localPeerId;
    int localIdDisplay = -1;
//        //! Set to true to print debug messages.
//    bool debugFlag;
//        //! Set to true to print debug messages for the swarm modules.
//    bool subModulesDebugFlag;
//        //! TODO document this
    int globalNumberOfPeers;
//        //! TODO document this
//    int numActiveConn;
//        //! TODO document this
//    int numPassiveConn;
//        //!@name Signals and helper variables
//        //@{
//    unsigned int prevNumUnconnected;
//    unsigned int prevNumConnected;
//    simsignal_t numUnconnected_Signal;
//    simsignal_t numConnected_Signal;
////
//    simsignal_t processingTime_Signal;
////
//    simsignal_t peerWireBytesSent_Signal;
//    simsignal_t peerWireBytesReceived_Signal;
//    simsignal_t contentBytesSent_Signal;
//    simsignal_t contentBytesReceived_Signal;
////
//    simsignal_t bitFieldSent_Signal;
//    simsignal_t bitFieldReceived_Signal;
//    simsignal_t cancelSent_Signal;
//    simsignal_t cancelReceived_Signal;
//    simsignal_t chokeSent_Signal;
//    simsignal_t chokeReceived_Signal;
//    simsignal_t handshakeSent_Signal;
//    simsignal_t handshakeReceived_Signal;
//    simsignal_t haveSent_Signal;
//    simsignal_t haveReceived_Signal;
//    simsignal_t interestedSent_Signal;
//    simsignal_t interestedReceived_Signal;
//    simsignal_t keepAliveSent_Signal;
//    simsignal_t keepAliveReceived_Signal;
//    simsignal_t notInterestedSent_Signal;
//    simsignal_t notInterestedReceived_Signal;
//    simsignal_t pieceSent_Signal;
//    simsignal_t pieceReceived_Signal;
//    simsignal_t requestSent_Signal;
//    simsignal_t requestReceived_Signal;
//    simsignal_t unchokeSent_Signal;
//    simsignal_t unchokeReceived_Signal;
//    void attemptActiveConnections(Swarm & swarm, int infoHash);
//    void emitReceivedSignal(int messageId);
//    void emitSentSignal(int messageId);
//    Swarm & getSwarm(int infoHash);
//    const Swarm & getSwarm(int infoHash) const;
//    void peerWireStatistics(const cMessage *msg, bool sending);
//    void printDebugMsg(std::string s) const;
//    void printDebugMsgConnections(std ::string methodName, int infoHash, const Swarm & swarm) const;
//    void registerEmittedSignals();


  protected:
    virtual int numInitStages();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
    virtual void initialize(int stage);


};

#endif
