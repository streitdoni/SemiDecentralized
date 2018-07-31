//
// Generated file, do not edit! Created by nedtool 5.4 from src/routing/AODVQoSControlPackets.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "AODVQoSControlPackets_m.h"

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
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

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

UnreachableNode::UnreachableNode()
{
    this->seqNum = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const UnreachableNode& a)
{
    doParsimPacking(b,a.addr);
    doParsimPacking(b,a.seqNum);
}

void __doUnpacking(omnetpp::cCommBuffer *b, UnreachableNode& a)
{
    doParsimUnpacking(b,a.addr);
    doParsimUnpacking(b,a.seqNum);
}

class UnreachableNodeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UnreachableNodeDescriptor();
    virtual ~UnreachableNodeDescriptor();

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

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(UnreachableNodeDescriptor)

UnreachableNodeDescriptor::UnreachableNodeDescriptor() : omnetpp::cClassDescriptor("inet::UnreachableNode", "")
{
    propertynames = nullptr;
}

UnreachableNodeDescriptor::~UnreachableNodeDescriptor()
{
    delete[] propertynames;
}

bool UnreachableNodeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UnreachableNode *>(obj)!=nullptr;
}

const char **UnreachableNodeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UnreachableNodeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UnreachableNodeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int UnreachableNodeDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *UnreachableNodeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "addr",
        "seqNum",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int UnreachableNodeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addr")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNum")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UnreachableNodeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "unsigned int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **UnreachableNodeDescriptor::getFieldPropertyNames(int field) const
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

const char *UnreachableNodeDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UnreachableNodeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UnreachableNode *pp = (UnreachableNode *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UnreachableNodeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UnreachableNode *pp = (UnreachableNode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UnreachableNodeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UnreachableNode *pp = (UnreachableNode *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->addr; return out.str();}
        case 1: return ulong2string(pp->seqNum);
        default: return "";
    }
}

bool UnreachableNodeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UnreachableNode *pp = (UnreachableNode *)object; (void)pp;
    switch (field) {
        case 1: pp->seqNum = string2ulong(value); return true;
        default: return false;
    }
}

const char *UnreachableNodeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UnreachableNodeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UnreachableNode *pp = (UnreachableNode *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->addr); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::AODVQoSControlPacketType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::AODVQoSControlPacketType"));
    e->insert(RREQ, "RREQ");
    e->insert(RREP, "RREP");
    e->insert(RERR, "RERR");
    e->insert(RREPACK, "RREPACK");
)

Register_Class(AODVQoSControlPacket)

AODVQoSControlPacket::AODVQoSControlPacket(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->packetType = 0;
}

AODVQoSControlPacket::AODVQoSControlPacket(const AODVQoSControlPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

AODVQoSControlPacket::~AODVQoSControlPacket()
{
}

AODVQoSControlPacket& AODVQoSControlPacket::operator=(const AODVQoSControlPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVQoSControlPacket::copy(const AODVQoSControlPacket& other)
{
    this->packetType = other.packetType;
}

void AODVQoSControlPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
}

void AODVQoSControlPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
}

unsigned int AODVQoSControlPacket::getPacketType() const
{
    return this->packetType;
}

void AODVQoSControlPacket::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

class AODVQoSControlPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVQoSControlPacketDescriptor();
    virtual ~AODVQoSControlPacketDescriptor();

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

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVQoSControlPacketDescriptor)

AODVQoSControlPacketDescriptor::AODVQoSControlPacketDescriptor() : omnetpp::cClassDescriptor("inet::AODVQoSControlPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

AODVQoSControlPacketDescriptor::~AODVQoSControlPacketDescriptor()
{
    delete[] propertynames;
}

bool AODVQoSControlPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVQoSControlPacket *>(obj)!=nullptr;
}

const char **AODVQoSControlPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVQoSControlPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVQoSControlPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int AODVQoSControlPacketDescriptor::getFieldTypeFlags(int field) const
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

