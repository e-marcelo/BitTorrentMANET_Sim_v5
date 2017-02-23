//
// Generated file, do not edit! Created by nedtool 5.0 from client/messages/PeerWireMsgBundle.msg.
//

#ifndef __PEERWIREMSGBUNDLE_M_H
#define __PEERWIREMSGBUNDLE_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
// EbitSim - Enhanced BitTorrent Simulation
// This program is under the terms of the Creative Commons
// Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
//
// You are free:
//
//    to Share - to copy, distribute and transmit the work
//    to Remix - to adapt the work
//
// Under the following conditions:
//
//    Attribution - You must attribute the work in the manner specified by the
//    author or licensor (but not in any way that suggests that they endorse you
//    or your use of the work).
//
//    Noncommercial - You may not use this work for commercial purposes.
//
//    Share Alike - If you alter, transform, or build upon this work, you may
//    distribute the resulting work only under the same or similar license to
//    this one.
//
// With the understanding that:
//
//    Waiver - Any of the above conditions can be waived if you get permission
//    from the copyright holder.
//
//    Public Domain - Where the work or any of its elements is in the public
//    domain under applicable law, that status is in no way affected by the
//    license.
//
//    Other Rights - In no way are any of the following rights affected by the
//    license:
//        - Your fair dealing or fair use rights, or other applicable copyright
//          exceptions and limitations;
//        - The author's moral rights;
//        - Rights other persons may have either in the work itself or in how
//          the work is used, such as publicity or privacy rights.
//
//    Notice - For any reuse or distribution, you must make clear to others the
//    license terms of this work. The best way to do this is with a link to this
//    web page. <http://creativecommons.org/licenses/by-nc-sa/3.0/>
//
// Author:
//     Pedro Manoel Fabiano Alves Evangelista <pevangelista@larc.usp.br>
//     Supervised by Prof Tereza Cristina M. B. Carvalho <carvalho@larc.usp.br>
//     Graduate Student at Escola Politecnica of University of Sao Paulo, Brazil
//
// Contributors:
//     Marcelo Carneiro do Amaral <mamaral@larc.usp.br>
//     Victor Souza <victor.souza@ericsson.com>
//
// Disclaimer:
//     This work is part of a Master Thesis developed by:
//        Pedro Evangelista, graduate student at
//        Laboratory of Computer Networks and Architecture
//        Escola Politecnica
//        University of Sao Paulo
//        Brazil
//     and supported by:
//        Innovation Center
//        Ericsson Telecomunicacoes S.A., Brazil.
//
// UNLESS OTHERWISE MUTUALLY AGREED TO BY THE PARTIES IN WRITING AND TO THE
// FULLEST EXTENT PERMITTED BY APPLICABLE LAW, LICENSOR OFFERS THE WORK AS-IS
// AND MAKES NO REPRESENTATIONS OR WARRANTIES OF ANY KIND CONCERNING THE WORK,
// EXPRESS, IMPLIED, STATUTORY OR OTHERWISE, INCLUDING, WITHOUT LIMITATION,
// WARRANTIES OF TITLE, MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
// NONINFRINGEMENT, OR THE ABSENCE OF LATENT OR OTHER DEFECTS, ACCURACY, OR THE
// PRESENCE OF ABSENCE OF ERRORS, WHETHER OR NOT DISCOVERABLE. SOME
// JURISDICTIONS DO NOT ALLOW THE EXCLUSION OF IMPLIED WARRANTIES, SO THIS
// EXCLUSION MAY NOT APPLY TO YOU.

//#include <cpacketqueue.h>
using omnetpp::cPacketQueue;
#include "PeerWire_m.h"

typedef cPacketQueue* cPacketQueuePtr;
// }}

/**
 * Class generated from <tt>client/messages/PeerWireMsgBundle.msg:85</tt> by nedtool.
 * <pre>
 * //
 * // Store several PeerWire messages. Used for request and have messages.
 * //
 * packet PeerWireMsgBundle
 * {
 *     // a queue containing PeerWire messages.
 *     cPacketQueuePtr bundle;
 * }
 * </pre>
 */
class PeerWireMsgBundle : public ::omnetpp::cPacket
{
  protected:
    cPacketQueuePtr bundle;

  private:
    void copy(const PeerWireMsgBundle& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PeerWireMsgBundle&);

  public:
    PeerWireMsgBundle(const char *name=nullptr, int kind=0);
    PeerWireMsgBundle(const PeerWireMsgBundle& other);
    virtual ~PeerWireMsgBundle();
    PeerWireMsgBundle& operator=(const PeerWireMsgBundle& other);
    virtual PeerWireMsgBundle *dup() const {return new PeerWireMsgBundle(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual cPacketQueuePtr& getBundle();
    virtual const cPacketQueuePtr& getBundle() const {return const_cast<PeerWireMsgBundle*>(this)->getBundle();}
    virtual void setBundle(const cPacketQueuePtr& bundle);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PeerWireMsgBundle& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PeerWireMsgBundle& obj) {obj.parsimUnpack(b);}


#endif // ifndef __PEERWIREMSGBUNDLE_M_H

