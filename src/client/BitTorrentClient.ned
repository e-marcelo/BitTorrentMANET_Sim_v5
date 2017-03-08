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

import inet.applications.tcpapp.TCPSrvHostApp;


simple BitTorrentClient extends TCPSrvHostApp
{
    parameters:
        @signal[BitTorrentClient_NumUnconnected];
        @signal[BitTorrentClient_NumConnected];
        @signal[BitTorrentClient_ProcessingTime];
        @signal[BitTorrentClient_PeerWireBytesSent];
        @signal[BitTorrentClient_PeerWireBytesReceived];
        @signal[BitTorrentClient_ContentBytesSent];
        @signal[BitTorrentClient_ContentBytesReceived];
        @signal[BitTorrentClient_BitFieldSent];
        @signal[BitTorrentClient_BitFieldReceived];
        @signal[BitTorrentClient_CancelSent];
        @signal[BitTorrentClient_CancelReceived];
        @signal[BitTorrentClient_ChokeSent];
        @signal[BitTorrentClient_ChokeReceived];
        @signal[BitTorrentClient_HandshakeSent];
        @signal[BitTorrentClient_HandshakeReceived];
        @signal[BitTorrentClient_HaveSent];
        @signal[BitTorrentClient_HaveReceived];
        @signal[BitTorrentClient_InterestedSent];
        @signal[BitTorrentClient_InterestedReceived];
        @signal[BitTorrentClient_KeepAliveSent];
        @signal[BitTorrentClient_KeepAliveReceived];
        @signal[BitTorrentClient_NotInterestedSent];
        @signal[BitTorrentClient_NotInterestedReceived];
        @signal[BitTorrentClient_PieceSent];
        @signal[BitTorrentClient_PieceReceived];
        @signal[BitTorrentClient_RequestSent];
        @signal[BitTorrentClient_RequestReceived];
        @signal[BitTorrentClient_UnchokeSent];
        @signal[BitTorrentClient_UnchokeReceived];
        @class(BitTorrentClient);
        //@class(SwarmManager);
        @display("i=misc/globe,green");
        serverThreadClass = "n/a";
        localPort = default(6881); // port the client is listening
        bool debugFlag = default(false);
        bool subModulesDebugFlag = default(false);
        // file-saved histogram with the processing time
        string processingTimeHistogram;
        double downloadRateInterval @unit(s) = default(1s);
        double keepAliveInterval @unit(s) = default(60s);
        double oldUnchokeInterval @unit(s) = default(20s);
        double snubbedInterval @unit(s) = default(30s);
        double timeoutInterval @unit(s) = default(120s);
        double uploadRateInterval @unit(s) = default(1s);
        int globalNumberOfPeers = default(0);
        int numberOfActivePeers = default(4);
        int numberOfPassivePeers = default(6);
        int communicationRange = default(50);
}
 
