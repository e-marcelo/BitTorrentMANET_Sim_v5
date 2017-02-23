//
// Generated file, do not edit! Created by nedtool 5.0 from tracker/messages/AnnounceResponseMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "AnnounceResponseMsg_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: no doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: no doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(AnnounceResponseMsg);

AnnounceResponseMsg::AnnounceResponseMsg(const char *name, int kind) : ::omnetpp::cPacket(name,kind)
{
    this->interval = 0;
    this->minInterval = 0;
    this->trackerId = 0;
    this->complete = 0;
    this->incomplete = 0;
    peers_arraysize = 0;
    this->peers = 0;
}

AnnounceResponseMsg::AnnounceResponseMsg(const AnnounceResponseMsg& other) : ::omnetpp::cPacket(other)
{
    peers_arraysize = 0;
    this->peers = 0;
    copy(other);
}

AnnounceResponseMsg::~AnnounceResponseMsg()
{
    delete [] this->peers;
}

AnnounceResponseMsg& AnnounceResponseMsg::operator=(const AnnounceResponseMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void AnnounceResponseMsg::copy(const AnnounceResponseMsg& other)
{
    this->failureReason = other.failureReason;
    this->warningMessage = other.warningMessage;
    this->interval = other.interval;
    this->minInterval = other.minInterval;
    this->trackerId = other.trackerId;
    this->complete = other.complete;
    this->incomplete = other.incomplete;
    delete [] this->peers;
    this->peers = (other.peers_arraysize==0) ? nullptr : new PeerInfo[other.peers_arraysize];
    peers_arraysize = other.peers_arraysize;
    for (unsigned int i=0; i<peers_arraysize; i++)
        this->peers[i] = other.peers[i];
    this->bencodedResponse = other.bencodedResponse;
}

void AnnounceResponseMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->failureReason);
    doParsimPacking(b,this->warningMessage);
    doParsimPacking(b,this->interval);
    doParsimPacking(b,this->minInterval);
    doParsimPacking(b,this->trackerId);
    doParsimPacking(b,this->complete);
    doParsimPacking(b,this->incomplete);
    b->pack(peers_arraysize);
    doParsimArrayPacking(b,this->peers,peers_arraysize);
    doParsimPacking(b,this->bencodedResponse);
}

void AnnounceResponseMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->failureReason);
    doParsimUnpacking(b,this->warningMessage);
    doParsimUnpacking(b,this->interval);
    doParsimUnpacking(b,this->minInterval);
    doParsimUnpacking(b,this->trackerId);
    doParsimUnpacking(b,this->complete);
    doParsimUnpacking(b,this->incomplete);
    delete [] this->peers;
    b->unpack(peers_arraysize);
    if (peers_arraysize==0) {
        this->peers = 0;
    } else {
        this->peers = new PeerInfo[peers_arraysize];
        doParsimArrayUnpacking(b,this->peers,peers_arraysize);
    }
    doParsimUnpacking(b,this->bencodedResponse);
}

const char * AnnounceResponseMsg::getFailureReason() const
{
    return this->failureReason.c_str();
}

void AnnounceResponseMsg::setFailureReason(const char * failureReason)
{
    this->failureReason = failureReason;
}

const char * AnnounceResponseMsg::getWarningMessage() const
{
    return this->warningMessage.c_str();
}

void AnnounceResponseMsg::setWarningMessage(const char * warningMessage)
{
    this->warningMessage = warningMessage;
}

unsigned int AnnounceResponseMsg::getInterval() const
{
    return this->interval;
}

void AnnounceResponseMsg::setInterval(unsigned int interval)
{
    this->interval = interval;
}

unsigned int AnnounceResponseMsg::getMinInterval() const
{
    return this->minInterval;
}

void AnnounceResponseMsg::setMinInterval(unsigned int minInterval)
{
    this->minInterval = minInterval;
}

int AnnounceResponseMsg::getTrackerId() const
{
    return this->trackerId;
}

void AnnounceResponseMsg::setTrackerId(int trackerId)
{
    this->trackerId = trackerId;
}

unsigned int AnnounceResponseMsg::getComplete() const
{
    return this->complete;
}

void AnnounceResponseMsg::setComplete(unsigned int complete)
{
    this->complete = complete;
}

unsigned int AnnounceResponseMsg::getIncomplete() const
{
    return this->incomplete;
}

void AnnounceResponseMsg::setIncomplete(unsigned int incomplete)
{
    this->incomplete = incomplete;
}