const char *AODVQoSControlPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int AODVQoSControlPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVQoSControlPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **AODVQoSControlPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *AODVQoSControlPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AODVQoSControlPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVQoSControlPacket *pp = (AODVQoSControlPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AODVQoSControlPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSControlPacket *pp = (AODVQoSControlPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AODVQoSControlPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSControlPacket *pp = (AODVQoSControlPacket *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        default: return "";
    }
}

bool AODVQoSControlPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVQoSControlPacket *pp = (AODVQoSControlPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *AODVQoSControlPacketDescriptor::getFieldStructName(int field) const
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

void *AODVQoSControlPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSControlPacket *pp = (AODVQoSControlPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(AODVQoSRREQ)

AODVQoSRREQ::AODVQoSRREQ(const char *name) : ::inet::AODVQoSControlPacket(name)
{
    this->setPacketType(RREQ);

    this->joinFlag = false;
    this->repairFlag = false;
    this->gratuitousRREPFlag = false;
    this->destOnlyFlag = false;
    this->unknownSeqNumFlag = false;
    this->hopCount = 0;
    this->rreqId = 0;
    this->destSeqNum = 0;
    this->originatorSeqNum = 0;
    this->minAvailableBandwidth = 0;
    this->minAvailableSlotTime = 0;
}

AODVQoSRREQ::AODVQoSRREQ(const AODVQoSRREQ& other) : ::inet::AODVQoSControlPacket(other)
{
    copy(other);
}

AODVQoSRREQ::~AODVQoSRREQ()
{
}

AODVQoSRREQ& AODVQoSRREQ::operator=(const AODVQoSRREQ& other)
{
    if (this==&other) return *this;
    ::inet::AODVQoSControlPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVQoSRREQ::copy(const AODVQoSRREQ& other)
{
    this->joinFlag = other.joinFlag;
    this->repairFlag = other.repairFlag;
    this->gratuitousRREPFlag = other.gratuitousRREPFlag;
    this->destOnlyFlag = other.destOnlyFlag;
    this->unknownSeqNumFlag = other.unknownSeqNumFlag;
    this->hopCount = other.hopCount;
    this->rreqId = other.rreqId;
    this->destAddr = other.destAddr;
    this->destSeqNum = other.destSeqNum;
    this->originatorAddr = other.originatorAddr;
    this->originatorSeqNum = other.originatorSeqNum;
    this->minAvailableBandwidth = other.minAvailableBandwidth;
    this->minAvailableSlotTime = other.minAvailableSlotTime;
}

void AODVQoSRREQ::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::AODVQoSControlPacket::parsimPack(b);
    doParsimPacking(b,this->joinFlag);
    doParsimPacking(b,this->repairFlag);
    doParsimPacking(b,this->gratuitousRREPFlag);
    doParsimPacking(b,this->destOnlyFlag);
    doParsimPacking(b,this->unknownSeqNumFlag);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->rreqId);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->destSeqNum);
    doParsimPacking(b,this->originatorAddr);
    doParsimPacking(b,this->originatorSeqNum);
    doParsimPacking(b,this->minAvailableBandwidth);
    doParsimPacking(b,this->minAvailableSlotTime);
}

void AODVQoSRREQ::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::AODVQoSControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->joinFlag);
    doParsimUnpacking(b,this->repairFlag);
    doParsimUnpacking(b,this->gratuitousRREPFlag);
    doParsimUnpacking(b,this->destOnlyFlag);
    doParsimUnpacking(b,this->unknownSeqNumFlag);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->rreqId);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->destSeqNum);
    doParsimUnpacking(b,this->originatorAddr);
    doParsimUnpacking(b,this->originatorSeqNum);
    doParsimUnpacking(b,this->minAvailableBandwidth);
    doParsimUnpacking(b,this->minAvailableSlotTime);
}

bool AODVQoSRREQ::getJoinFlag() const
{
    return this->joinFlag;
}

void AODVQoSRREQ::setJoinFlag(bool joinFlag)
{
    this->joinFlag = joinFlag;
}

bool AODVQoSRREQ::getRepairFlag() const
{
    return this->repairFlag;
}

void AODVQoSRREQ::setRepairFlag(bool repairFlag)
{
    this->repairFlag = repairFlag;
}

bool AODVQoSRREQ::getGratuitousRREPFlag() const
{
    return this->gratuitousRREPFlag;
}

void AODVQoSRREQ::setGratuitousRREPFlag(bool gratuitousRREPFlag)
{
    this->gratuitousRREPFlag = gratuitousRREPFlag;
}

bool AODVQoSRREQ::getDestOnlyFlag() const
{
    return this->destOnlyFlag;
}

void AODVQoSRREQ::setDestOnlyFlag(bool destOnlyFlag)
{
    this->destOnlyFlag = destOnlyFlag;
}

bool AODVQoSRREQ::getUnknownSeqNumFlag() const
{
    return this->unknownSeqNumFlag;
}

void AODVQoSRREQ::setUnknownSeqNumFlag(bool unknownSeqNumFlag)
{
    this->unknownSeqNumFlag = unknownSeqNumFlag;
}

unsigned int AODVQoSRREQ::getHopCount() const
{
    return this->hopCount;
}

void AODVQoSRREQ::setHopCount(unsigned int hopCount)
{
    this->hopCount = hopCount;
}

unsigned int AODVQoSRREQ::getRreqId() const
{
    return this->rreqId;
}

void AODVQoSRREQ::setRreqId(unsigned int rreqId)
{
    this->rreqId = rreqId;
}

