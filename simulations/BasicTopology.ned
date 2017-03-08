
package btm.simulations;
package btm.controller;
import btm.controller.ClientController;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.routing.contract.IPIMRouting;

import btm.nodes.Peer;
import inet.networklayer.configurator.ipv4.FlatNetworkConfigurator;


import inet.node.ethernet.EtherHost;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;
import inet.common.figures.DelegateSignalConfigurator;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.node.inet.AdhocHost;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;
import inet.visualizer.integrated.IntegratedCanvasVisualizer;

network BasicTopology extends BasicNetwork
{
    parameters:
        string hostType = default("WirelessHost");
        string mediumType = default("IdealRadioMedium");
        @display("bgb=1000,1000;bgg=100,1,grey95");
        @figure[title](type=label; pos=0,-1; anchor=sw; color=darkblue);

    //        @figure[rcvdPkText](type=indicatorText; pos=420,20; anchor=w; font=,20; textFormat="packets received: %g"; initialValue=0);
    //        @statistic[rcvdPk](source=hostB_rcvdPk; record=figure(count); targetFigure=rcvdPkText);
    //        @signal[hostB_rcvdPk];
    //        @delegatesignal[rcvdPk](source=hostB.udpApp[0].rcvdPk; target=hostB_rcvdPk);
    //    
    submodules:
        peer[numPeers]: Peer;
        configurator: IPv4NetworkConfigurator {
            @display("p=0,0");
        }
        visualizer: IntegratedCanvasVisualizer {
            parameters:
                @display("p=-7,9");
        }
        
        figureHelper: DelegateSignalConfigurator {
            @display("p=1,9");
        }
   
        radioMedium: Ieee80211ScalarRadioMedium {
            parameters:
                @display("p=0,9");
        }

        clientController: ClientController {
            @display("p=39,40");
        }
    connections:
}