void AnnounceResponseMsg::setPeersArraySize(unsigned int size)
{
    PeerInfo *peers2 = (size==0) ? nullptr : new PeerInfo[size];
    unsigned int sz = peers_arraysize < size ? peers_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        peers2[i] = this->peers[i];
    peers_arraysize = size;
    delete [] this->peers;
    this->peers = peers2;
}

unsigned int AnnounceResponseMsg::getPeersArraySize() const
{
    return peers_arraysize;
}

PeerInfo& AnnounceResponseMsg::getPeers(unsigned int k)
{
    if (k>=peers_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", peers_arraysize, k);
    return this->peers[k];
}

void AnnounceResponseMsg::setPeers(unsigned int k, const PeerInfo& peers)
{
    if (k>=peers_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", peers_arraysize, k);
    this->peers[k] = peers;
}

const char * AnnounceResponseMsg::getBencodedResponse() const
{
    return this->bencodedResponse.c_str();
}

void AnnounceResponseMsg::setBencodedResponse(const char * bencodedResponse)
{
    this->bencodedResponse = bencodedResponse;
}

class AnnounceResponseMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AnnounceResponseMsgDescriptor();
    virtual ~AnnounceResponseMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AnnounceResponseMsgDescriptor);

AnnounceResponseMsgDescriptor::AnnounceResponseMsgDescriptor() : omnetpp::cClassDescriptor("AnnounceResponseMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

AnnounceResponseMsgDescriptor::~AnnounceResponseMsgDescriptor()
{
    delete[] propertynames;
}

bool AnnounceResponseMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AnnounceResponseMsg *>(obj)!=nullptr;
}

const char **AnnounceResponseMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AnnounceResponseMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AnnounceResponseMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int AnnounceResponseMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *AnnounceResponseMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "failureReason",
        "warningMessage",
        "interval",
        "minInterval",
        "trackerId",
        "complete",
        "incomplete",
        "peers",
        "bencodedResponse",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int AnnounceResponseMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "failureReason")==0) return base+0;
    if (fieldName[0]=='w' && strcmp(fieldName, "warningMessage")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "interval")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "minInterval")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "trackerId")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "complete")==0) return base+5;
    if (fieldName[0]=='i' && strcmp(fieldName, "incomplete")==0) return base+6;
    if (fieldName[0]=='p' && strcmp(fieldName, "peers")==0) return base+7;
    if (fieldName[0]=='b' && strcmp(fieldName, "bencodedResponse")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AnnounceResponseMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "unsigned int",
        "unsigned int",
        "int",
        "unsigned int",
        "unsigned int",
        "PeerInfo",
        "string",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **AnnounceResponseMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AnnounceResponseMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AnnounceResponseMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AnnounceResponseMsg *pp = (AnnounceResponseMsg *)object; (void)pp;
    switch (field) {
        case 7: return pp->getPeersArraySize();
        default: return 0;
    }
}

std::string AnnounceResponseMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AnnounceResponseMsg *pp = (AnnounceResponseMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getFailureReason());
        case 1: return oppstring2string(pp->getWarningMessage());
        case 2: return ulong2string(pp->getInterval());
        case 3: return ulong2string(pp->getMinInterval());
        case 4: return long2string(pp->getTrackerId());
        case 5: return ulong2string(pp->getComplete());
        case 6: return ulong2string(pp->getIncomplete());
        case 7: {std::stringstream out; out << pp->getPeers(i); return out.str();}
        case 8: return oppstring2string(pp->getBencodedResponse());
        default: return "";
    }
}

bool AnnounceResponseMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AnnounceResponseMsg *pp = (AnnounceResponseMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setFailureReason((value)); return true;
        case 1: pp->setWarningMessage((value)); return true;
        case 2: pp->setInterval(string2ulong(value)); return true;
        case 3: pp->setMinInterval(string2ulong(value)); return true;
        case 4: pp->setTrackerId(string2long(value)); return true;
        case 5: pp->setComplete(string2ulong(value)); return true;
        case 6: pp->setIncomplete(string2ulong(value)); return true;
        case 8: pp->setBencodedResponse((value)); return true;
        default: return false;
    }
}

const char *AnnounceResponseMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 7: return omnetpp::opp_typename(typeid(PeerInfo));
        default: return nullptr;
    };
}

void *AnnounceResponseMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AnnounceResponseMsg *pp = (AnnounceResponseMsg *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getPeers(i)); break;
        default: return nullptr;
    }
}


