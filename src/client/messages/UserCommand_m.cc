//
// Generated file, do not edit! Created by nedtool 5.0 from client/messages/UserCommand.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "UserCommand_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("UserCommandKind");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("UserCommandKind"));
    e->insert(USER_COMMAND_ENTER_SWARM, "USER_COMMAND_ENTER_SWARM");
    e->insert(USER_COMMAND_LEAVE_SWARM, "USER_COMMAND_LEAVE_SWARM");
);

Register_Class(UserCommand);

UserCommand::UserCommand() : ::omnetpp::cObject()
{
}

UserCommand::UserCommand(const UserCommand& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

UserCommand::~UserCommand()
{
}

UserCommand& UserCommand::operator=(const UserCommand& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void UserCommand::copy(const UserCommand& other)
{
}

void UserCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
}

void UserCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
}

class UserCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UserCommandDescriptor();
    virtual ~UserCommandDescriptor();

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

Register_ClassDescriptor(UserCommandDescriptor);

UserCommandDescriptor::UserCommandDescriptor() : omnetpp::cClassDescriptor("UserCommand", "omnetpp::cObject")
{
    propertynames = nullptr;
}

UserCommandDescriptor::~UserCommandDescriptor()
{
    delete[] propertynames;
}

bool UserCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UserCommand *>(obj)!=nullptr;
}

const char **UserCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UserCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UserCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int UserCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *UserCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int UserCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UserCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **UserCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UserCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UserCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UserCommand *pp = (UserCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UserCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UserCommand *pp = (UserCommand *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool UserCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UserCommand *pp = (UserCommand *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *UserCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *UserCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UserCommand *pp = (UserCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(EnterSwarmCommand);

EnterSwarmCommand::EnterSwarmCommand() : ::UserCommand()
{
    this->seeder = false;
    this->trackerPort = 0;
}

EnterSwarmCommand::EnterSwarmCommand(const EnterSwarmCommand& other) : ::UserCommand(other)
{
    copy(other);
}

EnterSwarmCommand::~EnterSwarmCommand()
{
}

EnterSwarmCommand& EnterSwarmCommand::operator=(const EnterSwarmCommand& other)
{
    if (this==&other) return *this;
    ::UserCommand::operator=(other);
    copy(other);
    return *this;
}

void EnterSwarmCommand::copy(const EnterSwarmCommand& other)
{
    this->torrentMetadata = other.torrentMetadata;
    this->seeder = other.seeder;
    this->trackerAddress = other.trackerAddress;
    this->trackerPort = other.trackerPort;
}

void EnterSwarmCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::UserCommand::parsimPack(b);
    doParsimPacking(b,this->torrentMetadata);
    doParsimPacking(b,this->seeder);
    doParsimPacking(b,this->trackerAddress);
    doParsimPacking(b,this->trackerPort);
}

void EnterSwarmCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::UserCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->torrentMetadata);
    doParsimUnpacking(b,this->seeder);
    doParsimUnpacking(b,this->trackerAddress);
    doParsimUnpacking(b,this->trackerPort);
}

TorrentMetadata& EnterSwarmCommand::getTorrentMetadata()
{
    return this->torrentMetadata;
}

void EnterSwarmCommand::setTorrentMetadata(const TorrentMetadata& torrentMetadata)
{
    this->torrentMetadata = torrentMetadata;
}

bool EnterSwarmCommand::getSeeder() const
{
    return this->seeder;
}

void EnterSwarmCommand::setSeeder(bool seeder)
{
    this->seeder = seeder;
}

IPvXAddress& EnterSwarmCommand::getTrackerAddress()
{
    return this->trackerAddress;
}

void EnterSwarmCommand::setTrackerAddress(const IPvXAddress& trackerAddress)
{
    this->trackerAddress = trackerAddress;
}

int EnterSwarmCommand::getTrackerPort() const
{
    return this->trackerPort;
}

void EnterSwarmCommand::setTrackerPort(int trackerPort)
{
    this->trackerPort = trackerPort;
}

class EnterSwarmCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EnterSwarmCommandDescriptor();
    virtual ~EnterSwarmCommandDescriptor();

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

Register_ClassDescriptor(EnterSwarmCommandDescriptor);

EnterSwarmCommandDescriptor::EnterSwarmCommandDescriptor() : omnetpp::cClassDescriptor("EnterSwarmCommand", "UserCommand")
{
    propertynames = nullptr;
}

EnterSwarmCommandDescriptor::~EnterSwarmCommandDescriptor()
{
    delete[] propertynames;
}

bool EnterSwarmCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EnterSwarmCommand *>(obj)!=nullptr;
}

