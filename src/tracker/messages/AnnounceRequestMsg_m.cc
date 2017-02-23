//
// Generated file, do not edit! Created by nedtool 5.0 from tracker/messages/AnnounceRequestMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "AnnounceRequestMsg_m.h"

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

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("AnnounceType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("AnnounceType"));
    e->insert(A_STARTED, "A_STARTED");
    e->insert(A_STOPPED, "A_STOPPED");
    e->insert(A_COMPLETED, "A_COMPLETED");
    e->insert(A_NORMAL, "A_NORMAL");
);

Register_Class(AnnounceRequestMsg);

AnnounceRequestMsg::AnnounceRequestMsg(const char *name, int kind) : ::omnetpp::cPacket(name,kind)
{
    this->messageLength = 272;
    this->infoHash = 0;
    this->downloaded = 0;
    this->event = 0;
    this->numWant = 0;
    this->peerId = 0;
    this->port = 0;
    this->uploaded = 0;
}

AnnounceRequestMsg::AnnounceRequestMsg(const AnnounceRequestMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

AnnounceRequestMsg::~AnnounceRequestMsg()
{
}

AnnounceRequestMsg& AnnounceRequestMsg::operator=(const AnnounceRequestMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void AnnounceRequestMsg::copy(const AnnounceRequestMsg& other)
{
    this->messageLength = other.messageLength;
    this->urlEncodedRequest = other.urlEncodedRequest;
    this->infoHash = other.infoHash;
    this->downloaded = other.downloaded;
    this->event = other.event;
    this->numWant = other.numWant;
    this->peerId = other.peerId;
    this->port = other.port;
    this->uploaded = other.uploaded;
}

void AnnounceRequestMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->messageLength);
    doParsimPacking(b,this->urlEncodedRequest);
    doParsimPacking(b,this->infoHash);
    doParsimPacking(b,this->downloaded);
    doParsimPacking(b,this->event);
    doParsimPacking(b,this->numWant);
    doParsimPacking(b,this->peerId);
    doParsimPacking(b,this->port);
    doParsimPacking(b,this->uploaded);
}

void AnnounceRequestMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->messageLength);
    doParsimUnpacking(b,this->urlEncodedRequest);
    doParsimUnpacking(b,this->infoHash);
    doParsimUnpacking(b,this->downloaded);
    doParsimUnpacking(b,this->event);
    doParsimUnpacking(b,this->numWant);
    doParsimUnpacking(b,this->peerId);
    doParsimUnpacking(b,this->port);
    doParsimUnpacking(b,this->uploaded);
}

int AnnounceRequestMsg::getMessageLength() const
{
    return this->messageLength;
}

void AnnounceRequestMsg::setMessageLength(int messageLength)
{
    this->messageLength = messageLength;
}

const char * AnnounceRequestMsg::getUrlEncodedRequest() const
{
    return this->urlEncodedRequest.c_str();
}

void AnnounceRequestMsg::setUrlEncodedRequest(const char * urlEncodedRequest)
{
    this->urlEncodedRequest = urlEncodedRequest;
}

int AnnounceRequestMsg::getInfoHash() const
{
    return this->infoHash;
}

void AnnounceRequestMsg::setInfoHash(int infoHash)
{
    this->infoHash = infoHash;
}

double AnnounceRequestMsg::getDownloaded() const
{
    return this->downloaded;
}

void AnnounceRequestMsg::setDownloaded(double downloaded)
{
    this->downloaded = downloaded;
}

int AnnounceRequestMsg::getEvent() const
{
    return this->event;
}

void AnnounceRequestMsg::setEvent(int event)
{
    this->event = event;
}

unsigned int AnnounceRequestMsg::getNumWant() const
{
    return this->numWant;
}

void AnnounceRequestMsg::setNumWant(unsigned int numWant)
{
    this->numWant = numWant;
}