L3Address& AODVQoSRREQ::getDestAddr()
{
    return this->destAddr;
}

void AODVQoSRREQ::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

unsigned int AODVQoSRREQ::getDestSeqNum() const
{
    return this->destSeqNum;
}

void AODVQoSRREQ::setDestSeqNum(unsigned int destSeqNum)
{
    this->destSeqNum = destSeqNum;
}

L3Address& AODVQoSRREQ::getOriginatorAddr()
{
    return this->originatorAddr;
}

void AODVQoSRREQ::setOriginatorAddr(const L3Address& originatorAddr)
{
    this->originatorAddr = originatorAddr;
}

unsigned int AODVQoSRREQ::getOriginatorSeqNum() const
{
    return this->originatorSeqNum;
}

void AODVQoSRREQ::setOriginatorSeqNum(unsigned int originatorSeqNum)
{
    this->originatorSeqNum = originatorSeqNum;
}

double AODVQoSRREQ::getMinAvailableBandwidth() const
{
    return this->minAvailableBandwidth;
}

void AODVQoSRREQ::setMinAvailableBandwidth(double minAvailableBandwidth)
{
    this->minAvailableBandwidth = minAvailableBandwidth;
}

double AODVQoSRREQ::getMinAvailableSlotTime() const
{
    return this->minAvailableSlotTime;
}

void AODVQoSRREQ::setMinAvailableSlotTime(double minAvailableSlotTime)
{
    this->minAvailableSlotTime = minAvailableSlotTime;
}

class AODVQoSRREQDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVQoSRREQDescriptor();
    virtual ~AODVQoSRREQDescriptor();

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

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVQoSRREQDescriptor)

AODVQoSRREQDescriptor::AODVQoSRREQDescriptor() : omnetpp::cClassDescriptor("inet::AODVQoSRREQ", "inet::AODVQoSControlPacket")
{
    propertynames = nullptr;
}

AODVQoSRREQDescriptor::~AODVQoSRREQDescriptor()
{
    delete[] propertynames;
}

bool AODVQoSRREQDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVQoSRREQ *>(obj)!=nullptr;
}

const char **AODVQoSRREQDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVQoSRREQDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVQoSRREQDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 13+basedesc->getFieldCount() : 13;
}

unsigned int AODVQoSRREQDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<13) ? fieldTypeFlags[field] : 0;
}

const char *AODVQoSRREQDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "joinFlag",
        "repairFlag",
        "gratuitousRREPFlag",
        "destOnlyFlag",
        "unknownSeqNumFlag",
        "hopCount",
        "rreqId",
        "destAddr",
        "destSeqNum",
        "originatorAddr",
        "originatorSeqNum",
        "minAvailableBandwidth",
        "minAvailableSlotTime",
    };
    return (field>=0 && field<13) ? fieldNames[field] : nullptr;
}

int AODVQoSRREQDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='j' && strcmp(fieldName, "joinFlag")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "repairFlag")==0) return base+1;
    if (fieldName[0]=='g' && strcmp(fieldName, "gratuitousRREPFlag")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destOnlyFlag")==0) return base+3;
    if (fieldName[0]=='u' && strcmp(fieldName, "unknownSeqNumFlag")==0) return base+4;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "rreqId")==0) return base+6;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+7;
    if (fieldName[0]=='d' && strcmp(fieldName, "destSeqNum")==0) return base+8;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorAddr")==0) return base+9;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorSeqNum")==0) return base+10;
    if (fieldName[0]=='m' && strcmp(fieldName, "minAvailableBandwidth")==0) return base+11;
    if (fieldName[0]=='m' && strcmp(fieldName, "minAvailableSlotTime")==0) return base+12;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVQoSRREQDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "unsigned int",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "double",
        "double",
    };
    return (field>=0 && field<13) ? fieldTypeStrings[field] : nullptr;
}

const char **AODVQoSRREQDescriptor::getFieldPropertyNames(int field) const
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

const char *AODVQoSRREQDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AODVQoSRREQDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREQ *pp = (AODVQoSRREQ *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AODVQoSRREQDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREQ *pp = (AODVQoSRREQ *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AODVQoSRREQDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREQ *pp = (AODVQoSRREQ *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getJoinFlag());
        case 1: return bool2string(pp->getRepairFlag());
        case 2: return bool2string(pp->getGratuitousRREPFlag());
        case 3: return bool2string(pp->getDestOnlyFlag());
        case 4: return bool2string(pp->getUnknownSeqNumFlag());
        case 5: return ulong2string(pp->getHopCount());
        case 6: return ulong2string(pp->getRreqId());
        case 7: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 8: return ulong2string(pp->getDestSeqNum());
        case 9: {std::stringstream out; out << pp->getOriginatorAddr(); return out.str();}
        case 10: return ulong2string(pp->getOriginatorSeqNum());
        case 11: return double2string(pp->getMinAvailableBandwidth());
        case 12: return double2string(pp->getMinAvailableSlotTime());
        default: return "";
    }
}

