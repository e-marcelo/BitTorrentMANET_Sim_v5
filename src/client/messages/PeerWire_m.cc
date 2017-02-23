//
// Generated file, do not edit! Created by nedtool 5.0 from client/messages/PeerWire.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PeerWire_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("PeerWireMessageType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("PeerWireMessageType"));
    e->insert(PW_CHOKE_MSG, "PW_CHOKE_MSG");
    e->insert(PW_UNCHOKE_MSG, "PW_UNCHOKE_MSG");
    e->insert(PW_INTERESTED_MSG, "PW_INTERESTED_MSG");
    e->insert(PW_NOT_INTERESTED_MSG, "PW_NOT_INTERESTED_MSG");
    e->insert(PW_HAVE_MSG, "PW_HAVE_MSG");
    e->insert(PW_BITFIELD_MSG, "PW_BITFIELD_MSG");
    e->insert(PW_REQUEST_MSG, "PW_REQUEST_MSG");
    e->insert(PW_PIECE_MSG, "PW_PIECE_MSG");
    e->insert(PW_CANCEL_MSG, "PW_CANCEL_MSG");
    e->insert(PW_KEEP_ALIVE_MSG, "PW_KEEP_ALIVE_MSG");
    e->insert(PW_HANDSHAKE_MSG, "PW_HANDSHAKE_MSG");
);

Register_Class(PeerWireMsg);

PeerWireMsg::PeerWireMsg(const char *name, int kind) : ::omnetpp::cPacket(name,kind)
{
    this->headerLen = 4;
    this->payloadLen = 1;
    this->variablePayloadLen = 0;
    this->messageId = 0;
}

PeerWireMsg::PeerWireMsg(const PeerWireMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

PeerWireMsg::~PeerWireMsg()
{
}

PeerWireMsg& PeerWireMsg::operator=(const PeerWireMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void PeerWireMsg::copy(const PeerWireMsg& other)
{
    this->headerLen = other.headerLen;
    this->payloadLen = other.payloadLen;
    this->variablePayloadLen = other.variablePayloadLen;
    this->messageId = other.messageId;
}

void PeerWireMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->headerLen);
    doParsimPacking(b,this->payloadLen);
    doParsimPacking(b,this->variablePayloadLen);
    doParsimPacking(b,this->messageId);
}

void PeerWireMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->headerLen);
    doParsimUnpacking(b,this->payloadLen);
    doParsimUnpacking(b,this->variablePayloadLen);
    doParsimUnpacking(b,this->messageId);
}

int PeerWireMsg::getHeaderLen() const
{
    return this->headerLen;
}

void PeerWireMsg::setHeaderLen(int headerLen)
{
    this->headerLen = headerLen;
}

int PeerWireMsg::getPayloadLen() const
{
    return this->payloadLen;
}

void PeerWireMsg::setPayloadLen(int payloadLen)
{
    this->payloadLen = payloadLen;
}

int PeerWireMsg::getVariablePayloadLen() const
{
    return this->variablePayloadLen;
}

void PeerWireMsg::setVariablePayloadLen(int variablePayloadLen)
{
    this->variablePayloadLen = variablePayloadLen;
}

int PeerWireMsg::getMessageId() const
{
    return this->messageId;
}

void PeerWireMsg::setMessageId(int messageId)
{
    this->messageId = messageId;
}

class PeerWireMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PeerWireMsgDescriptor();
    virtual ~PeerWireMsgDescriptor();

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

Register_ClassDescriptor(PeerWireMsgDescriptor);

PeerWireMsgDescriptor::PeerWireMsgDescriptor() : omnetpp::cClassDescriptor("PeerWireMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

PeerWireMsgDescriptor::~PeerWireMsgDescriptor()
{
    delete[] propertynames;
}

bool PeerWireMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PeerWireMsg *>(obj)!=nullptr;
}

const char **PeerWireMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PeerWireMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PeerWireMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int PeerWireMsgDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *PeerWireMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "headerLen",
        "payloadLen",
        "variablePayloadLen",
        "messageId",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int PeerWireMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerLen")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLen")==0) return base+1;
    if (fieldName[0]=='v' && strcmp(fieldName, "variablePayloadLen")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PeerWireMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **PeerWireMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *PeerWireMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3:
            if (!strcmp(propertyname,"enum")) return "PeerWireMessageType";
            return nullptr;
        default: return nullptr;
    }
}

int PeerWireMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PeerWireMsg *pp = (PeerWireMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PeerWireMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PeerWireMsg *pp = (PeerWireMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getHeaderLen());
        case 1: return long2string(pp->getPayloadLen());
        case 2: return long2string(pp->getVariablePayloadLen());
        case 3: return enum2string(pp->getMessageId(), "PeerWireMessageType");
        default: return "";
    }
}

bool PeerWireMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PeerWireMsg *pp = (PeerWireMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setHeaderLen(string2long(value)); return true;
        case 1: pp->setPayloadLen(string2long(value)); return true;
        case 2: pp->setVariablePayloadLen(string2long(value)); return true;
        case 3: pp->setMessageId((PeerWireMessageType)string2enum(value, "PeerWireMessageType")); return true;
        default: return false;
    }
}

