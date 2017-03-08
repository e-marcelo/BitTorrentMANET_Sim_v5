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

package btm.client;


module BitTorrentApp
{
    parameters:
        @peer(); // used by the Tracker to find all Peers in the simulation
        @display("i=abstract/penguin");
        string clientControllerModule = default("");
    gates:
       input tcpIn[2];
       output tcpOut[2];
       
        

    submodules:
		swarmManager: SwarmManager {
            @display("p=68,58");
        }
        bitTorrentClient: BitTorrentClient {
            @display("p=68,128");
        } 

    connections:
        // TCP connections
        //        bitTorrentClient.tcpOut --> uploadLimiter.in;
        //        uploadLimiter.out --> tcpOut[0];
        bitTorrentClient.tcpOut --> tcpOut[0];
        bitTorrentClient.tcpIn <-- tcpIn[0];
        swarmManager.tcpOut --> tcpOut[1];
        swarmManager.tcpIn <-- tcpIn[1];
}
