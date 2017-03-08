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

#include <PeerStatus.h>


// PeerStatus method implementations
//PeerStatus::PeerStatus(int peerId, PeerWireThread* thread) :
//        peerId(peerId), thread(thread), snubbed(false), interested(false),
//            unchoked(false), oldUnchoked(false), timeOfLastUnchoke(0) {
//}

std::string PeerStatus::str() const {
    std::ostringstream out;
    out << this->peerId << ", address: " << (void *) this << ", ";

    out << (this->snubbed ? "snubbed" : "not snubbed") << ", ";
    out << (this->interested ? "interested" : "not interested") << ", ";
    out << (this->unchoked ? "unchoked" : "choked") << ", ";
    out << (this->oldUnchoked ? "old unchoked" : "recently unchoked") << ", ";

    out << "last unchoke: " << this->timeOfLastUnchoke << "s, ";
    out << "download rate: " << this->downloadDataRate.getDataRateAverage()
        << "kpbs, upload rate: ";
    out << this->uploadDataRate.getDataRateAverage() << "bps";

    return out.str();
}
//PeerWireThread* PeerStatus::getThread() const {
//    return this->thread;
//}

int PeerStatus::getPeerId() const {
    return this->peerId;
}


// Attributes used when sorting.
void PeerStatus::setSnubbed(bool snubbed) {
    this->snubbed = snubbed;
}
bool PeerStatus::isSnubbed() const {
    return this->snubbed;
}
void PeerStatus::setInterested(bool interested) {
    this->interested = interested;
}
bool PeerStatus::isInterested() const {
    return this->interested;
}
void PeerStatus::setUnchoked(bool unchoked, simtime_t const& now) {
    if (unchoked) {
        this->timeOfLastUnchoke = now;
    }
    this->unchoked = unchoked;
}
bool PeerStatus::isUnchoked() const {
    return this->unchoked;
}
void PeerStatus::setOldUnchoked(bool oldUnchoked) {
    this->oldUnchoked = oldUnchoked;
}
void PeerStatus::setBytesDownloaded(double now, unsigned long bytesDownloaded) {
    this->downloadDataRate.collect(now, bytesDownloaded);
}
void PeerStatus::setBytesUploaded(double now, unsigned long bytesUploaded) {
    this->uploadDataRate.collect(now, bytesUploaded);
}
double PeerStatus::getDownloadRate() const {
    return this->downloadDataRate.getDataRateAverage();
}
double PeerStatus::getUploadRate() const {
    return this->uploadDataRate.getDataRateAverage();
}

//Sorting methods
/*!
 * Only interested and not snubbed (sent at least one piece in the last 30 seconds)
 * are considered. That means that if one of the PeerStatus'es is not interested or snubbed,
 * than it will come after the other.
 * lhs and rhs are compared based on the download rate from the Client's point of view.
 *
 * When true is returned, lhs comes before rhs, meaning lhs is worse than rhs.
 */
bool PeerStatus::sortByDownloadRate(PeerStatus const* lhs, PeerStatus const* rhs) {
    if (lhs->interested != rhs->interested) {
        // If lhs isn't interest but rhs is, then it is worse than rhs
        return !lhs->interested;
    }
    if (lhs->snubbed != rhs->snubbed) {
        // If lhs is snubbed but rhs isn't, then it is worse than rhs
        return lhs->snubbed;
    }
    // They have the same interest and snubbing status, so if lhs has lower download
    // rate, then it is worse than rhs
    int lhsDataRate = lhs->downloadDataRate.getDataRateAverage();
    int rhsDataRate = rhs->downloadDataRate.getDataRateAverage();
    return (lhsDataRate < rhsDataRate);
}
/*!
 * Only peers that are unchoked and interested are considered. That means that
 * if one of the PeerStatus objects is choked or not interested, than it will come
 * after the other.
 * The PeerStatus lhs and rhs are compared by the following criteria, in the order
 * presented. If lhs is equal to rhs in one of the criteria, then the following is
 * used, until lhs can be determined to be before or after rhs.
 * <ol>
 *      <li> Unchoked and interested comes first.
 *      <li> Recently unchoked (less than 20 second ago).
 *      <li> Most recently unchoked comes first.
 *      <li> Highest upload rate, from the Client's point of view, comes first.
 * </ol>
 *
 * The algorithm orders peers according to the time they were last unchoked (most recently
 * unchoked first) for all peers that were unchoked recently (less than 20 seconds ago) or that
 * have pending requests. The upload rate is used to decide between peers with the same last unchoked
 * time, giving priority to the highest upload. All other peers are ordered according to their
 * upload rate, giving priority to the highest upload.
 *
 * When true is returned, lhs comes before rhs, meaning lhs is worse than rhs.
 */
bool PeerStatus::sortByUploadRate(PeerStatus const* lhs, PeerStatus const* rhs) {
    if (lhs->interested != rhs->interested) {
        // If lhs isn't interested but rhs is, then it is worse than rhs
        return !lhs->interested;
    }
    if (lhs->unchoked != rhs->unchoked) {
        // If lhs isn't unchoked but rhs is, then it is worse than rhs
        return !lhs->unchoked;
    }

    if (lhs->oldUnchoked != rhs->oldUnchoked) {
        // If lhs is old unchoked but rhs isn't, then it is worse then rhs
        return lhs->oldUnchoked;
    }

    // TODO: verify pending requests

    // If both are not old unchoked, the oldest is worse
    if (!lhs->oldUnchoked) {
        return lhs->timeOfLastUnchoke > rhs->timeOfLastUnchoke;
    }

    // They have the same interest and choking status, and are both old unchokes,
    // so if lhs has lower upload data rate, it is worse than rhs
    int lhsDataRate = lhs->uploadDataRate.getDataRateAverage();
    int rhsDataRate = rhs->uploadDataRate.getDataRateAverage();
    return lhsDataRate < rhsDataRate;
}

/*!
 * Print information about this PeerStatus.
 */
std::ostream& operator<<(std::ostream& os, PeerStatus const& peer) {
    os << peer.str().c_str();
    return os;
}


