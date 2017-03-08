cplusplus {{
	//Mensaje del controlador
	#include "ClientController.h"
}}

class noncobject TorrentMetadata;



enum UserCommandKind {
    USER_COMMAND_ENTER_SWARM = 0;
    USER_COMMAND_LEAVE_SWARM = 1;
}

class UserCommand {
}

class EnterSwarmCommand extends UserCommand {
    TorrentMetadata torrentMetadata;
    bool seeder;
    int idDisplay;
}

class LeaveSwarmCommand extends UserCommand  {
    int infoHash;
}