bool AODVQoSRREQDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREQ *pp = (AODVQoSRREQ *)object; (void)pp;
    switch (field) {
        case 0: pp->setJoinFlag(string2bool(value)); return true;
        case 1: pp->setRepairFlag(string2bool(value)); return true;
        case 2: pp->setGratuitousRREPFlag(string2bool(value)); return true;
        case 3: pp->setDestOnlyFlag(string2bool(value)); return true;
        case 4: pp->setUnknownSeqNumFlag(string2bool(value)); return true;
        case 5: pp->setHopCount(string2ulong(value)); return true;
        case 6: pp->setRreqId(string2ulong(value)); return true;
        case 8: pp->setDestSeqNum(string2ulong(value)); return true;
        case 10: pp->setOriginatorSeqNum(string2ulong(value)); return true;
        case 11: pp->setMinAvailableBandwidth(string2double(value)); return true;
        case 12: pp->setMinAvailableSlotTime(string2double(value)); return true;
        default: return false;
    }
}

const char *AODVQoSRREQDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 7: return omnetpp::opp_typename(typeid(L3Address));
        case 9: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *AODVQoSRREQDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREQ *pp = (AODVQoSRREQ *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getDestAddr()); break;
        case 9: return (void *)(&pp->getOriginatorAddr()); break;
        default: return nullptr;
    }
}

Register_Class(AODVQoSRREP)

AODVQoSRREP::AODVQoSRREP(const char *name) : ::inet::AODVQoSControlPacket(name)
{
    this->setPacketType(RREP);

    this->repairFlag = false;
    this->ackRequiredFlag = false;
    this->prefixSize = 0;
    this->hopCount = 0;
    this->destSeqNum = 0;
    this->originatorSeqNum = 0;
    this->lifeTime = 0;
    this->totalHopsToDest = 0;
}

AODVQoSRREP::AODVQoSRREP(const AODVQoSRREP& other) : ::inet::AODVQoSControlPacket(other)
{
    copy(other);
}

AODVQoSRREP::~AODVQoSRREP()
{
}

AODVQoSRREP& AODVQoSRREP::operator=(const AODVQoSRREP& other)
{
    if (this==&other) return *this;
    ::inet::AODVQoSControlPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVQoSRREP::copy(const AODVQoSRREP& other)
{
    this->repairFlag = other.repairFlag;
    this->ackRequiredFlag = other.ackRequiredFlag;
    this->prefixSize = other.prefixSize;
    this->hopCount = other.hopCount;
    this->destAddr = other.destAddr;
    this->destSeqNum = other.destSeqNum;
    this->originatorAddr = other.originatorAddr;
    this->originatorSeqNum = other.originatorSeqNum;
    this->lifeTime = other.lifeTime;
    this->totalHopsToDest = other.totalHopsToDest;
}

void AODVQoSRREP::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::AODVQoSControlPacket::parsimPack(b);
    doParsimPacking(b,this->repairFlag);
    doParsimPacking(b,this->ackRequiredFlag);
    doParsimPacking(b,this->prefixSize);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->destSeqNum);
    doParsimPacking(b,this->originatorAddr);
    doParsimPacking(b,this->originatorSeqNum);
    doParsimPacking(b,this->lifeTime);
    doParsimPacking(b,this->totalHopsToDest);
}

void AODVQoSRREP::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::AODVQoSControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->repairFlag);
    doParsimUnpacking(b,this->ackRequiredFlag);
    doParsimUnpacking(b,this->prefixSize);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->destSeqNum);
    doParsimUnpacking(b,this->originatorAddr);
    doParsimUnpacking(b,this->originatorSeqNum);
    doParsimUnpacking(b,this->lifeTime);
    doParsimUnpacking(b,this->totalHopsToDest);
}

bool AODVQoSRREP::getRepairFlag() const
{
    return this->repairFlag;
}

void AODVQoSRREP::setRepairFlag(bool repairFlag)
{
    this->repairFlag = repairFlag;
}

bool AODVQoSRREP::getAckRequiredFlag() const
{
    return this->ackRequiredFlag;
}

void AODVQoSRREP::setAckRequiredFlag(bool ackRequiredFlag)
{
    this->ackRequiredFlag = ackRequiredFlag;
}

unsigned int AODVQoSRREP::getPrefixSize() const
{
    return this->prefixSize;
}

void AODVQoSRREP::setPrefixSize(unsigned int prefixSize)
{
    this->prefixSize = prefixSize;
}

unsigned int AODVQoSRREP::getHopCount() const
{
    return this->hopCount;
}

