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
import inet.linklayer.ethernet.EthernetInterface;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.IPv4NetworkLayer;
import inet.networklayer.ipv4.IPv4RoutingTable;
import inet.transportlayer.tcp.TCP;
import inet.applications.contract.IPingApp;
import inet.common.packet.PcapRecorder;
import inet.networklayer.contract.IRoutingTable;


//
// Peer module.
//
module Peer like PeerInterface
{
    parameters:
        //@node();
        @networkNode();
        bool IPForward = default(false);
        int namid = default(-1);
        string routingFile = default("");
        string networkLayerType = default("IPv4NetworkLayer");
        string routingTableType = default("Ipv4RoutingTable");
        *.interfaceTableModule = default(absPath(".interfaceTable"));
        *.routingTableModule = default(routingTableType != "" ? absPath(".routingTable") : "");
        *.displayAddresses = false;
        int numPingApps = default(0);
        @display("i=device/pc2");

    gates:
        inout ethg;

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
        eth: EthernetInterface {
            parameters:
                @display("p=163,359,row,90;q=txQueue");
            gates:
        }
        tcp1: TCP {
            @display("p=103,37");
        }
        tcpDump: TCPDump {
            @display("p=30,320");
        }
        pcapRecorder: PcapRecorder {
            @display("p=30,82");
        }

    connections allowunconnected:
        // Connect application to TCP layer
        bitTorrentApp.tcpOut[0] --> tcp.appIn++;
        bitTorrentApp.tcpOut[1] --> tcp.appIn++;
        bitTorrentApp.tcpIn[0] <-- tcp.appOut++;
        bitTorrentApp.tcpIn[1] <-- tcp.appOut++;

        tcp.ipOut --> networkLayer.igmpIn;
        tcp.ipIn <-- networkLayer.igmpOut;

        networkLayer.ifOut++ --> eth.upperLayerIn;
        networkLayer.ifIn++ <-- eth.upperLayerOut;

        eth.phys <--> ethg;
}
