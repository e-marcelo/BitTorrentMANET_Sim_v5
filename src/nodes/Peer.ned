
package btm.nodes;


import btm.client.BitTorrentApp;
import inet.applications.contract.IPingApp;
import inet.common.packet.TCPDump;
import inet.linklayer.contract.IWiredNic;
import inet.transportlayer.contract.ITCP;
import inet.linklayer.contract.IWirelessNic;
import inet.linklayer.ethernet.EthernetInterface;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.IPv4NetworkLayer;
import inet.applications.contract.ITCPApp;
import inet.networklayer.ipv4.IPv4RoutingTable;
import inet.transportlayer.tcp.TCP;
import inet.applications.contract.IPingApp;
import inet.common.packet.PcapRecorder;
import inet.networklayer.contract.IRoutingTable;
import inet.mobility.contract.IMobility;
import inet.node.inet.NodeBase;

import inet.common.lifecycle.NodeStatus;
import inet.common.packet.PcapRecorder;
import inet.linklayer.contract.IExternalNic;
import inet.linklayer.contract.ITunNic;
import inet.linklayer.contract.IWiredNic;
import inet.linklayer.contract.IWirelessNic;
import inet.linklayer.loopback.LoopbackInterface;
import inet.mobility.contract.IMobility;
import inet.networklayer.contract.IRoutingTable;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.contract.INetworkLayer;
import inet.power.contract.IEnergyStorage;
import inet.power.contract.IEnergyGenerator;

import inet.applications.contract.IPingApp;
import inet.applications.contract.ISCTPApp;
import inet.applications.contract.ITCPApp;

import inet.transportlayer.contract.ISCTP;
import inet.transportlayer.contract.ITCP;

import inet.applications.contract.ITunApp;



//
// Peer module.
//
module Peer
{
    parameters:
        @display("bgb=,448");
        @networkNode;
        @labels(node,ethernet-node,wireless-node);
        @display("i=device/cellphone");


        bool hasStatus = default(false);
        int numExtInterfaces = default(0);
        int numRadios = default(1);               // the number of radios in the router. by default no wireless
        int numPcapRecorders = default(0); // no of PcapRecorders.
        int numTunInterfaces = default(0);
        string osgModel = default(""); // 3D model for OSG visualization, no 3D model by default
        string osgModelColor = default(""); // tint color, no colorization by default
        string mobilityType = default(numRadios > 0 ? "StationaryMobility" : "");
        string networkLayerType = default("IPv4NetworkLayer");
        string routingTableType = default("IPv4RoutingTable");
        bool forwarding = default(true);
        bool multicastForwarding = default(false);
        string energyStorageType = default("");
        string energyGeneratorType = default("");
        routingTable.forwarding = forwarding;
        routingTable.multicastForwarding = multicastForwarding;   // for IPv4, IPv6, Generic
        *.interfaceTableModule = default(absPath(".interfaceTable"));
        *.routingTableModule = default(routingTableType != "" ? absPath(".routingTable") : "");
        *.energySourceModule = default(energyStorageType != "" ? absPath(".energyStorage") : "");
        *.mobilityModule = default(mobilityType != "" ? absPath(".mobility") : "");


        int numTcpApps = default(0);  // no of TCP apps. Specify the app types in INI file with tcpApp[0..1].typename="TCPEchoApp" syntax
        
        int numSctpApps = default(0); // no of SCTP apps. Specify the app types in INI file with sctpApp[0..1].typename="SCTPServer" syntax
        int numPingApps = default(0);  // no of PING apps. Specify the app types in INI file with pingApp[0..1].typename="PingApp" syntax
        bool hasTcp = default(numTcpApps > 0);
        
        bool hasSctp = default(numSctpApps > 0);
        bool hasTun = default(numTunInterfaces > 0);
        string tcpType = default(firstAvailableOrEmpty("TCP", "TCP_lwIP", "TCP_NSC"));  // tcp implementation (e.g. ~TCP, ~TCP_lwIP, ~TCP_NSC) or ~TCPSpoof
        
        string sctpType = default(firstAvailableOrEmpty("SCTP"));
        

		networkLayer.proxyARP = default(false);
		wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");  // use adhoc management
		



    gates:
        input radioIn[numRadios] @directIn;

    submodules:
        status: NodeStatus if hasStatus {
            @display("p=50,50");
        }
        energyStorage: <energyStorageType> like IEnergyStorage if energyStorageType != "" {
            parameters:
                @display("p=50,100;i=block/plug;is=s");
        }
        energyGenerator: <energyGeneratorType> like IEnergyGenerator if energyGeneratorType != "" {
            parameters:
                @display("p=50,150;i=block/plug;is=s");
        }
        // optional mobility module. Required only if wireless cards are present
        mobility: <mobilityType> like IMobility if mobilityType != "" {
            parameters:
                @display("p=53,200");
        }
        // network layer
        networkLayer: <networkLayerType> like INetworkLayer {
            parameters:
                @display("p=329,287;q=queue");
            gates:
                ifIn[1];
                ifOut[1];
        }
        // routing table
        routingTable: <routingTableType> like IRoutingTable if routingTableType != "" {
            parameters:
                @display("p=53,250;is=s");
        }
        // linklayer
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=53,300;is=s");
        }
        pcapRecorder[numPcapRecorders]: PcapRecorder {
            @display("p=53,350,r,10");
        }
        wlan[numRadios]: <default("Ieee80211Nic")> like IWirelessNic {
            parameters:
                @display("p=216,406,row,60;q=queue");
        }
        tcpApp[numTcpApps]: <> like ITCPApp {
            parameters:
                @display("p=147,54,row,60");
        }
        tcp: TCP {
            parameters:
                @display("p=147,141");
        }
        
        bitTorrentApp: BitTorrentApp {
            @display("p=211,24");
        }
        pingApp[numPingApps]: <default("PingApp")> like IPingApp {
            parameters:
                @display("p=635,141,row,60");
        }
    connections allowunconnected:
        for i=0..sizeof(radioIn)-1 {
            radioIn[i] --> { @display("m=s"); } --> wlan[i].radioIn;
            wlan[i].upperLayerOut --> networkLayer.ifIn++;
            wlan[i].upperLayerIn <-- networkLayer.ifOut++;
        }

        for i=0..numTcpApps-1 {
            tcpApp[i].tcpOut --> tcp.appIn++;
            tcpApp[i].tcpIn <-- tcp.appOut++;
        }

        tcp.ipOut --> networkLayer.transportIn++;
        tcp.ipIn <-- networkLayer.transportOut++;

        
        for i=0..numPingApps-1 {
            networkLayer.pingOut++ --> pingApp[i].pingIn;
            networkLayer.pingIn++ <-- pingApp[i].pingOut;
        }

        
//        
        bitTorrentApp.tcpOut[0] --> tcp.appIn++;
        bitTorrentApp.tcpIn[0] <-- tcp.appOut++;
        bitTorrentApp.tcpIn[1] <-- tcp.appOut++;
        bitTorrentApp.tcpOut[1] --> tcp.appIn++;
        
        

}