int AnnounceRequestMsg::getPeerId() const
{
    return this->peerId;
}

void AnnounceRequestMsg::setPeerId(int peerId)
{
    this->peerId = peerId;
}

unsigned int AnnounceRequestMsg::getPort() const
{
    return this->port;
}

void AnnounceRequestMsg::setPort(unsigned int port)
{
    this->port = port;
}

double AnnounceRequestMsg::getUploaded() const
{
    return this->uploaded;
}

void AnnounceRequestMsg::setUploaded(double uploaded)
{
    this->uploaded = uploaded;
}

class AnnounceRequestMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AnnounceRequestMsgDescriptor();
    virtual ~AnnounceRequestMsgDescriptor();

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

Register_ClassDescriptor(AnnounceRequestMsgDescriptor);

AnnounceRequestMsgDescriptor::AnnounceRequestMsgDescriptor() : omnetpp::cClassDescriptor("AnnounceRequestMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

AnnounceRequestMsgDescriptor::~AnnounceRequestMsgDescriptor()
{
    delete[] propertynames;
}

bool AnnounceRequestMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AnnounceRequestMsg *>(obj)!=nullptr;
}

const char **AnnounceRequestMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AnnounceRequestMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AnnounceRequestMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int AnnounceRequestMsgDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *AnnounceRequestMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageLength",
        "urlEncodedRequest",
        "infoHash",
        "downloaded",
        "event",
        "numWant",
        "peerId",
        "port",
        "uploaded",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int AnnounceRequestMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageLength")==0) return base+0;
    if (fieldName[0]=='u' && strcmp(fieldName, "urlEncodedRequest")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "infoHash")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "downloaded")==0) return base+3;
    if (fieldName[0]=='e' && strcmp(fieldName, "event")==0) return base+4;
    if (fieldName[0]=='n' && strcmp(fieldName, "numWant")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "peerId")==0) return base+6;
    if (fieldName[0]=='p' && strcmp(fieldName, "port")==0) return base+7;
    if (fieldName[0]=='u' && strcmp(fieldName, "uploaded")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AnnounceRequestMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "int",
        "double",
        "int",
        "unsigned int",
        "int",
        "unsigned int",
        "double",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **AnnounceRequestMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *AnnounceRequestMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4:
            if (!strcmp(propertyname,"enum")) return "AnnounceType";
            return nullptr;
        default: return nullptr;
    }
}

int AnnounceRequestMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AnnounceRequestMsg *pp = (AnnounceRequestMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AnnounceRequestMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AnnounceRequestMsg *pp = (AnnounceRequestMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMessageLength());
        case 1: return oppstring2string(pp->getUrlEncodedRequest());
        case 2: return long2string(pp->getInfoHash());
        case 3: return double2string(pp->getDownloaded());
        case 4: return enum2string(pp->getEvent(), "AnnounceType");
        case 5: return ulong2string(pp->getNumWant());
        case 6: return long2string(pp->getPeerId());
        case 7: return ulong2string(pp->getPort());
        case 8: return double2string(pp->getUploaded());
        default: return "";
    }
}

bool AnnounceRequestMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AnnounceRequestMsg *pp = (AnnounceRequestMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessageLength(string2long(value)); return true;
        case 1: pp->setUrlEncodedRequest((value)); return true;
        case 2: pp->setInfoHash(string2long(value)); return true;
        case 3: pp->setDownloaded(string2double(value)); return true;
        case 4: pp->setEvent((AnnounceType)string2enum(value, "AnnounceType")); return true;
        case 5: pp->setNumWant(string2ulong(value)); return true;
        case 6: pp->setPeerId(string2long(value)); return true;
        case 7: pp->setPort(string2ulong(value)); return true;
        case 8: pp->setUploaded(string2double(value)); return true;
        default: return false;
    }
}

const char *AnnounceRequestMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *AnnounceRequestMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AnnounceRequestMsg *pp = (AnnounceRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