void AODVQoSRREP::setHopCount(unsigned int hopCount)
{
    this->hopCount = hopCount;
}

L3Address& AODVQoSRREP::getDestAddr()
{
    return this->destAddr;
}

void AODVQoSRREP::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

unsigned int AODVQoSRREP::getDestSeqNum() const
{
    return this->destSeqNum;
}

void AODVQoSRREP::setDestSeqNum(unsigned int destSeqNum)
{
    this->destSeqNum = destSeqNum;
}

L3Address& AODVQoSRREP::getOriginatorAddr()
{
    return this->originatorAddr;
}

void AODVQoSRREP::setOriginatorAddr(const L3Address& originatorAddr)
{
    this->originatorAddr = originatorAddr;
}

unsigned int AODVQoSRREP::getOriginatorSeqNum() const
{
    return this->originatorSeqNum;
}

void AODVQoSRREP::setOriginatorSeqNum(unsigned int originatorSeqNum)
{
    this->originatorSeqNum = originatorSeqNum;
}

::omnetpp::simtime_t AODVQoSRREP::getLifeTime() const
{
    return this->lifeTime;
}

void AODVQoSRREP::setLifeTime(::omnetpp::simtime_t lifeTime)
{
    this->lifeTime = lifeTime;
}

int AODVQoSRREP::getTotalHopsToDest() const
{
    return this->totalHopsToDest;
}

void AODVQoSRREP::setTotalHopsToDest(int totalHopsToDest)
{
    this->totalHopsToDest = totalHopsToDest;
}

class AODVQoSRREPDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVQoSRREPDescriptor();
    virtual ~AODVQoSRREPDescriptor();

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

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVQoSRREPDescriptor)

AODVQoSRREPDescriptor::AODVQoSRREPDescriptor() : omnetpp::cClassDescriptor("inet::AODVQoSRREP", "inet::AODVQoSControlPacket")
{
    propertynames = nullptr;
}

AODVQoSRREPDescriptor::~AODVQoSRREPDescriptor()
{
    delete[] propertynames;
}

bool AODVQoSRREPDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVQoSRREP *>(obj)!=nullptr;
}

const char **AODVQoSRREPDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVQoSRREPDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVQoSRREPDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int AODVQoSRREPDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *AODVQoSRREPDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "repairFlag",
        "ackRequiredFlag",
        "prefixSize",
        "hopCount",
        "destAddr",
        "destSeqNum",
        "originatorAddr",
        "originatorSeqNum",
        "lifeTime",
        "totalHopsToDest",
    };
    return (field>=0 && field<10) ? fieldNames[field] : nullptr;
}

int AODVQoSRREPDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "repairFlag")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackRequiredFlag")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixSize")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "destSeqNum")==0) return base+5;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorAddr")==0) return base+6;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorSeqNum")==0) return base+7;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifeTime")==0) return base+8;
    if (fieldName[0]=='t' && strcmp(fieldName, "totalHopsToDest")==0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVQoSRREPDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "unsigned int",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "simtime_t",
        "int",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : nullptr;
}

const char **AODVQoSRREPDescriptor::getFieldPropertyNames(int field) const
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

const char *AODVQoSRREPDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AODVQoSRREPDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREP *pp = (AODVQoSRREP *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AODVQoSRREPDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREP *pp = (AODVQoSRREP *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AODVQoSRREPDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREP *pp = (AODVQoSRREP *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getRepairFlag());
        case 1: return bool2string(pp->getAckRequiredFlag());
        case 2: return ulong2string(pp->getPrefixSize());
        case 3: return ulong2string(pp->getHopCount());
        case 4: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 5: return ulong2string(pp->getDestSeqNum());
        case 6: {std::stringstream out; out << pp->getOriginatorAddr(); return out.str();}
        case 7: return ulong2string(pp->getOriginatorSeqNum());
        case 8: return simtime2string(pp->getLifeTime());
        case 9: return long2string(pp->getTotalHopsToDest());
        default: return "";
    }
}

bool AODVQoSRREPDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREP *pp = (AODVQoSRREP *)object; (void)pp;
    switch (field) {
        case 0: pp->setRepairFlag(string2bool(value)); return true;
        case 1: pp->setAckRequiredFlag(string2bool(value)); return true;
        case 2: pp->setPrefixSize(string2ulong(value)); return true;
        case 3: pp->setHopCount(string2ulong(value)); return true;
        case 5: pp->setDestSeqNum(string2ulong(value)); return true;
        case 7: pp->setOriginatorSeqNum(string2ulong(value)); return true;
        case 8: pp->setLifeTime(string2simtime(value)); return true;
        case 9: pp->setTotalHopsToDest(string2long(value)); return true;
        default: return false;
    }
}

