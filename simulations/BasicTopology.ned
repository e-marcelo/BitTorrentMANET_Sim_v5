
package btm.simulations;

import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.routing.contract.IPIMRouting;
import btm.nodes.PeerInterface;
import btm.nodes.Peer;
import inet.networklayer.configurator.ipv4.FlatNetworkConfigurator;


import inet.node.ethernet.EtherHost;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;


network BasicTopology extends BasicNetwork
{
    submodules:
        peer[numPeers]: <> like PeerInterface;
        router: Router;

        tracker: StandardHost {
            @display("p=67,156;i=device/server2");
        }

        configurator: IPv4NetworkConfigurator {
            @display("p=167,102");
        }
    connections:
        for i=0..numPeers-1 {
            peer[i].ethg <--> ethernetline <--> router.ethg++;
        }
        tracker.ethg++ <--> ethernetline <--> router.ethg++;
}