const char *PeerWireMsgDescriptor::getFieldStructName(int field) const
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

void *PeerWireMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PeerWireMsg *pp = (PeerWireMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ChokeMsg);

ChokeMsg::ChokeMsg(const char *name, int kind) : ::PeerWireMsg(name,kind)
{
    this->messageId = PW_CHOKE_MSG;
}

ChokeMsg::ChokeMsg(const ChokeMsg& other) : ::PeerWireMsg(other)
{
    copy(other);
}

ChokeMsg::~ChokeMsg()
{
}

ChokeMsg& ChokeMsg::operator=(const ChokeMsg& other)
{
    if (this==&other) return *this;
    ::PeerWireMsg::operator=(other);
    copy(other);
    return *this;
}

void ChokeMsg::copy(const ChokeMsg& other)
{
    this->messageId = other.messageId;
}

void ChokeMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PeerWireMsg::parsimPack(b);
    doParsimPacking(b,this->messageId);
}

void ChokeMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PeerWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->messageId);
}

int ChokeMsg::getMessageId() const
{
    return this->messageId;
}

void ChokeMsg::setMessageId(int messageId)
{
    this->messageId = messageId;
}

class ChokeMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ChokeMsgDescriptor();
    virtual ~ChokeMsgDescriptor();

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

Register_ClassDescriptor(ChokeMsgDescriptor);

ChokeMsgDescriptor::ChokeMsgDescriptor() : omnetpp::cClassDescriptor("ChokeMsg", "PeerWireMsg")
{
    propertynames = nullptr;
}

ChokeMsgDescriptor::~ChokeMsgDescriptor()
{
    delete[] propertynames;
}

bool ChokeMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ChokeMsg *>(obj)!=nullptr;
}

const char **ChokeMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ChokeMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ChokeMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int ChokeMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *ChokeMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageId",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int ChokeMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ChokeMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **ChokeMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *ChokeMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int ChokeMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ChokeMsg *pp = (ChokeMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ChokeMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ChokeMsg *pp = (ChokeMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMessageId());
        default: return "";
    }
}

bool ChokeMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ChokeMsg *pp = (ChokeMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessageId(string2long(value)); return true;
        default: return false;
    }
}

const char *ChokeMsgDescriptor::getFieldStructName(int field) const
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

void *ChokeMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ChokeMsg *pp = (ChokeMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UnchokeMsg);

UnchokeMsg::UnchokeMsg(const char *name, int kind) : ::PeerWireMsg(name,kind)
{
    this->messageId = PW_UNCHOKE_MSG;
}

UnchokeMsg::UnchokeMsg(const UnchokeMsg& other) : ::PeerWireMsg(other)
{
    copy(other);
}

UnchokeMsg::~UnchokeMsg()
{
}

UnchokeMsg& UnchokeMsg::operator=(const UnchokeMsg& other)
{
    if (this==&other) return *this;
    ::PeerWireMsg::operator=(other);
    copy(other);
    return *this;
}

void UnchokeMsg::copy(const UnchokeMsg& other)
{
    this->messageId = other.messageId;
}

void UnchokeMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PeerWireMsg::parsimPack(b);
    doParsimPacking(b,this->messageId);
}

void UnchokeMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PeerWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->messageId);
}

int UnchokeMsg::getMessageId() const
{
    return this->messageId;
}

void UnchokeMsg::setMessageId(int messageId)
{
    this->messageId = messageId;
}

class UnchokeMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UnchokeMsgDescriptor();
    virtual ~UnchokeMsgDescriptor();

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

Register_ClassDescriptor(UnchokeMsgDescriptor);

UnchokeMsgDescriptor::UnchokeMsgDescriptor() : omnetpp::cClassDescriptor("UnchokeMsg", "PeerWireMsg")
{
    propertynames = nullptr;
}

UnchokeMsgDescriptor::~UnchokeMsgDescriptor()
{
    delete[] propertynames;
}

bool UnchokeMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UnchokeMsg *>(obj)!=nullptr;
}

const char **UnchokeMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UnchokeMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UnchokeMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UnchokeMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *UnchokeMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageId",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int UnchokeMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UnchokeMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **UnchokeMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *UnchokeMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UnchokeMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UnchokeMsg *pp = (UnchokeMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UnchokeMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UnchokeMsg *pp = (UnchokeMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMessageId());
        default: return "";
    }
}

bool UnchokeMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UnchokeMsg *pp = (UnchokeMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessageId(string2long(value)); return true;
        default: return false;
    }
}

const char *UnchokeMsgDescriptor::getFieldStructName(int field) const
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

void *UnchokeMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UnchokeMsg *pp = (UnchokeMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(InterestedMsg);

InterestedMsg::InterestedMsg(const char *name, int kind) : ::PeerWireMsg(name,kind)
{
    this->messageId = PW_INTERESTED_MSG;
}

InterestedMsg::InterestedMsg(const InterestedMsg& other) : ::PeerWireMsg(other)
{
    copy(other);
}

InterestedMsg::~InterestedMsg()
{
}

InterestedMsg& InterestedMsg::operator=(const InterestedMsg& other)
{
    if (this==&other) return *this;
    ::PeerWireMsg::operator=(other);
    copy(other);
    return *this;
}

void InterestedMsg::copy(const InterestedMsg& other)
{
    this->messageId = other.messageId;
}

void InterestedMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PeerWireMsg::parsimPack(b);
    doParsimPacking(b,this->messageId);
}

void InterestedMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PeerWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->messageId);
}

int InterestedMsg::getMessageId() const
{
    return this->messageId;
}

void InterestedMsg::setMessageId(int messageId)
{
    this->messageId = messageId;
}

class InterestedMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    InterestedMsgDescriptor();
    virtual ~InterestedMsgDescriptor();

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

Register_ClassDescriptor(InterestedMsgDescriptor);

InterestedMsgDescriptor::InterestedMsgDescriptor() : omnetpp::cClassDescriptor("InterestedMsg", "PeerWireMsg")
{
    propertynames = nullptr;
}

InterestedMsgDescriptor::~InterestedMsgDescriptor()
{
    delete[] propertynames;
}

bool InterestedMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<InterestedMsg *>(obj)!=nullptr;
}

const char **InterestedMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *InterestedMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int InterestedMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int InterestedMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *InterestedMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageId",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int InterestedMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *InterestedMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **InterestedMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *InterestedMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int InterestedMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    InterestedMsg *pp = (InterestedMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string InterestedMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    InterestedMsg *pp = (InterestedMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMessageId());
        default: return "";
    }
}

bool InterestedMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    InterestedMsg *pp = (InterestedMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessageId(string2long(value)); return true;
        default: return false;
    }
}

const char *InterestedMsgDescriptor::getFieldStructName(int field) const
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

void *InterestedMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    InterestedMsg *pp = (InterestedMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NotInterestedMsg);

NotInterestedMsg::NotInterestedMsg(const char *name, int kind) : ::PeerWireMsg(name,kind)
{
    this->messageId = PW_NOT_INTERESTED_MSG;
}

NotInterestedMsg::NotInterestedMsg(const NotInterestedMsg& other) : ::PeerWireMsg(other)
{
    copy(other);
}

NotInterestedMsg::~NotInterestedMsg()
{
}

NotInterestedMsg& NotInterestedMsg::operator=(const NotInterestedMsg& other)
{
    if (this==&other) return *this;
    ::PeerWireMsg::operator=(other);
    copy(other);
    return *this;
}

void NotInterestedMsg::copy(const NotInterestedMsg& other)
{
    this->messageId = other.messageId;
}

void NotInterestedMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PeerWireMsg::parsimPack(b);
    doParsimPacking(b,this->messageId);
}

void NotInterestedMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PeerWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->messageId);
}

int NotInterestedMsg::getMessageId() const
{
    return this->messageId;
}

void NotInterestedMsg::setMessageId(int messageId)
{
    this->messageId = messageId;
}

class NotInterestedMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NotInterestedMsgDescriptor();
    virtual ~NotInterestedMsgDescriptor();

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

Register_ClassDescriptor(NotInterestedMsgDescriptor);

NotInterestedMsgDescriptor::NotInterestedMsgDescriptor() : omnetpp::cClassDescriptor("NotInterestedMsg", "PeerWireMsg")
{
    propertynames = nullptr;
}

NotInterestedMsgDescriptor::~NotInterestedMsgDescriptor()
{
    delete[] propertynames;
}

bool NotInterestedMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NotInterestedMsg *>(obj)!=nullptr;
}

const char **NotInterestedMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NotInterestedMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NotInterestedMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int NotInterestedMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *NotInterestedMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageId",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int NotInterestedMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NotInterestedMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **NotInterestedMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *NotInterestedMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NotInterestedMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NotInterestedMsg *pp = (NotInterestedMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string NotInterestedMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NotInterestedMsg *pp = (NotInterestedMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMessageId());
        default: return "";
    }
}

bool NotInterestedMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NotInterestedMsg *pp = (NotInterestedMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessageId(string2long(value)); return true;
        default: return false;
    }
}

const char *NotInterestedMsgDescriptor::getFieldStructName(int field) const
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

void *NotInterestedMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NotInterestedMsg *pp = (NotInterestedMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(HaveMsg);

HaveMsg::HaveMsg(const char *name, int kind) : ::PeerWireMsg(name,kind)
{
    this->payloadLen = 5;
    this->messageId = PW_HAVE_MSG;
    this->index = 0;
}

HaveMsg::HaveMsg(const HaveMsg& other) : ::PeerWireMsg(other)
{
    copy(other);
}

HaveMsg::~HaveMsg()
{
}

HaveMsg& HaveMsg::operator=(const HaveMsg& other)
{
    if (this==&other) return *this;
    ::PeerWireMsg::operator=(other);
    copy(other);
    return *this;
}

void HaveMsg::copy(const HaveMsg& other)
{
    this->payloadLen = other.payloadLen;
    this->messageId = other.messageId;
    this->index = other.index;
}

void HaveMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PeerWireMsg::parsimPack(b);
    doParsimPacking(b,this->payloadLen);
    doParsimPacking(b,this->messageId);
    doParsimPacking(b,this->index);
}

void HaveMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PeerWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->payloadLen);
    doParsimUnpacking(b,this->messageId);
    doParsimUnpacking(b,this->index);
}

int HaveMsg::getPayloadLen() const
{
    return this->payloadLen;
}

void HaveMsg::setPayloadLen(int payloadLen)
{
    this->payloadLen = payloadLen;
}

int HaveMsg::getMessageId() const
{
    return this->messageId;
}

void HaveMsg::setMessageId(int messageId)
{
    this->messageId = messageId;
}

int HaveMsg::getIndex() const
{
    return this->index;
}

void HaveMsg::setIndex(int index)
{
    this->index = index;
}

class HaveMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    HaveMsgDescriptor();
    virtual ~HaveMsgDescriptor();

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

Register_ClassDescriptor(HaveMsgDescriptor);

HaveMsgDescriptor::HaveMsgDescriptor() : omnetpp::cClassDescriptor("HaveMsg", "PeerWireMsg")
{
    propertynames = nullptr;
}

HaveMsgDescriptor::~HaveMsgDescriptor()
{
    delete[] propertynames;
}

bool HaveMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HaveMsg *>(obj)!=nullptr;
}

const char **HaveMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HaveMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HaveMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int HaveMsgDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *HaveMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "payloadLen",
        "messageId",
        "index",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int HaveMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLen")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HaveMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **HaveMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *HaveMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int HaveMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    HaveMsg *pp = (HaveMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string HaveMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HaveMsg *pp = (HaveMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPayloadLen());
        case 1: return long2string(pp->getMessageId());
        case 2: return long2string(pp->getIndex());
        default: return "";
    }
}

bool HaveMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    HaveMsg *pp = (HaveMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setPayloadLen(string2long(value)); return true;
        case 1: pp->setMessageId(string2long(value)); return true;
        case 2: pp->setIndex(string2long(value)); return true;
        default: return false;
    }
}

const char *HaveMsgDescriptor::getFieldStructName(int field) const
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

void *HaveMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    HaveMsg *pp = (HaveMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RequestMsg);

RequestMsg::RequestMsg(const char *name, int kind) : ::PeerWireMsg(name,kind)
{
    this->payloadLen = 13;
    this->messageId = PW_REQUEST_MSG;
    this->index = 0;
    this->begin = 0;
    this->reqLength = 0;
}

RequestMsg::RequestMsg(const RequestMsg& other) : ::PeerWireMsg(other)
{
    copy(other);
}

RequestMsg::~RequestMsg()
{
}

RequestMsg& RequestMsg::operator=(const RequestMsg& other)
{
    if (this==&other) return *this;
    ::PeerWireMsg::operator=(other);
    copy(other);
    return *this;
}

void RequestMsg::copy(const RequestMsg& other)
{
    this->payloadLen = other.payloadLen;
    this->messageId = other.messageId;
    this->index = other.index;
    this->begin = other.begin;
    this->reqLength = other.reqLength;
}

void RequestMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PeerWireMsg::parsimPack(b);
    doParsimPacking(b,this->payloadLen);
    doParsimPacking(b,this->messageId);
    doParsimPacking(b,this->index);
    doParsimPacking(b,this->begin);
    doParsimPacking(b,this->reqLength);
}

void RequestMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PeerWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->payloadLen);
    doParsimUnpacking(b,this->messageId);
    doParsimUnpacking(b,this->index);
    doParsimUnpacking(b,this->begin);
    doParsimUnpacking(b,this->reqLength);
}

int RequestMsg::getPayloadLen() const
{
    return this->payloadLen;
}

void RequestMsg::setPayloadLen(int payloadLen)
{
    this->payloadLen = payloadLen;
}

int RequestMsg::getMessageId() const
{
    return this->messageId;
}

void RequestMsg::setMessageId(int messageId)
{
    this->messageId = messageId;
}

int RequestMsg::getIndex() const
{
    return this->index;
}

void RequestMsg::setIndex(int index)
{
    this->index = index;
}

int RequestMsg::getBegin() const
{
    return this->begin;
}

void RequestMsg::setBegin(int begin)
{
    this->begin = begin;
}

int RequestMsg::getReqLength() const
{
    return this->reqLength;
}

void RequestMsg::setReqLength(int reqLength)
{
    this->reqLength = reqLength;
}

class RequestMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RequestMsgDescriptor();
    virtual ~RequestMsgDescriptor();

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

Register_ClassDescriptor(RequestMsgDescriptor);

RequestMsgDescriptor::RequestMsgDescriptor() : omnetpp::cClassDescriptor("RequestMsg", "PeerWireMsg")
{
    propertynames = nullptr;
}

RequestMsgDescriptor::~RequestMsgDescriptor()
{
    delete[] propertynames;
}

bool RequestMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RequestMsg *>(obj)!=nullptr;
}