const char *AODVQoSRREPDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: return omnetpp::opp_typename(typeid(L3Address));
        case 6: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *AODVQoSRREPDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREP *pp = (AODVQoSRREP *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getDestAddr()); break;
        case 6: return (void *)(&pp->getOriginatorAddr()); break;
        default: return nullptr;
    }
}

Register_Class(AODVQoSRERR)

AODVQoSRERR::AODVQoSRERR(const char *name) : ::inet::AODVQoSControlPacket(name)
{
    this->setPacketType(RERR);

    unreachableNodes_arraysize = 0;
    this->unreachableNodes = 0;
    this->noDeleteFlag = false;
    this->destCount = 0;
}

AODVQoSRERR::AODVQoSRERR(const AODVQoSRERR& other) : ::inet::AODVQoSControlPacket(other)
{
    unreachableNodes_arraysize = 0;
    this->unreachableNodes = 0;
    copy(other);
}

AODVQoSRERR::~AODVQoSRERR()
{
    delete [] this->unreachableNodes;
}

AODVQoSRERR& AODVQoSRERR::operator=(const AODVQoSRERR& other)
{
    if (this==&other) return *this;
    ::inet::AODVQoSControlPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVQoSRERR::copy(const AODVQoSRERR& other)
{
    delete [] this->unreachableNodes;
    this->unreachableNodes = (other.unreachableNodes_arraysize==0) ? nullptr : new UnreachableNode[other.unreachableNodes_arraysize];
    unreachableNodes_arraysize = other.unreachableNodes_arraysize;
    for (unsigned int i=0; i<unreachableNodes_arraysize; i++)
        this->unreachableNodes[i] = other.unreachableNodes[i];
    this->noDeleteFlag = other.noDeleteFlag;
    this->destCount = other.destCount;
}

void AODVQoSRERR::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::AODVQoSControlPacket::parsimPack(b);
    b->pack(unreachableNodes_arraysize);
    doParsimArrayPacking(b,this->unreachableNodes,unreachableNodes_arraysize);
    doParsimPacking(b,this->noDeleteFlag);
    doParsimPacking(b,this->destCount);
}

void AODVQoSRERR::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::AODVQoSControlPacket::parsimUnpack(b);
    delete [] this->unreachableNodes;
    b->unpack(unreachableNodes_arraysize);
    if (unreachableNodes_arraysize==0) {
        this->unreachableNodes = 0;
    } else {
        this->unreachableNodes = new UnreachableNode[unreachableNodes_arraysize];
        doParsimArrayUnpacking(b,this->unreachableNodes,unreachableNodes_arraysize);
    }
    doParsimUnpacking(b,this->noDeleteFlag);
    doParsimUnpacking(b,this->destCount);
}

void AODVQoSRERR::setUnreachableNodesArraySize(unsigned int size)
{
    UnreachableNode *unreachableNodes2 = (size==0) ? nullptr : new UnreachableNode[size];
    unsigned int sz = unreachableNodes_arraysize < size ? unreachableNodes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unreachableNodes2[i] = this->unreachableNodes[i];
    unreachableNodes_arraysize = size;
    delete [] this->unreachableNodes;
    this->unreachableNodes = unreachableNodes2;
}

unsigned int AODVQoSRERR::getUnreachableNodesArraySize() const
{
    return unreachableNodes_arraysize;
}

UnreachableNode& AODVQoSRERR::getUnreachableNodes(unsigned int k)
{
    if (k>=unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unreachableNodes_arraysize, k);
    return this->unreachableNodes[k];
}

void AODVQoSRERR::setUnreachableNodes(unsigned int k, const UnreachableNode& unreachableNodes)
{
    if (k>=unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unreachableNodes_arraysize, k);
    this->unreachableNodes[k] = unreachableNodes;
}

bool AODVQoSRERR::getNoDeleteFlag() const
{
    return this->noDeleteFlag;
}

void AODVQoSRERR::setNoDeleteFlag(bool noDeleteFlag)
{
    this->noDeleteFlag = noDeleteFlag;
}

unsigned int AODVQoSRERR::getDestCount() const
{
    return this->destCount;
}

void AODVQoSRERR::setDestCount(unsigned int destCount)
{
    this->destCount = destCount;
}

class AODVQoSRERRDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVQoSRERRDescriptor();
    virtual ~AODVQoSRERRDescriptor();

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

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVQoSRERRDescriptor)

AODVQoSRERRDescriptor::AODVQoSRERRDescriptor() : omnetpp::cClassDescriptor("inet::AODVQoSRERR", "inet::AODVQoSControlPacket")
{
    propertynames = nullptr;
}

AODVQoSRERRDescriptor::~AODVQoSRERRDescriptor()
{
    delete[] propertynames;
}