const char **EnterSwarmCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EnterSwarmCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EnterSwarmCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int EnterSwarmCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *EnterSwarmCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "torrentMetadata",
        "seeder",
        "trackerAddress",
        "trackerPort",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int EnterSwarmCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "torrentMetadata")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "seeder")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "trackerAddress")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "trackerPort")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EnterSwarmCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "TorrentMetadata",
        "bool",
        "IPvXAddress",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **EnterSwarmCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *EnterSwarmCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EnterSwarmCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EnterSwarmCommand *pp = (EnterSwarmCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EnterSwarmCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EnterSwarmCommand *pp = (EnterSwarmCommand *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getTorrentMetadata(); return out.str();}
        case 1: return bool2string(pp->getSeeder());
        case 2: {std::stringstream out; out << pp->getTrackerAddress(); return out.str();}
        case 3: return long2string(pp->getTrackerPort());
        default: return "";
    }
}

bool EnterSwarmCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EnterSwarmCommand *pp = (EnterSwarmCommand *)object; (void)pp;
    switch (field) {
        case 1: pp->setSeeder(string2bool(value)); return true;
        case 3: pp->setTrackerPort(string2long(value)); return true;
        default: return false;
    }
}

const char *EnterSwarmCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(TorrentMetadata));
        case 2: return omnetpp::opp_typename(typeid(IPvXAddress));
        default: return nullptr;
    };
}

void *EnterSwarmCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EnterSwarmCommand *pp = (EnterSwarmCommand *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getTorrentMetadata()); break;
        case 2: return (void *)(&pp->getTrackerAddress()); break;
        default: return nullptr;
    }
}

Register_Class(LeaveSwarmCommand);

LeaveSwarmCommand::LeaveSwarmCommand() : ::UserCommand()
{
    this->infoHash = 0;
}

LeaveSwarmCommand::LeaveSwarmCommand(const LeaveSwarmCommand& other) : ::UserCommand(other)
{
    copy(other);
}

LeaveSwarmCommand::~LeaveSwarmCommand()
{
}

LeaveSwarmCommand& LeaveSwarmCommand::operator=(const LeaveSwarmCommand& other)
{
    if (this==&other) return *this;
    ::UserCommand::operator=(other);
    copy(other);
    return *this;
}

void LeaveSwarmCommand::copy(const LeaveSwarmCommand& other)
{
    this->infoHash = other.infoHash;
}

void LeaveSwarmCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::UserCommand::parsimPack(b);
    doParsimPacking(b,this->infoHash);
}

void LeaveSwarmCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::UserCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->infoHash);
}

int LeaveSwarmCommand::getInfoHash() const
{
    return this->infoHash;
}

void LeaveSwarmCommand::setInfoHash(int infoHash)
{
    this->infoHash = infoHash;
}

class LeaveSwarmCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LeaveSwarmCommandDescriptor();
    virtual ~LeaveSwarmCommandDescriptor();

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

Register_ClassDescriptor(LeaveSwarmCommandDescriptor);

LeaveSwarmCommandDescriptor::LeaveSwarmCommandDescriptor() : omnetpp::cClassDescriptor("LeaveSwarmCommand", "UserCommand")
{
    propertynames = nullptr;
}

LeaveSwarmCommandDescriptor::~LeaveSwarmCommandDescriptor()
{
    delete[] propertynames;
}

bool LeaveSwarmCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LeaveSwarmCommand *>(obj)!=nullptr;
}

const char **LeaveSwarmCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LeaveSwarmCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LeaveSwarmCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int LeaveSwarmCommandDescriptor::getFieldTypeFlags(int field) const
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

const char *LeaveSwarmCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "infoHash",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int LeaveSwarmCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "infoHash")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LeaveSwarmCommandDescriptor::getFieldTypeString(int field) const
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

const char **LeaveSwarmCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *LeaveSwarmCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LeaveSwarmCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LeaveSwarmCommand *pp = (LeaveSwarmCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string LeaveSwarmCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LeaveSwarmCommand *pp = (LeaveSwarmCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getInfoHash());
        default: return "";
    }
}

bool LeaveSwarmCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LeaveSwarmCommand *pp = (LeaveSwarmCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setInfoHash(string2long(value)); return true;
        default: return false;
    }
}

const char *LeaveSwarmCommandDescriptor::getFieldStructName(int field) const
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

void *LeaveSwarmCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LeaveSwarmCommand *pp = (LeaveSwarmCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


