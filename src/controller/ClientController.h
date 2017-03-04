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

#ifndef __BITTORRENTMANET_SIM_V5_CLIENTCONTROLLER_H_
#define __BITTORRENTMANET_SIM_V5_CLIENTCONTROLLER_H_

#include <omnetpp.h>

using omnetpp::cListener;


#include <list>

#include "TrackerApp.h"

class SwarmManager;

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
    int endPeerDownload;
    int numNodesTotal;

    //!@name Signals
    //@{
    simsignal_t enterTime_Signal; //! Emitted the instant a peer enters the swarm
    //@}
private:
    void endUserDownload(cMessage * msg);
    /*! Return the torrent metadata for the passed content. Must be called after
     * init stage 0.
     */
    TorrentMetadata getTorrentMetadata(const char* content);

    //! Print a debug message to clog.
    void printDebugMsg(std::string s);
    void updateStatusString();
    //!@name Signal registration and subscription methods
    //@{
    //! Subscribe to signals.
    void subscribeToSignals();
    //@}
protected:
    int numInitStages() const;
    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);
};

#endif