bool AODVQoSRERRDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVQoSRERR *>(obj)!=nullptr;
}

const char **AODVQoSRERRDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVQoSRERRDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVQoSRERRDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int AODVQoSRERRDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *AODVQoSRERRDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "unreachableNodes",
        "noDeleteFlag",
        "destCount",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int AODVQoSRERRDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='u' && strcmp(fieldName, "unreachableNodes")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "noDeleteFlag")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destCount")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVQoSRERRDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "UnreachableNode",
        "bool",
        "unsigned int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **AODVQoSRERRDescriptor::getFieldPropertyNames(int field) const
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

const char *AODVQoSRERRDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AODVQoSRERRDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRERR *pp = (AODVQoSRERR *)object; (void)pp;
    switch (field) {
        case 0: return pp->getUnreachableNodesArraySize();
        default: return 0;
    }
}

const char *AODVQoSRERRDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRERR *pp = (AODVQoSRERR *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AODVQoSRERRDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRERR *pp = (AODVQoSRERR *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getUnreachableNodes(i); return out.str();}
        case 1: return bool2string(pp->getNoDeleteFlag());
        case 2: return ulong2string(pp->getDestCount());
        default: return "";
    }
}

bool AODVQoSRERRDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRERR *pp = (AODVQoSRERR *)object; (void)pp;
    switch (field) {
        case 1: pp->setNoDeleteFlag(string2bool(value)); return true;
        case 2: pp->setDestCount(string2ulong(value)); return true;
        default: return false;
    }
}

const char *AODVQoSRERRDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(UnreachableNode));
        default: return nullptr;
    };
}

void *AODVQoSRERRDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRERR *pp = (AODVQoSRERR *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getUnreachableNodes(i)); break;
        default: return nullptr;
    }
}

Register_Class(AODVQoSRREPACK)

AODVQoSRREPACK::AODVQoSRREPACK(const char *name) : ::inet::AODVQoSControlPacket(name)
{
    this->setPacketType(RREPACK);
}

AODVQoSRREPACK::AODVQoSRREPACK(const AODVQoSRREPACK& other) : ::inet::AODVQoSControlPacket(other)
{
    copy(other);
}

AODVQoSRREPACK::~AODVQoSRREPACK()
{
}

AODVQoSRREPACK& AODVQoSRREPACK::operator=(const AODVQoSRREPACK& other)
{
    if (this==&other) return *this;
    ::inet::AODVQoSControlPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVQoSRREPACK::copy(const AODVQoSRREPACK& other)
{
}

void AODVQoSRREPACK::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::AODVQoSControlPacket::parsimPack(b);
}

void AODVQoSRREPACK::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::AODVQoSControlPacket::parsimUnpack(b);
}

class AODVQoSRREPACKDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVQoSRREPACKDescriptor();
    virtual ~AODVQoSRREPACKDescriptor();

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

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVQoSRREPACKDescriptor)

AODVQoSRREPACKDescriptor::AODVQoSRREPACKDescriptor() : omnetpp::cClassDescriptor("inet::AODVQoSRREPACK", "inet::AODVQoSControlPacket")
{
    propertynames = nullptr;
}

AODVQoSRREPACKDescriptor::~AODVQoSRREPACKDescriptor()
{
    delete[] propertynames;
}

bool AODVQoSRREPACKDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVQoSRREPACK *>(obj)!=nullptr;
}

const char **AODVQoSRREPACKDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVQoSRREPACKDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVQoSRREPACKDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int AODVQoSRREPACKDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *AODVQoSRREPACKDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int AODVQoSRREPACKDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVQoSRREPACKDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **AODVQoSRREPACKDescriptor::getFieldPropertyNames(int field) const
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

