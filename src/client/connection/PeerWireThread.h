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

#ifndef CLIENT_CONNECTION_PEERWIRETHREAD_H_
#define CLIENT_CONNECTION_PEERWIRETHREAD_H_

#include <omnetpp.h>
using omnetpp::cPacketQueue;
using omnetpp::cMessage;
using omnetpp::cPacket;
using omnetpp::cSimulation;
#define simulation  (*cSimulation::getActiveSimulation())

#include <TCPSrvHostApp.h>
#include <TCPSrvHostApp.h>
#include <TCPSocket.h>
using namespace inet;
using inet::TCPServerThreadBase;
using inet::TCPSocket;
using inet::TCPSrvHostApp;
using inet::L3Address;



//[EAM]#include <cPacketQueue.h>
//[EAM]#include <cpacketqueue.h>
//#include "client/smc/out/ConnectionSM_sm.h"
//#include "client/smc/out/DownloadSM_sm.h"
//#include "client/smc/out/UploadSM_sm.h"

#include "PeerWireMsgBundle_m.h"
#include "PeerWire_m.h"


class BitTorrentClient;
class Choker;
class ContentManager;

class PeerWireThread: public TCPServerThreadBase {
public:
    // own methods
    friend class BitTorrentClient;
    PeerWireThread(int infoHash, int remotePeerId);
    virtual ~PeerWireThread();
public:
    // parents' methods
    //!@name Implementation of the virtual methods from TCPServerThreadBase
    //@{
    //! Send an application message warning about the TCP connection closing.
    void closed();
    //! Insert the message in the queue for later processing.
    void dataArrived(cMessage *msg, bool urgent);
    //! Initiate the Handshake procedure in the Connection State Machine.
    void established();
    //! Shouldn't happen, so throw an error.
    void failure(int code);
    //! Call parent ctor and cast hostmodule to BitTorrentApp* as a shortcut.
    void init(TCPSrvHostApp *hostmodule, TCPSocket *socket);
    //! Send an application message about the Peer closing the TCP connection.
    void peerClosed();
    /*!
     * Send an application message corresponding to the expired timer.
     *
     * Timer messages are not deleted because they are constantly being
     * re-scheduled.
     * @param timer
     */
    void timerExpired(cMessage *timer);
    //@}
public:
    //!@name ConnectionSM's external transition callers
    //@{
    //! External call the ConnectionSM's outgoingPeerWireMsg transition.
    void outgoingPeerWireMsg_ConnectionSM(PeerWireMsg * msg);
    //! External call the ConnectionSM's outgoingPeerWireMsg transition.
    void outgoingPeerWireMsg_ConnectionSM(PeerWireMsgBundle * msg);
    //@}

    //!@name Connection State Machine methods.
    //@{
    void connected();
    //! Close the TCP connection from the client's side.
    void closeLocalConnection();
    //! Start the Download and Upload machines
    void startMachines();
    //! Stop the Download and Upload machines
    void stopMachines();
    //! Send a BitField message to the Peer.
    BitFieldMsg * getBitFieldMsg();
    //! Send a Handshake to the Peer.
    Handshake * getHandshake();
    //! Send a Keep-Alive message to the Peer.
    KeepAliveMsg * getKeepAliveMsg();
    //! Restart the keep-alive timer.
    void renewKeepAliveTimer();
    //! Restart the timeout timer.
    void renewTimeoutTimer();
    //! Send a PeerWireMsg to the connected Peer.
    void sendPeerWireMsg(cPacket * msg);
    //! Start the timeout and the keep-alive timers.
    void startHandshakeTimers();
    //! Stop the timeout and keep-alive timers.
    void stopHandshakeTimers();
    //! Terminate the thread, removing all information about the peer from the swarm
    void removeFromSwarm();
    //@}

    //!@name Connection State Machine transition guards.
    //@{
    //! Verify if the Peer sent a Handshake with the expected Id and info hash.
    bool checkHandshake(Handshake const& hs);
    //! Return true if this Client's BitField is empty
    bool isBitFieldEmpty();
    //@}

    //!@name Download State Machine methods.
    //@{
    //! Add the BitField from the message to the Peer. Throw an error if the
    //! BitField is not empty.
    void addBitField(const BitFieldMsg & msg);
    //! Calculate the download rate.
    void calculateDownloadRate();
    //! Cancel the requests made.
    void cancelDownloadRequests();
    //! Return a new InterestedMsg.
    InterestedMsg * getInterestedMsg();
    //! Return a new NotInterestedMsg.
    NotInterestedMsg * getNotInterestedMsg();
    //! Return a new RequestMsgBundle or NULL, if there are no requests to be made.
    PeerWireMsgBundle * getRequestMsgBundle();
    //! Save the downloaded block and verify the interest in all peers if the piece is completed.
    void processBlock(PieceMsg const& msg);
    //! Update the Peer BitField and verify if it became interesting.
    void processHaveMsg(HaveMsg const& msg);
    //! Restart the download rate timer.
    void renewDownloadRateTimer();
    //! Restart the snubbed timer.
    void renewSnubbedTimer();
    //! Set to true if the Client is snubbed by the Peer.
    void setSnubbed(bool snubbed);
    //! Start the snubbed and the download rate timers.
    void startDownloadTimers();
    //! Stop the snubbed and the download rate timers.
    void stopDownloadTimers();
    //@}

