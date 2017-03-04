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

#include "Application_m.h"
#include "PeerWire_m.h"
#include "PeerWireMsgBundle_m.h"
#include "PeerWireThread.h"
#include "Choker.h"
#include "ContentManager.h"
#include "SwarmManager.h"

// Dumb fix because of the CDT parser (https://bugs.eclipse.org/bugs/show_bug.cgi?id=332278)
#ifdef __CDT_PARSER__
#undef BOOST_FOREACH
#define BOOST_FOREACH(a, b) for(a; b; )
#endif

// Helper functions
namespace {
std::string toStr(int i) {
    return boost::lexical_cast<std::string>(i);
}
}

Define_Module(BitTorrentClient);

using inet::TCPSrvHostApp;

Register_Class(BitTorrentClient);


void BitTorrentClient::initialize(int stage)
{
//    if (stage == 0) {
//        this->registerEmittedSignals();
//    } else if (stage == 3) {
//    // create a listening connection
//    TCPSrvHostApp::initialized();
//    //this->swarmManager = check_and_cast<SwarmManager*>(getParentModule()->getSubmodule("swarmManager"));
      this->localPeerId = this->getParentModule()->getParentModule()->getId();
//
//    // get parameters from the modules
//    this->snubbedInterval = par("snubbedInterval");
//    this->timeoutInterval = par("timeoutInterval");
//    this->keepAliveInterval = par("keepAliveInterval");
//    //        this->oldUnchokeInterval = par("oldUnchokeInterval");
//    this->downloadRateInterval = par("downloadRateInterval");
//    this->uploadRateInterval = par("uploadRateInterval");
//    this->globalNumberOfPeers = par("globalNumberOfPeers"); //FIXME use this!
//    this->numActiveConn = par("numberOfActivePeers");
//    this->numPassiveConn = par("numberOfPassivePeers");
//
//    //IPAddressResolver resolver;
//    //this->localIp = resolver.addressOf(getParentModule()->getParentModule(),IPAddressResolver::ADDR_PREFER_IPv4);
//    this->localPort = par("localPort");
//
//    this->subModulesDebugFlag = par("subModulesDebugFlag").boolValue();
//    this->debugFlag = par("debugFlag").boolValue();
//
//    char const* histogramFileName = par("processingTimeHistogram");
//    FILE * histogramFile = fopen(histogramFileName, "r");
//    if (histogramFile == NULL) {
//        throw std::invalid_argument("Histogram file not found");
//    } else {
//        this->doubleProcessingTimeHist.loadFromFile(histogramFile);
//        fclose(histogramFile);
//    }
//}

}

BitTorrentClient::BitTorrentClient()/*: endOfProcessingTimer("End of processing"), doubleProcessingTimeHist(
"Piece processing time histogram"), snubbedInterval(0), timeoutInterval(0), keepAliveInterval(0), downloadRateInterval(0), uploadRateInterval(0), localPort(-1), localPeerId(-1), debugFlag(false), globalNumberOfPeers(0), numActiveConn(0), numPassiveConn(0), prevNumUnconnected(0), prevNumConnected(0) */
{
}