const char **RequestMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RequestMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RequestMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int RequestMsgDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *RequestMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "payloadLen",
        "messageId",
        "index",
        "begin",
        "reqLength",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int RequestMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLen")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "begin")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "reqLength")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RequestMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **RequestMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *RequestMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RequestMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RequestMsg *pp = (RequestMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RequestMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RequestMsg *pp = (RequestMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPayloadLen());
        case 1: return long2string(pp->getMessageId());
        case 2: return long2string(pp->getIndex());
        case 3: return long2string(pp->getBegin());
        case 4: return long2string(pp->getReqLength());
        default: return "";
    }
}

bool RequestMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RequestMsg *pp = (RequestMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setPayloadLen(string2long(value)); return true;
        case 1: pp->setMessageId(string2long(value)); return true;
        case 2: pp->setIndex(string2long(value)); return true;
        case 3: pp->setBegin(string2long(value)); return true;
        case 4: pp->setReqLength(string2long(value)); return true;
        default: return false;
    }
}

const char *RequestMsgDescriptor::getFieldStructName(int field) const
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

void *RequestMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RequestMsg *pp = (RequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(BitFieldMsg);

BitFieldMsg::BitFieldMsg(const char *name, int kind) : ::PeerWireMsg(name,kind)
{
    this->messageId = PW_BITFIELD_MSG;
    this->payloadLen = 1 + 0;
    this->numberOfPieces = 0;
}

BitFieldMsg::BitFieldMsg(const BitFieldMsg& other) : ::PeerWireMsg(other)
{
    copy(other);
}

BitFieldMsg::~BitFieldMsg()
{
}

BitFieldMsg& BitFieldMsg::operator=(const BitFieldMsg& other)
{
    if (this==&other) return *this;
    ::PeerWireMsg::operator=(other);
    copy(other);
    return *this;
}

void BitFieldMsg::copy(const BitFieldMsg& other)
{
    this->messageId = other.messageId;
    this->payloadLen = other.payloadLen;
    this->bitField = other.bitField;
    this->numberOfPieces = other.numberOfPieces;
}

void BitFieldMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PeerWireMsg::parsimPack(b);
    doParsimPacking(b,this->messageId);
    doParsimPacking(b,this->payloadLen);
    doParsimPacking(b,this->bitField);
    doParsimPacking(b,this->numberOfPieces);
}

void BitFieldMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PeerWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->messageId);
    doParsimUnpacking(b,this->payloadLen);
    doParsimUnpacking(b,this->bitField);
    doParsimUnpacking(b,this->numberOfPieces);
}

int BitFieldMsg::getMessageId() const
{
    return this->messageId;
}

void BitFieldMsg::setMessageId(int messageId)
{
    this->messageId = messageId;
}

int BitFieldMsg::getPayloadLen() const
{
    return this->payloadLen;
}

void BitFieldMsg::setPayloadLen(int payloadLen)
{
    this->payloadLen = payloadLen;
}

BitField& BitFieldMsg::getBitField()
{
    return this->bitField;
}

void BitFieldMsg::setBitField(const BitField& bitField)
{
    this->bitField = bitField;
}

int BitFieldMsg::getNumberOfPieces() const
{
    return this->numberOfPieces;
}

void BitFieldMsg::setNumberOfPieces(int numberOfPieces)
{
    this->numberOfPieces = numberOfPieces;
}

class BitFieldMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BitFieldMsgDescriptor();
    virtual ~BitFieldMsgDescriptor();

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

Register_ClassDescriptor(BitFieldMsgDescriptor);

BitFieldMsgDescriptor::BitFieldMsgDescriptor() : omnetpp::cClassDescriptor("BitFieldMsg", "PeerWireMsg")
{
    propertynames = nullptr;
}

BitFieldMsgDescriptor::~BitFieldMsgDescriptor()
{
    delete[] propertynames;
}

bool BitFieldMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BitFieldMsg *>(obj)!=nullptr;
}

const char **BitFieldMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BitFieldMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BitFieldMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int BitFieldMsgDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *BitFieldMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageId",
        "payloadLen",
        "bitField",
        "numberOfPieces",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int BitFieldMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLen")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitField")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberOfPieces")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BitFieldMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "BitField",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **BitFieldMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *BitFieldMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BitFieldMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BitFieldMsg *pp = (BitFieldMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BitFieldMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BitFieldMsg *pp = (BitFieldMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMessageId());
        case 1: return long2string(pp->getPayloadLen());
        case 2: {std::stringstream out; out << pp->getBitField(); return out.str();}
        case 3: return long2string(pp->getNumberOfPieces());
        default: return "";
    }
}

bool BitFieldMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BitFieldMsg *pp = (BitFieldMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessageId(string2long(value)); return true;
        case 1: pp->setPayloadLen(string2long(value)); return true;
        case 3: pp->setNumberOfPieces(string2long(value)); return true;
        default: return false;
    }
}

const char *BitFieldMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(BitField));
        default: return nullptr;
    };
}

void *BitFieldMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BitFieldMsg *pp = (BitFieldMsg *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getBitField()); break;
        default: return nullptr;
    }
}

Register_Class(PieceMsg);

PieceMsg::PieceMsg(const char *name, int kind) : ::PeerWireMsg(name,kind)
{
    this->payloadLen = 9 + 0;
    this->messageId = PW_PIECE_MSG;
    this->index = 0;
    this->begin = 0;
    this->blockSize = 0;
}