    //!@name Upload State Machine methods
    //@{
    //! Cancel the request made by the Peer.
    void cancelPiece(CancelMsg const& msg);
    //! Cancel all the requestes made by this Peer.
    void cancelUploadRequests();
    //! Calculate the upload rate.
    void calculateUploadRate();
    //! Tell the Choker execute the next choke round now.
    void callChokeAlgorithm();
    //! While there are available slots, choked peers that become interested
    //! will be unchoked.
    void addPeerToChoker();
    //! Return a new ChokeMsg.
    ChokeMsg * getChokeMsg();
    //! Make a piece request to the ContentManager.
    void requestPieceMsg(RequestMsg const& msg);
    //! Get the previously requested piece from the ContentManager.
    PieceMsg * getPieceMsg();
    //! Return a new UnchokeMsg.
    UnchokeMsg * getUnchokeMsg();
    //! Restart the upload rate timer.
    void renewUploadRateTimer();
    //! Set to true if the Peer is interested in the Client.
    void setInterested(bool interested);
    //! Start the old unchoke and the upload rate timers.
    void startUploadTimers();
    //! Stop the old unchoke and the upload rate timers.
    void stopUploadTimers();
    //@}
    //! Print a debug message with information about the thread.
    std::string getThreadId();
    void printDebugMsg(std::string s);
private:
    //!@name BitTorrent State Machines
    //@{
//    ConnectionSMContext connectionSm;
//    DownloadSMContext downloadSm;
//    UploadSMContext uploadSm;
    //@}

    //! Pointer to the host, cast to the BitTorrentClient class.
    BitTorrentClient *btClient;

    //!@name Swarm-related modules
    //@{
    Choker *choker; //! The Swarm's Choker module
    ContentManager *contentManager; //! The Swarm's Content Manager module
    //@}


    // attributes
    //! True if this thread was created because of an active connection.
    bool activeConnection;
    /*!
     * The peerId of the Peer, which can be set in two moments: at the
     * connection, if the Tracker specified it, or at the arrival of the Handshake.
     */
    int infoHash;
    int remotePeerId;
    /*!
     * True when this thread is terminated.
     * Will result in the deletion of the thread when the finishProcessing()
     * method is called.
     */
    bool terminating;

    //!@name Message processing
    //@{
    eventnumber_t lastEvent;
    bool busy;
    /*!
     * Queue with all the messages to be processed. ApplicationMsgs are
     * processed instantly, while the PeerWireMsg are processed with a timeout
     * timer. The processing timer also serves as the time slice for this thread.
     */
    cQueue messageQueue;
    /*!
     * Queue for messages produced during the processing of the current message.
     */
    cQueue postProcessingAppMsg;
    //@}

    //!@name Self-messages
    //@{
    //! Self-message used to calculate the download rate.
    cMessage downloadRateTimer;
    //! Self-message used to create keep-alives.
    cMessage keepAliveTimer;
    //! Self-message used to verify if the connection is snubbed.
    cMessage snubbedTimer;
    //! Self-message used to timeout the connection.
    cMessage timeoutTimer;
    //! Self-message used to calculate the upload rate.
    cMessage uploadRateTimer;
    //@}
private:
    //!@name Message processing
    //@{
    //! Cancel all the messages in the queue.
    void cancelMessages();
    //! True if there are messages to process in this thread.
    bool hasMessagesToProcess();
    /*!
     * Start processing the messages in the message queue. Will process all
     * application messages until it finds a PeerWire message.
     *
     * Return the time it will take to process these messages. If no PeerWire
     * was found in the queue, this time is zero.
     */
    simtime_t startProcessing();
    //! Execute the transitions issued during the processing, or delete the thread
    void finishProcessing();
    /*!
     * Process all ApplicationMsgs in the queue until a PeerWireMsg is found or
     * until the queue is empty.
     */
    void processAppMessages();
    //! Insert a message from the Application in the processing queue.
    void sendApplicationMessage(int kind);
    //! Insert a message from the connection in the processing queue.
    void sendPeerWireMessage(cMessage * msg);
    //@}

    //! Issue a transition to one of the state machines.
    void issueTransition(cMessage const* msg);
    //! The Client was not recently unchoked.
    //    void oldUnchoked();
};


#endif /* CLIENT_CONNECTION_PEERWIRETHREAD_H_ */
