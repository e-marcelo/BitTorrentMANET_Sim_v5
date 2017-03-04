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

package btm.nodes;


import btm.client.BitTorrentApp;

import inet.common.packet.TCPDump;
import inet.linklayer.contract.IWiredNic;
import inet.linklayer.contract.IWirelessNic;
import inet.linklayer.ethernet.EthernetInterface;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.IPv4NetworkLayer;
import inet.networklayer.ipv4.IPv4RoutingTable;
import inet.transportlayer.tcp.TCP;
import inet.applications.contract.IPingApp;
import inet.common.packet.PcapRecorder;
import inet.networklayer.contract.IRoutingTable;
import inet.mobility.contract.IMobility;



//
// Peer module.
//
module Peer
{
    parameters:
        //@node();
        @networkNode();
        bool IPForward = default(false);
        int namid = default(-1);
        string routingFile = default("");
        string mobilityType = default(numRadios > 0 ? "StationaryMobility" : "");
        string networkLayerType = default("IPv4NetworkLayer");
        string routingTableType = default("Ipv4RoutingTable");
        *.interfaceTableModule = default(absPath(".interfaceTable"));
        *.routingTableModule = default(routingTableType != "" ? absPath(".routingTable") : "");
        *.displayAddresses = false;
        int numPingApps = default(0);


        @display("i=device/cellphone2");

    gates:
        input radioIn @directIn;

    submodules:
        interfaceTable: InterfaceTable {
            parameters:

                @display("p=60,150");
        }
        routingTable: IPv4RoutingTable {
            parameters:
                forwarding = true;
                routerId = "";
                routingFile = routingFile;
                @display("p=60,230");

        }
        bitTorrentApp: BitTorrentApp {
            parameters:
                @display("p=163,67;i=abstract/penguin");
        }
        tcp: TCP {
            parameters:
                @display("p=163,154");
        }
        networkLayer: IPv4NetworkLayer {
            parameters:
                proxyARP = false;
                @display("p=163,230;q=queue");
        }
        tcpDump: TCPDump {
            @display("p=60,315");
        }
        pcapRecorder: PcapRecorder {
            @display("p=65,90");
        }

        wlan0: <default("Ieee80211Nic")> like IWirelessNic {
            @display("p=161,337");
        }
        // optional mobility module. Required only if wireless cards are present
        mobility: <mobilityType> like IMobility if mobilityType != "" {
            parameters:
                @display("p=53,200");
        }
    connections allowunconnected:
        // Connect application to TCP layer
        bitTorrentApp.tcpOut[0] --> tcp.appIn++;
        bitTorrentApp.tcpOut[1] --> tcp.appIn++;
        bitTorrentApp.tcpIn[0] <-- tcp.appOut++;
        bitTorrentApp.tcpIn[1] <-- tcp.appOut++;

        tcp.ipOut --> networkLayer.igmpIn;
        tcp.ipIn <-- networkLayer.igmpOut;

        radioIn --> wlan0.radioIn;
        networkLayer.ifOut++ --> wlan0.upperLayerIn;
        networkLayer.ifIn++ <-- wlan0.upperLayerOut;

}