PieceMsg::PieceMsg(const PieceMsg& other) : ::PeerWireMsg(other)
{
    copy(other);
}

PieceMsg::~PieceMsg()
{
}

PieceMsg& PieceMsg::operator=(const PieceMsg& other)
{
    if (this==&other) return *this;
    ::PeerWireMsg::operator=(other);
    copy(other);
    return *this;
}

void PieceMsg::copy(const PieceMsg& other)
{
    this->payloadLen = other.payloadLen;
    this->messageId = other.messageId;
    this->index = other.index;
    this->begin = other.begin;
    this->blockSize = other.blockSize;
}

void PieceMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PeerWireMsg::parsimPack(b);
    doParsimPacking(b,this->payloadLen);
    doParsimPacking(b,this->messageId);
    doParsimPacking(b,this->index);
    doParsimPacking(b,this->begin);
    doParsimPacking(b,this->blockSize);
}

void PieceMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PeerWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->payloadLen);
    doParsimUnpacking(b,this->messageId);
    doParsimUnpacking(b,this->index);
    doParsimUnpacking(b,this->begin);
    doParsimUnpacking(b,this->blockSize);
}

int PieceMsg::getPayloadLen() const
{
    return this->payloadLen;
}

void PieceMsg::setPayloadLen(int payloadLen)
{
    this->payloadLen = payloadLen;
}

int PieceMsg::getMessageId() const
{
    return this->messageId;
}

void PieceMsg::setMessageId(int messageId)
{
    this->messageId = messageId;
}

int PieceMsg::getIndex() const
{
    return this->index;
}

void PieceMsg::setIndex(int index)
{
    this->index = index;
}

int PieceMsg::getBegin() const
{
    return this->begin;
}

void PieceMsg::setBegin(int begin)
{
    this->begin = begin;
}

int PieceMsg::getBlockSize() const
{
    return this->blockSize;
}

void PieceMsg::setBlockSize(int blockSize)
{
    this->blockSize = blockSize;
}

class PieceMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PieceMsgDescriptor();
    virtual ~PieceMsgDescriptor();

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

Register_ClassDescriptor(PieceMsgDescriptor);

PieceMsgDescriptor::PieceMsgDescriptor() : omnetpp::cClassDescriptor("PieceMsg", "PeerWireMsg")
{
    propertynames = nullptr;
}

PieceMsgDescriptor::~PieceMsgDescriptor()
{
    delete[] propertynames;
}

bool PieceMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PieceMsg *>(obj)!=nullptr;
}

const char **PieceMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PieceMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PieceMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int PieceMsgDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *PieceMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "payloadLen",
        "messageId",
        "index",
        "begin",
        "blockSize",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int PieceMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLen")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "begin")==0) return base+3;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockSize")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PieceMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **PieceMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *PieceMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PieceMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PieceMsg *pp = (PieceMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PieceMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PieceMsg *pp = (PieceMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPayloadLen());
        case 1: return long2string(pp->getMessageId());
        case 2: return long2string(pp->getIndex());
        case 3: return long2string(pp->getBegin());
        case 4: return long2string(pp->getBlockSize());
        default: return "";
    }
}

bool PieceMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PieceMsg *pp = (PieceMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setPayloadLen(string2long(value)); return true;
        case 1: pp->setMessageId(string2long(value)); return true;
        case 2: pp->setIndex(string2long(value)); return true;
        case 3: pp->setBegin(string2long(value)); return true;
        case 4: pp->setBlockSize(string2long(value)); return true;
        default: return false;
    }
}

const char *PieceMsgDescriptor::getFieldStructName(int field) const
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

void *PieceMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PieceMsg *pp = (PieceMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CancelMsg);

CancelMsg::CancelMsg(const char *name, int kind) : ::PeerWireMsg(name,kind)
{
    this->payloadLen = 13;
    this->messageId = PW_CANCEL_MSG;
    this->index = 0;
    this->begin = 0;
    this->reqLength = 0;
}

CancelMsg::CancelMsg(const CancelMsg& other) : ::PeerWireMsg(other)
{
    copy(other);
}

CancelMsg::~CancelMsg()
{
}

CancelMsg& CancelMsg::operator=(const CancelMsg& other)
{
    if (this==&other) return *this;
    ::PeerWireMsg::operator=(other);
    copy(other);
    return *this;
}

void CancelMsg::copy(const CancelMsg& other)
{
    this->payloadLen = other.payloadLen;
    this->messageId = other.messageId;
    this->index = other.index;
    this->begin = other.begin;
    this->reqLength = other.reqLength;
}

void CancelMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PeerWireMsg::parsimPack(b);
    doParsimPacking(b,this->payloadLen);
    doParsimPacking(b,this->messageId);
    doParsimPacking(b,this->index);
    doParsimPacking(b,this->begin);
    doParsimPacking(b,this->reqLength);
}

void CancelMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PeerWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->payloadLen);
    doParsimUnpacking(b,this->messageId);
    doParsimUnpacking(b,this->index);
    doParsimUnpacking(b,this->begin);
    doParsimUnpacking(b,this->reqLength);
}

