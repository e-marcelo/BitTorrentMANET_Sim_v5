#
# OMNeT++/OMNEST Makefile for BitTorrentMANET_Sim_v5
#
# This file was generated with the command:
#  opp_makemake -f --deep -I/root/smc_6_6_0/lib/C++ -I/root/boost_1_61_0 -I../../inet/src -I../../inet/src/inet/transportlayer/contract/tcp -I../../inet/src/inet/networklayer/common -I../../inet/src/inet/applications/tcpapp -L../../inet/out/$$\(CONFIGNAME\)/src -L../../inet/out/$$\(CONFIGNAME\) -lINET -linet -KINET_PROJ=../../inet
#

# Name of target to be created (-o option)
TARGET = BitTorrentMANET_Sim_v5$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(QTENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)
#USERIF_LIBS = $(QTENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I/root/smc_6_6_0/lib/C++ \
    -I/root/boost_1_61_0 \
    -I../../inet/src \
    -I../../inet/src/inet/transportlayer/contract/tcp \
    -I../../inet/src/inet/networklayer/common \
    -I../../inet/src/inet/applications/tcpapp \
    -I. \
    -Iclient \
    -Iclient/connection \
    -Iclient/messages \
    -Iclient/other \
    -Icontroller \
    -Inodes \
    -Itracker \
    -Itracker/connection \
    -Itracker/messages \
    -Itracker/other

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../inet/out/$(CONFIGNAME)/src -L../../inet/out/$(CONFIGNAME)  -lINET -linet
LIBS += -Wl,-rpath,`abspath ../../inet/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath ../../inet/out/$(CONFIGNAME)`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/client/Choker.o \
    $O/client/BitTorrentClient.o \
    $O/client/ContentManager.o \
    $O/client/SwarmManager.o \
    $O/client/connection/PeerWireThread.o \
    $O/client/other/BitField.o \
    $O/client/other/DataRateRollingAverage.o \
    $O/client/other/RarestPieceCounter.o \
    $O/client/other/PeerStatus.o \
    $O/controller/ClientController.o \
    $O/tracker/TrackerApp.o \
    $O/tracker/connection/PeerConnectionThread.o \
    $O/tracker/other/PeerInfo.o \
    $O/client/messages/UserCommand_m.o \
    $O/client/messages/PeerWireMsgBundle_m.o \
    $O/client/messages/PeerWire_m.o \
    $O/client/messages/Application_m.o \
    $O/tracker/messages/AnnounceResponseMsg_m.o \
    $O/tracker/messages/AnnounceRequestMsg_m.o

# Message files
MSGFILES = \
    client/messages/UserCommand.msg \
    client/messages/PeerWireMsgBundle.msg \
    client/messages/PeerWire.msg \
    client/messages/Application.msg \
    tracker/messages/AnnounceResponseMsg.msg \
    tracker/messages/AnnounceRequestMsg.msg

# SM files
SMFILES =

# Other makefile variables (-K)
INET_PROJ=../../inet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)
SMCOPTS =

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders smheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

