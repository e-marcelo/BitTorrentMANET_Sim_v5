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

#ifndef CLIENT_CHOKER_H_
#define CLIENT_CHOKER_H_


#include <omnetpp.h>
#include <vector>
using omnetpp::cSimpleModule;
using omnetpp::simtime_t;
using omnetpp::cMessage;
class BitTorrentClient;
class PeerStatus;

/**
 * The Choker chokes and unchokes Peers connected to the Client.
 * The choking is performed in rounds, which occurs every
 * ten seconds, when a Peer leaves the peer set or when an
 * unchoked peer becomes changes interest.
 * The peer selection algorithm changes depending on the state
 * of the BitTorrentApp (that is, leecher and seeder states).
 *
 * The algorithm was acquired from (U. Guillaume and M. Pietro,
 * "Understanding BitTorrent: An Experimental Perspective",
 * Technical report, INRIA Sophia Antipolis / Institut Eurecom, November 2005.)
 *
 * In leecher state, the following algorithm is used to select peers
 * to unchoke:
 * <ol>
 *      <li> At the beginning of every three rounds, i.e., every 30 seconds,
 *           the algorithm chooses one peer at random that is choked and interested.
 *           This is called the optimistic unchoked peer.
 *      <li> The algorithm orders peers that are interested and not snubbed (a peer that
 *           has not send any block in the last 30 seconds is called snubbed) according
 *           to their download rate (to the Client).
 *      <li> The three fastest peers are unchoked.
 *      <li> If the planned optimistic unchoke is not part of the three fastest peers, it
 *           is unchoked and the round is completed.
 *      <li> If the planned optimistic unchoke is part of the three fastest peers, another
 *           planned optimistic unchoke is choken at random.
 *      <li>
 *          <ul>
 *              <li> If the peer is interested, it is unchoked and the round is completed.
 *              <li> If the peer is not interested, it is unchoked and a new planned
 *              optimistic unchoke is chosen at random. The previous step is repeated with
 *              the new planned optimistic unchoke. The consequence of this behavior is that
 *              there can be more than four unchoked peers, but only four can be unchoked
 *              AND interested. This way, the active peer set can be computed as soon as
 *              one of the unchoked and not interested peers becomes interested.
 *          </ul>
 * </ol>
 *
 * In seeder state, the following algorithm is used to select peers to unchoke:
 * <ol>
 *      <li> The algorithm selects all peers that were recently unchoked (less than 20 seconds ago)
 *      or that have pending requests for blocks and orders them according to the time
 *      they were last unchoked. If two peers were unchoked at the same time, they are ordered
 *      by their upload rate (to the Client), giving priority to the highest upload.
 *      <li> The algorithm orders the other peers according to their upload rate
 *      (to the Client), giving priority to the highest upload, and puts them after the peers
 *      ordered in the previous step.
 *      <li> During two out of three rounds, the algorithm keeps unchoked the first 3 peers,
 *      and unchoke another interested peer at random. For the third round, the algorithm
 *      keeps unchoked the first four peers.
 * </ol>
 *
 * When there are not enough connected peers to fill the upload slots, all of them
 * start unchoked. On the other hand, if there are more peers than there are upload
 * slots, they will start choked. In this way, the first peers to connect will
 * start downloading as soon as it becomes interested in the Client.
 */
class Choker: public cSimpleModule {
public:
    Choker();
    virtual ~Choker();
    void callChokeAlgorithm();
    void stopChokerRounds();
    /*!
     * If there are upload slots available, unchoke the passed Peer. First use
     * the regular slots, then the optimistic slots. When an optimistic slots is
     * used, start choke round timer. This method is called to fill up the
     * upload slots while there aren't enough connections to justify choking.
     *
     * @param peerId An interested but choked Peer.
     */
    void addInterestedPeer(int peerId);
    void removePeer(int peerId);
private:
    //!@name Pointers to other modules
    //@{
    BitTorrentClient *bitTorrentClient;
    //@}

    simtime_t roundInterval;
    unsigned int optimisticRoundRateInLeech;
    unsigned int optimisticRoundRateInSeed;
    unsigned int numRegular;
    unsigned int numOptimistic;
    unsigned int numberOfUploadSlots;
    long optimisticCounter;

    //! Set to true to print debug messages
    bool debugFlag;
    //! The infoHash of the swarm this ContentManager is serving.
    int infoHash;
    //! The peerId of this Client.
    int localPeerId;

    //!@name Upload slot vectors.
    //! A value of -1 represents an empty slot.
    //@{
    std::set<int> regularSlots;
    std::set<int> optimisticSlots;
    //@}

    cMessage roundTimer;
    //! Used to avoid multiple calls to the choke algorithm in the same event.
    cMessage chokeAlgorithmTimer;
private:
    void chokeAlgorithm(bool optimisticRound = false);
    typedef std::vector<PeerStatus const*>::iterator PeerVectorIt;
    /*!
     * Fill the regular slots with the fastest interested peers that are not
     * optimistically unchoked.
     *
     * Will increment the iterator until (it == end) or until the upload slots
     * are full.
     */
    void regularUnchoke(PeerVectorIt & it, PeerVectorIt const& end);
    /*!
     * Fill the optimistic upload slots with randomly selected interested peers.
     *
     * Will increment the iterator until (it == end) or until the optimistic
     * slots are full.
     */
    void optimisticUnchoke(PeerVectorIt & it, PeerVectorIt & end);
    void printUploadSlots();
    //! Print a debug message to clog.
    void printDebugMsg(std::string s);
    void updateStatusString();
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif /* CLIENT_CHOKER_H_ */