int CancelMsg::getPayloadLen() const
{
    return this->payloadLen;
}

void CancelMsg::setPayloadLen(int payloadLen)
{
    this->payloadLen = payloadLen;
}

int CancelMsg::getMessageId() const
{
    return this->messageId;
}

void CancelMsg::setMessageId(int messageId)
{
    this->messageId = messageId;
}

int CancelMsg::getIndex() const
{
    return this->index;
}

void CancelMsg::setIndex(int index)
{
    this->index = index;
}

int CancelMsg::getBegin() const
{
    return this->begin;
}

void CancelMsg::setBegin(int begin)
{
    this->begin = begin;
}

int CancelMsg::getReqLength() const
{
    return this->reqLength;
}

void CancelMsg::setReqLength(int reqLength)
{
    this->reqLength = reqLength;
}

class CancelMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    CancelMsgDescriptor();
    virtual ~CancelMsgDescriptor();

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

Register_ClassDescriptor(CancelMsgDescriptor);

CancelMsgDescriptor::CancelMsgDescriptor() : omnetpp::cClassDescriptor("CancelMsg", "PeerWireMsg")
{
    propertynames = nullptr;
}

CancelMsgDescriptor::~CancelMsgDescriptor()
{
    delete[] propertynames;
}

bool CancelMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CancelMsg *>(obj)!=nullptr;
}

const char **CancelMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CancelMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CancelMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int CancelMsgDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *CancelMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "payloadLen",
        "messageId",
        "index",
        "begin",
        "reqLength",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int CancelMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLen")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "begin")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "reqLength")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CancelMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **CancelMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *CancelMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int CancelMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CancelMsg *pp = (CancelMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string CancelMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CancelMsg *pp = (CancelMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPayloadLen());
        case 1: return long2string(pp->getMessageId());
        case 2: return long2string(pp->getIndex());
        case 3: return long2string(pp->getBegin());
        case 4: return long2string(pp->getReqLength());
        default: return "";
    }
}

bool CancelMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CancelMsg *pp = (CancelMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setPayloadLen(string2long(value)); return true;
        case 1: pp->setMessageId(string2long(value)); return true;
        case 2: pp->setIndex(string2long(value)); return true;
        case 3: pp->setBegin(string2long(value)); return true;
        case 4: pp->setReqLength(string2long(value)); return true;
        default: return false;
    }
}

const char *CancelMsgDescriptor::getFieldStructName(int field) const
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

void *CancelMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CancelMsg *pp = (CancelMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(KeepAliveMsg);

KeepAliveMsg::KeepAliveMsg(const char *name, int kind) : ::PeerWireMsg(name,kind)
{
    this->payloadLen = 0;
    this->messageId = PW_KEEP_ALIVE_MSG;
}

KeepAliveMsg::KeepAliveMsg(const KeepAliveMsg& other) : ::PeerWireMsg(other)
{
    copy(other);
}

KeepAliveMsg::~KeepAliveMsg()
{
}

KeepAliveMsg& KeepAliveMsg::operator=(const KeepAliveMsg& other)
{
    if (this==&other) return *this;
    ::PeerWireMsg::operator=(other);
    copy(other);
    return *this;
}

void KeepAliveMsg::copy(const KeepAliveMsg& other)
{
    this->payloadLen = other.payloadLen;
    this->messageId = other.messageId;
}

void KeepAliveMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PeerWireMsg::parsimPack(b);
    doParsimPacking(b,this->payloadLen);
    doParsimPacking(b,this->messageId);
}

void KeepAliveMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PeerWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->payloadLen);
    doParsimUnpacking(b,this->messageId);
}

int KeepAliveMsg::getPayloadLen() const
{
    return this->payloadLen;
}

void KeepAliveMsg::setPayloadLen(int payloadLen)
{
    this->payloadLen = payloadLen;
}

int KeepAliveMsg::getMessageId() const
{
    return this->messageId;
}

void KeepAliveMsg::setMessageId(int messageId)
{
    this->messageId = messageId;
}

class KeepAliveMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KeepAliveMsgDescriptor();
    virtual ~KeepAliveMsgDescriptor();

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

Register_ClassDescriptor(KeepAliveMsgDescriptor);

KeepAliveMsgDescriptor::KeepAliveMsgDescriptor() : omnetpp::cClassDescriptor("KeepAliveMsg", "PeerWireMsg")
{
    propertynames = nullptr;
}

KeepAliveMsgDescriptor::~KeepAliveMsgDescriptor()
{
    delete[] propertynames;
}

bool KeepAliveMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KeepAliveMsg *>(obj)!=nullptr;
}

const char **KeepAliveMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KeepAliveMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KeepAliveMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int KeepAliveMsgDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *KeepAliveMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "payloadLen",
        "messageId",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int KeepAliveMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLen")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KeepAliveMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **KeepAliveMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *KeepAliveMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int KeepAliveMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KeepAliveMsg *pp = (KeepAliveMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string KeepAliveMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KeepAliveMsg *pp = (KeepAliveMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPayloadLen());
        case 1: return long2string(pp->getMessageId());
        default: return "";
    }
}

