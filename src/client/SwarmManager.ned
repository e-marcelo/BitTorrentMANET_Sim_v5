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

//
// TODO auto-generated module
//
import inet.applications.contract.ITCPApp;

simple SwarmManager like ITCPApp
{
     parameters:
        @signal[SwarmManager_EnterSwarm];
        @signal[SwarmManager_LeaveSwarm];
        @signal[SwarmManager_EmittedPeerId];
    	@display("i=misc/globe,red");
    
        // own parameters
        bool debugFlag = default(false);
        // The number of Peers the Client requests to the Tracker
        int numWant = default(50);
        double normalRefreshInterval @unit(s) = default(180s);
        double minimumRefreshInterval @unit(s) = default(20s);
        // probability the Peer will stay in the swarm after completion
        double remainingSeeders;
    gates:
        input userCommand @directIn;
        input tcpIn @labels(TCPCommand/up);
        output tcpOut @labels(TCPCommand/down);
}
