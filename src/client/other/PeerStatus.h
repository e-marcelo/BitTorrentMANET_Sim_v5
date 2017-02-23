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

#ifndef CLIENT_OTHER_PEERSTATUS_H_
#define CLIENT_OTHER_PEERSTATUS_H_

#include <omnetpp.h>
using namespace omnetpp;
#include <ostream>
#include <string>
#include "DataRateRollingAverage.h"
#include "PeerWireThread.h"
//[EAM]class PeerWireThread;

class PeerStatus {

public:
    PeerStatus(int peerId, PeerWireThread* thread);
    //! Return a string representation of this PeerStatus object.
    std::string str() const;
    PeerWireThread* getThread() const;
    //!@name PeerStatus main attributes.
    //@{
    //! Return the Id of the PeerStatus.
    int getPeerId() const;
    //! Return pointer to the thread opened when this Peer connected with the client.
    //@}

    //!@name Setters for the attributes used when sorting the PeerStatus'es in the ConnectedPeerManager.
    //@{
    //! Set to true if the Peer is snubbing the Client (did not answer any piece requests in the last minute).
    void setSnubbed(bool snubbed);
    //! Return true if the Peer is snubbing the Client (did not answer any piece requests in the last minute).
    bool isSnubbed() const;
    //! Set to true if the Peer showed interest in the Client.
    void setInterested(bool interested);
    //! Return true if the Peer is interested in the Client.
    bool isInterested() const;
    //! Set to true if the Peer was unchoked by the Client and the time the Peer was unchoked.
    void setUnchoked(bool unchoked, simtime_t const& now);
    //! Return true if the Peer was unchoked by the Client.
    bool isUnchoked() const;
    //! Set to true if the Peer was not recently unchoked.
    void setOldUnchoked(bool oldUnchoked);
    //! Set how many bytes arrived FROM the Peer since the last call.
    void setBytesDownloaded(double now, unsigned long bytesDownloaded);
    //! Set how many bytes were sent TO the Peer since the last call.
    void setBytesUploaded(double now, unsigned long bytesUploaded);
    //! Return the download rate that was collected last.
    double getDownloadRate() const;
    //! Return the upload rate that was collected last.
    double getUploadRate() const;
    //@}

    //!@name Static methods used to sort a list of PeerStatus'es
    //@{
    //! Return true if lhs comes before rhs.
    static bool sortByDownloadRate(PeerStatus const* lhs, PeerStatus const* rhs);
    //! Return true if lhs comes before rhs.
    static bool sortByUploadRate(PeerStatus const* lhs, PeerStatus const* rhs);
    //@}
private:
    /*!
     * The peerId of this peer. The specification says the peerId is a 20-byte string,
     * but to simplify the code development, the peerId of the module is used instead,
     * since it is guaranteed to be unique.
     */
    int peerId;
    //! Pointer to the thread created when the Peer connected with the client.
    PeerWireThread* thread;

    //! True if the Peer is snubbed.
    bool snubbed;
    //! True if the Peer is interested in the Client.
    bool interested;
    //! True if the Peer is unchoked by the Client.
    bool unchoked;
    //! False if the Peer was recently unchoked by the Client.
    bool oldUnchoked;
    //! The time the last unchoke occurred.
    simtime_t timeOfLastUnchoke;

    //! Used to calculate the upload data rate
    DataRateRollingAverage uploadDataRate;
    //! Used to calculate the download data rate
    DataRateRollingAverage downloadDataRate;
};

//! Output operator used by the WATCH_SET macro to print info about the PeerStatus.
std::ostream& operator<<(std::ostream& os, PeerStatus const& peer);

#endif /* CLIENT_OTHER_PEERSTATUS_H_ */