bool KeepAliveMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KeepAliveMsg *pp = (KeepAliveMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setPayloadLen(string2long(value)); return true;
        case 1: pp->setMessageId(string2long(value)); return true;
        default: return false;
    }
}

const char *KeepAliveMsgDescriptor::getFieldStructName(int field) const
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

void *KeepAliveMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KeepAliveMsg *pp = (KeepAliveMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Handshake);

Handshake::Handshake(const char *name, int kind) : ::PeerWireMsg(name,kind)
{
    this->messageId = PW_HANDSHAKE_MSG;
    this->length = 68;
    this->pstrlen = 19;
    this->pstr = "BitTorrent protocol";
    this->reserved = 0;
    this->infoHash = 0;
    this->peerId = 0;
}

Handshake::Handshake(const Handshake& other) : ::PeerWireMsg(other)
{
    copy(other);
}

Handshake::~Handshake()
{
}

Handshake& Handshake::operator=(const Handshake& other)
{
    if (this==&other) return *this;
    ::PeerWireMsg::operator=(other);
    copy(other);
    return *this;
}

void Handshake::copy(const Handshake& other)
{
    this->messageId = other.messageId;
    this->length = other.length;
    this->pstrlen = other.pstrlen;
    this->pstr = other.pstr;
    this->reserved = other.reserved;
    this->infoHash = other.infoHash;
    this->peerId = other.peerId;
}

void Handshake::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PeerWireMsg::parsimPack(b);
    doParsimPacking(b,this->messageId);
    doParsimPacking(b,this->length);
    doParsimPacking(b,this->pstrlen);
    doParsimPacking(b,this->pstr);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->infoHash);
    doParsimPacking(b,this->peerId);
}

void Handshake::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PeerWireMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->messageId);
    doParsimUnpacking(b,this->length);
    doParsimUnpacking(b,this->pstrlen);
    doParsimUnpacking(b,this->pstr);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->infoHash);
    doParsimUnpacking(b,this->peerId);
}

int Handshake::getMessageId() const
{
    return this->messageId;
}

void Handshake::setMessageId(int messageId)
{
    this->messageId = messageId;
}

int Handshake::getLength() const
{
    return this->length;
}

void Handshake::setLength(int length)
{
    this->length = length;
}

int Handshake::getPstrlen() const
{
    return this->pstrlen;
}

void Handshake::setPstrlen(int pstrlen)
{
    this->pstrlen = pstrlen;
}

const char * Handshake::getPstr() const
{
    return this->pstr.c_str();
}

void Handshake::setPstr(const char * pstr)
{
    this->pstr = pstr;
}

int Handshake::getReserved() const
{
    return this->reserved;
}

void Handshake::setReserved(int reserved)
{
    this->reserved = reserved;
}

int Handshake::getInfoHash() const
{
    return this->infoHash;
}

void Handshake::setInfoHash(int infoHash)
{
    this->infoHash = infoHash;
}

int Handshake::getPeerId() const
{
    return this->peerId;
}

void Handshake::setPeerId(int peerId)
{
    this->peerId = peerId;
}

class HandshakeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    HandshakeDescriptor();
    virtual ~HandshakeDescriptor();

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

Register_ClassDescriptor(HandshakeDescriptor);

HandshakeDescriptor::HandshakeDescriptor() : omnetpp::cClassDescriptor("Handshake", "PeerWireMsg")
{
    propertynames = nullptr;
}

HandshakeDescriptor::~HandshakeDescriptor()
{
    delete[] propertynames;
}

bool HandshakeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Handshake *>(obj)!=nullptr;
}

const char **HandshakeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HandshakeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HandshakeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int HandshakeDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *HandshakeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageId",
        "length",
        "pstrlen",
        "pstr",
        "reserved",
        "infoHash",
        "peerId",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int HandshakeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "pstrlen")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "pstr")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "infoHash")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "peerId")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HandshakeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "string",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **HandshakeDescriptor::getFieldPropertyNames(int field) const
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

const char *HandshakeDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int HandshakeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Handshake *pp = (Handshake *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string HandshakeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Handshake *pp = (Handshake *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMessageId());
        case 1: return long2string(pp->getLength());
        case 2: return long2string(pp->getPstrlen());
        case 3: return oppstring2string(pp->getPstr());
        case 4: return long2string(pp->getReserved());
        case 5: return long2string(pp->getInfoHash());
        case 6: return long2string(pp->getPeerId());
        default: return "";
    }
}

bool HandshakeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Handshake *pp = (Handshake *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessageId(string2long(value)); return true;
        case 1: pp->setLength(string2long(value)); return true;
        case 2: pp->setPstrlen(string2long(value)); return true;
        case 3: pp->setPstr((value)); return true;
        case 4: pp->setReserved(string2long(value)); return true;
        case 5: pp->setInfoHash(string2long(value)); return true;
        case 6: pp->setPeerId(string2long(value)); return true;
        default: return false;
    }
}

const char *HandshakeDescriptor::getFieldStructName(int field) const
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

void *HandshakeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Handshake *pp = (Handshake *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