const char *AODVQoSRREPACKDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AODVQoSRREPACKDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREPACK *pp = (AODVQoSRREPACK *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AODVQoSRREPACKDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREPACK *pp = (AODVQoSRREPACK *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AODVQoSRREPACKDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREPACK *pp = (AODVQoSRREPACK *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool AODVQoSRREPACKDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREPACK *pp = (AODVQoSRREPACK *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *AODVQoSRREPACKDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *AODVQoSRREPACKDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVQoSRREPACK *pp = (AODVQoSRREPACK *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(WaitForQoSRREP)

WaitForQoSRREP::WaitForQoSRREP(const char *name, short kind) : ::omnetpp::cMessage(name,kind)
{
    this->lastTTL = 0;
    this->fromInvalidEntry = false;
    this->minAvailableBandwidth = 0;
    this->minAvailableSlotTime = 0;
}

WaitForQoSRREP::WaitForQoSRREP(const WaitForQoSRREP& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

WaitForQoSRREP::~WaitForQoSRREP()
{
}

WaitForQoSRREP& WaitForQoSRREP::operator=(const WaitForQoSRREP& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void WaitForQoSRREP::copy(const WaitForQoSRREP& other)
{
    this->destAddr = other.destAddr;
    this->lastTTL = other.lastTTL;
    this->fromInvalidEntry = other.fromInvalidEntry;
    this->minAvailableBandwidth = other.minAvailableBandwidth;
    this->minAvailableSlotTime = other.minAvailableSlotTime;
}

void WaitForQoSRREP::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->lastTTL);
    doParsimPacking(b,this->fromInvalidEntry);
    doParsimPacking(b,this->minAvailableBandwidth);
    doParsimPacking(b,this->minAvailableSlotTime);
}

void WaitForQoSRREP::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->lastTTL);
    doParsimUnpacking(b,this->fromInvalidEntry);
    doParsimUnpacking(b,this->minAvailableBandwidth);
    doParsimUnpacking(b,this->minAvailableSlotTime);
}

L3Address& WaitForQoSRREP::getDestAddr()
{
    return this->destAddr;
}

void WaitForQoSRREP::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

unsigned int WaitForQoSRREP::getLastTTL() const
{
    return this->lastTTL;
}

void WaitForQoSRREP::setLastTTL(unsigned int lastTTL)
{
    this->lastTTL = lastTTL;
}

bool WaitForQoSRREP::getFromInvalidEntry() const
{
    return this->fromInvalidEntry;
}

void WaitForQoSRREP::setFromInvalidEntry(bool fromInvalidEntry)
{
    this->fromInvalidEntry = fromInvalidEntry;
}

double WaitForQoSRREP::getMinAvailableBandwidth() const
{
    return this->minAvailableBandwidth;
}

void WaitForQoSRREP::setMinAvailableBandwidth(double minAvailableBandwidth)
{
    this->minAvailableBandwidth = minAvailableBandwidth;
}

double WaitForQoSRREP::getMinAvailableSlotTime() const
{
    return this->minAvailableSlotTime;
}

void WaitForQoSRREP::setMinAvailableSlotTime(double minAvailableSlotTime)
{
    this->minAvailableSlotTime = minAvailableSlotTime;
}

class WaitForQoSRREPDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    WaitForQoSRREPDescriptor();
    virtual ~WaitForQoSRREPDescriptor();

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

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(WaitForQoSRREPDescriptor)

WaitForQoSRREPDescriptor::WaitForQoSRREPDescriptor() : omnetpp::cClassDescriptor("inet::WaitForQoSRREP", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

WaitForQoSRREPDescriptor::~WaitForQoSRREPDescriptor()
{
    delete[] propertynames;
}

bool WaitForQoSRREPDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<WaitForQoSRREP *>(obj)!=nullptr;
}

const char **WaitForQoSRREPDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *WaitForQoSRREPDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int WaitForQoSRREPDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int WaitForQoSRREPDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *WaitForQoSRREPDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "destAddr",
        "lastTTL",
        "fromInvalidEntry",
        "minAvailableBandwidth",
        "minAvailableSlotTime",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int WaitForQoSRREPDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastTTL")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "fromInvalidEntry")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "minAvailableBandwidth")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "minAvailableSlotTime")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *WaitForQoSRREPDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "unsigned int",
        "bool",
        "double",
        "double",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **WaitForQoSRREPDescriptor::getFieldPropertyNames(int field) const
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

const char *WaitForQoSRREPDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int WaitForQoSRREPDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    WaitForQoSRREP *pp = (WaitForQoSRREP *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *WaitForQoSRREPDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    WaitForQoSRREP *pp = (WaitForQoSRREP *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string WaitForQoSRREPDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    WaitForQoSRREP *pp = (WaitForQoSRREP *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 1: return ulong2string(pp->getLastTTL());
        case 2: return bool2string(pp->getFromInvalidEntry());
        case 3: return double2string(pp->getMinAvailableBandwidth());
        case 4: return double2string(pp->getMinAvailableSlotTime());
        default: return "";
    }
}

bool WaitForQoSRREPDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    WaitForQoSRREP *pp = (WaitForQoSRREP *)object; (void)pp;
    switch (field) {
        case 1: pp->setLastTTL(string2ulong(value)); return true;
        case 2: pp->setFromInvalidEntry(string2bool(value)); return true;
        case 3: pp->setMinAvailableBandwidth(string2double(value)); return true;
        case 4: pp->setMinAvailableSlotTime(string2double(value)); return true;
        default: return false;
    }
}

const char *WaitForQoSRREPDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *WaitForQoSRREPDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    WaitForQoSRREP *pp = (WaitForQoSRREP *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getDestAddr()); break;
        default: return nullptr;
    }
}

} // namespace inet