BitTorrentClient::~BitTorrentClient() {
}
//
void BitTorrentClient::unchokePeer(int infoHash, int peerId) {
}
//
void BitTorrentClient::closeConnection(int infoHash, int peerId) const {
}
//
void BitTorrentClient::finishedDownload(int infoHash) {
}
//
void BitTorrentClient::peerInteresting(int infoHash, int peerId) const {
}
//
void BitTorrentClient::peerNotInteresting(int infoHash, int peerId) const {
}
//
void BitTorrentClient::sendHaveMessages(int infoHash, int pieceIndex) const {
}
//
void BitTorrentClient::sendPieceMessage(int infoHash, int peerId) const {
}
//
double BitTorrentClient::updateUploadRate(int infoHash, int peerId,
        unsigned long totalUploaded) {
}
//
int BitTorrentClient::getLocalPeerId() const {
}
//
void BitTorrentClient::createSwarm(int infoHash, int numOfPieces,
        int numOfSubPieces, int subPieceSize, bool newSwarmSeeding) {
}
//
void BitTorrentClient::deleteSwarm(int infoHash) {
}
//
bool BitTorrentClient::canConnect(int infoHash, int peerId, bool active) const {
}
//
void BitTorrentClient::processNextThread() {
    // allThreads will never be empty here
    assert(!this->allThreads.empty());

    std::list<PeerWireThread*>::iterator nextThreadIt =
        this->threadInProcessingIt;

    // don't start processing another thread if the current one is still processing
    if (!(*this->threadInProcessingIt)->busy
        && !this->endOfProcessingTimer.isScheduled()) {
        // increment the nextThreadIt until a thread with messages is found or
        // until a full circle is reached
        bool hasMessages = false;
#ifdef DEBUG_MSG
        std::ostringstream out;
        out << "== Next thread: ";
        out << (*nextThreadIt)->getThreadId();
#endif
        do {
            ++nextThreadIt;
            if (nextThreadIt == this->allThreads.end()) {
                nextThreadIt = this->allThreads.begin();
            }
#ifdef DEBUG_MSG
            out << " > " << (*nextThreadIt)->getThreadId();
#endif
            hasMessages = (*nextThreadIt)->hasMessagesToProcess();
        } while (nextThreadIt != this->threadInProcessingIt && !hasMessages);
#ifdef DEBUG_MSG
        out << " ==";
#endif

        if (hasMessages) {
#ifdef DEBUG_MSG
            this->printDebugMsg(out.str());
#endif
            this->threadInProcessingIt = nextThreadIt;
            simtime_t processingTime =
                (*this->threadInProcessingIt)->startProcessing();
            emit(this->processingTime_Signal, processingTime);
            this->scheduleAt(simTime() + processingTime,
                &this->endOfProcessingTimer);
#ifdef DEBUG_MSG
        } else {
            std::string out_str = "== Thread " + (*nextThreadIt)->getThreadId()
                + " idle ==";
            this->printDebugMsg(out_str);
#endif
        }
    }
}
//
void BitTorrentClient::removePeerFromSwarm(int infoHash, int peerId, int connId,
        bool active) {
}
//
void BitTorrentClient::setInterested(bool interested, int infoHash,
        int peerId) {
}
//
void BitTorrentClient::setOldUnchoked(bool oldUnchoke, int infoHash,
        int peerId) {
}
//
void BitTorrentClient::setSnubbed(bool snubbed, int infoHash, int peerId) {
}
//
void BitTorrentClient::attemptActiveConnections(Swarm& swarm, int infoHash) {
}
//
void BitTorrentClient::emitReceivedSignal(int messageId) {
}
//
void BitTorrentClient::emitSentSignal(int messageId) {
}
//
Swarm& BitTorrentClient::getSwarm(int infoHash) {
}
//
const Swarm& BitTorrentClient::getSwarm(int infoHash) const {
}
//
void BitTorrentClient::peerWireStatistics(const cMessage* msg, bool sending) {
}
//
void BitTorrentClient::printDebugMsg(std::string s) const {
}
//
void BitTorrentClient::printDebugMsgConnections(std::string methodName,
        int infoHash, const Swarm& swarm) const {
}
//
void BitTorrentClient::registerEmittedSignals() {
}
//
int BitTorrentClient::numInitStages() {
}
//
void BitTorrentClient::finish() {
}
//
void BitTorrentClient::handleMessage(cMessage *msg)
{
//    // TODO - Generated method body
}
PeerStatus & BitTorrentClient::getPeerStatus(int infoHash, int peerId) {
    Swarm & swarm = this->getSwarm(infoHash);
    assert(swarm.peerMap.count(peerId));
    return swarm.peerMap.at(peerId);
}
// Methods used by the Choker
void BitTorrentClient::chokePeer(int infoHash, int peerId) {
    Enter_Method("chokePeer(infoHash: %d, peerId: %d)", infoHash, peerId);

    PeerStatus & peer = this->getPeerStatus(infoHash, peerId);
    if (peer.isUnchoked()) {
        peer.setUnchoked(false, simTime());
        peer.getThread()->sendApplicationMessage(APP_CHOKE_PEER);
    }
}

PeerVector BitTorrentClient::getFastestToDownload(int infoHash) const {
    Enter_Method("getFastestToDownload(infoHash: %d)", infoHash);
    Swarm const& swarm = this->getSwarm(infoHash);
    PeerMap const& peerMap = swarm.peerMap;
    PeerVector orderedPeers;
    if (peerMap.size()) {
        orderedPeers.reserve(peerMap.size());
        PeerMapConstIt it = peerMap.begin();
        int i = 0;
        for (; it != peerMap.end(); ++it) {
            PeerStatus const* peerStatus = &it->second;
            orderedPeers.push_back(peerStatus);
        }

        // Order from lowest to largest, and we want the reverse order
        std::sort(orderedPeers.rbegin(), orderedPeers.rend(),
            PeerStatus::sortByDownloadRate);
    }

    return orderedPeers;
}
PeerVector BitTorrentClient::getFastestToUpload(int infoHash) const {
    Enter_Method("getFastestToUpload(infoHash: %d)", infoHash);
    Swarm const& swarm = this->getSwarm(infoHash);
    PeerMap const& peerMap = swarm.peerMap;
    int peerMapSize = peerMap.size();
    PeerVector orderedPeers;
    if (peerMapSize) {
        orderedPeers.reserve(peerMapSize);
        PeerMapConstIt it = peerMap.begin();
        for (; it != peerMap.end(); ++it) {
            PeerStatus const* peerStatus = &it->second;
            orderedPeers.push_back(peerStatus);
        }

        std::sort(orderedPeers.rbegin(), orderedPeers.rend(),
            PeerStatus::sortByUploadRate);
    }

    return orderedPeers;
}
