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

package btm.controller;


simple ClientController
{
    parameters:
        //Declaracion de la señal
        @signal[ClientController_EnterTimeSignal](type=simtime_t);
//        @statistic[EnterTime](
//            source=ClientController_EnterTimeSignal;
//            title="Enter Time";
//            record=vector;
//        );
        @display("i=block/user");
        bool debugFlag = default(false);
//        xml profile = xmldoc("/home/eandres/Workspace_Omnet++5/BitTorrent/simulations/BTProfiles.xml","profileList/profile[@name='test_simple']");
        int numSeeders; // The number of initial seeders in each swarm
        double startTime @unit(s) = default(3s); // the entry time of the first peer
//        string trackerAddress = default("tracker");  // tracker address
//        int trackerPort = default(8082); //The port number to connect to
}