%_sm.cc %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cc $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f BitTorrentMANET_Sim_v5 BitTorrentMANET_Sim_v5.exe libBitTorrentMANET_Sim_v5.so libBitTorrentMANET_Sim_v5.a libBitTorrentMANET_Sim_v5.dll libBitTorrentMANET_Sim_v5.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h ./*_sm.cc ./*_sm.h
	$(Q)-rm -f client/*_m.cc client/*_m.h client/*_sm.cc client/*_sm.h
	$(Q)-rm -f client/connection/*_m.cc client/connection/*_m.h client/connection/*_sm.cc client/connection/*_sm.h
	$(Q)-rm -f client/messages/*_m.cc client/messages/*_m.h client/messages/*_sm.cc client/messages/*_sm.h
	$(Q)-rm -f client/other/*_m.cc client/other/*_m.h client/other/*_sm.cc client/other/*_sm.h
	$(Q)-rm -f controller/*_m.cc controller/*_m.h controller/*_sm.cc controller/*_sm.h
	$(Q)-rm -f nodes/*_m.cc nodes/*_m.h nodes/*_sm.cc nodes/*_sm.h
	$(Q)-rm -f tracker/*_m.cc tracker/*_m.h tracker/*_sm.cc tracker/*_sm.h
	$(Q)-rm -f tracker/connection/*_m.cc tracker/connection/*_m.h tracker/connection/*_sm.cc tracker/connection/*_sm.h
	$(Q)-rm -f tracker/messages/*_m.cc tracker/messages/*_m.h tracker/messages/*_sm.cc tracker/messages/*_sm.h
	$(Q)-rm -f tracker/other/*_m.cc tracker/other/*_m.h tracker/other/*_sm.cc tracker/other/*_sm.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES) $(SM_CC_FILES)  ./*.cc client/*.cc client/connection/*.cc client/messages/*.cc client/other/*.cc controller/*.cc nodes/*.cc tracker/*.cc tracker/connection/*.cc tracker/messages/*.cc tracker/other/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/client/BitTorrentClient.o: client/BitTorrentClient.cc \
	client/BitTorrentClient.h \
	client/Choker.h \
	client/ContentManager.h \
	client/SwarmManager.h \
	client/connection/PeerWireThread.h \
	client/messages/Application_m.h \
	client/messages/PeerWireMsgBundle_m.h \
	client/messages/PeerWire_m.h \
	client/other/BitField.h \
	client/other/DataRateRollingAverage.h \
	client/other/PeerStatus.h \
	client/other/RarestPieceCounter.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/TCPSrvHostApp.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocketMap.h
$O/client/Choker.o: client/Choker.cc \
	client/BitTorrentClient.h \
	client/Choker.h \
	client/SwarmManager.h \
	client/connection/PeerWireThread.h \
	client/messages/PeerWireMsgBundle_m.h \
	client/messages/PeerWire_m.h \
	client/other/BitField.h \
	client/other/DataRateRollingAverage.h \
	client/other/PeerStatus.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/TCPSrvHostApp.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocketMap.h
$O/client/ContentManager.o: client/ContentManager.cc \
	client/BitTorrentClient.h \
	client/ContentManager.h \
	client/connection/PeerWireThread.h \
	client/messages/PeerWireMsgBundle_m.h \
	client/messages/PeerWire_m.h \
	client/other/BitField.h \
	client/other/DataRateRollingAverage.h \
	client/other/PeerStatus.h \
	client/other/RarestPieceCounter.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/TCPSrvHostApp.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocketMap.h
$O/client/SwarmManager.o: client/SwarmManager.cc \
	client/BitTorrentClient.h \
	client/SwarmManager.h \
	client/connection/PeerWireThread.h \
	client/messages/PeerWireMsgBundle_m.h \
	client/messages/PeerWire_m.h \
	client/other/BitField.h \
	client/other/DataRateRollingAverage.h \
	client/other/PeerStatus.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/TCPSrvHostApp.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocketMap.h
$O/client/connection/PeerWireThread.o: client/connection/PeerWireThread.cc \
	client/BitTorrentClient.h \
	client/ContentManager.h \
	client/connection/PeerWireThread.h \
	client/messages/Application_m.h \
	client/messages/PeerWireMsgBundle_m.h \
	client/messages/PeerWire_m.h \
	client/other/BitField.h \
	client/other/DataRateRollingAverage.h \
	client/other/PeerStatus.h \
	client/other/RarestPieceCounter.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/TCPSrvHostApp.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocketMap.h
$O/client/messages/Application_m.o: client/messages/Application_m.cc \
	client/messages/Application_m.h
$O/client/messages/PeerWireMsgBundle_m.o: client/messages/PeerWireMsgBundle_m.cc \
	client/messages/PeerWireMsgBundle_m.h \
	client/messages/PeerWire_m.h \
	client/other/BitField.h
$O/client/messages/PeerWire_m.o: client/messages/PeerWire_m.cc \
	client/messages/PeerWire_m.h \
	client/other/BitField.h
$O/client/messages/UserCommand_m.o: client/messages/UserCommand_m.cc \
	client/messages/UserCommand_m.h \
	client/other/BitField.h \
	tracker/TrackerApp.h \
	tracker/messages/AnnounceRequestMsg_m.h \
	tracker/messages/AnnounceResponseMsg_m.h \
	tracker/other/PeerInfo.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/TCPSrvHostApp.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocketMap.h
$O/client/other/BitField.o: client/other/BitField.cc \
	client/other/BitField.h
$O/client/other/DataRateRollingAverage.o: client/other/DataRateRollingAverage.cc \
	client/other/DataRateRollingAverage.h
$O/client/other/PeerStatus.o: client/other/PeerStatus.cc \
	client/connection/PeerWireThread.h \
	client/messages/PeerWireMsgBundle_m.h \
	client/messages/PeerWire_m.h \
	client/other/BitField.h \
	client/other/DataRateRollingAverage.h \
	client/other/PeerStatus.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/TCPSrvHostApp.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocketMap.h
$O/client/other/RarestPieceCounter.o: client/other/RarestPieceCounter.cc \
	client/other/BitField.h \
	client/other/RarestPieceCounter.h
$O/controller/ClientController.o: controller/ClientController.cc \
	client/messages/UserCommand_m.h \
	client/other/BitField.h \
	controller/ClientController.h \
	tracker/TrackerApp.h \
	tracker/messages/AnnounceRequestMsg_m.h \
	tracker/messages/AnnounceResponseMsg_m.h \
	tracker/other/PeerInfo.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/TCPSrvHostApp.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocketMap.h
$O/tracker/TrackerApp.o: tracker/TrackerApp.cc \
	client/other/BitField.h \
	tracker/TrackerApp.h \
	tracker/connection/PeerConnectionThread.h \
	tracker/messages/AnnounceRequestMsg_m.h \
	tracker/messages/AnnounceResponseMsg_m.h \
	tracker/other/PeerInfo.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/TCPSrvHostApp.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocketMap.h
$O/tracker/connection/PeerConnectionThread.o: tracker/connection/PeerConnectionThread.cc \
	client/other/BitField.h \
	tracker/TrackerApp.h \
	tracker/connection/PeerConnectionThread.h \
	tracker/messages/AnnounceRequestMsg_m.h \
	tracker/messages/AnnounceResponseMsg_m.h \
	tracker/other/PeerInfo.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/TCPSrvHostApp.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocketMap.h
$O/tracker/messages/AnnounceRequestMsg_m.o: tracker/messages/AnnounceRequestMsg_m.cc \
	client/other/BitField.h \
	tracker/messages/AnnounceRequestMsg_m.h
$O/tracker/messages/AnnounceResponseMsg_m.o: tracker/messages/AnnounceResponseMsg_m.cc \
	client/other/BitField.h \
	tracker/messages/AnnounceRequestMsg_m.h \
	tracker/messages/AnnounceResponseMsg_m.h \
	tracker/other/PeerInfo.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h
$O/tracker/other/PeerInfo.o: tracker/other/PeerInfo.cc \
	client/other/BitField.h \
	tracker/messages/AnnounceRequestMsg_m.h \
	tracker/other/PeerInfo.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h

