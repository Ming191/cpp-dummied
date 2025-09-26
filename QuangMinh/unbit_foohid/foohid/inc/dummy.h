#ifndef DUMMY_H
#define DUMMY_H

#include <cstdint>
#include <cstddef>
#include <cstring>

//-------------------------//
// Typedefs & constants
//-------------------------//
typedef uint8_t   UInt8;
typedef uint16_t  UInt16;
typedef uint32_t  UInt32;
typedef uint64_t  UInt64;
typedef int8_t    SInt8;
typedef int16_t   SInt16;
typedef int32_t   SInt32;
typedef int64_t   SInt64;

typedef uint32_t IOOptionBits;
typedef int IOReturn;
typedef uintptr_t vm_address_t;
typedef void* task_t;
typedef void* OSAsyncReference64;
typedef uint64_t io_user_reference_t;
enum IOHIDReportType {
    kIOHIDReportTypeInput,
    kIOHIDReportTypeOutput,
    kIOHIDReportTypeFeature
};

enum {
    kIODirectionNone = 0,
    kIODirectionIn = 1,
    kIODirectionOut = 2,
    kIODirectionInOut = 3,
    kIOMemoryDirectionMask = 0x3
};

constexpr IOReturn kIOReturnSuccess = 0;
constexpr IOReturn kIOReturnNoResources = -1;
constexpr IOReturn kIOReturnUnsupported = -2;
constexpr IOReturn kIOReturnNoMemory = -3;
constexpr IOReturn kIOReturnDeviceError = -4;
constexpr IOReturn kIOReturnBadArgument = -5;

static task_t kernel_task = nullptr;

//-------------------------//
// Dummy OS classes
//-------------------------//
class OSObject {
public:
    virtual ~OSObject() = default;
    virtual void retain() {}
    virtual void release() {}
};

class OSString : public OSObject {
public:
    static OSString* withCString(const char* str) {
        auto* s = new OSString();
        strncpy(s->value, str, sizeof(s->value) - 1);
        s->value[sizeof(s->value) - 1] = 0;
        return s;
    }

    const char* getCStringNoCopy() const { return value; }
    void release() override { delete this; }

private:
    char value[256]{};
};

class OSNumber : public OSObject {
public:
    static OSNumber* withNumber(uint32_t, uint32_t) {
        return new OSNumber();
    }
};

class OSDictionary : public OSObject {
public:
    static OSDictionary* withCapacity(unsigned int) {
        return new OSDictionary();
    }

    bool setObject(OSString*, OSObject*) { return true; }
    OSObject* getObject(OSString*) { return nullptr; }
    void removeObject(OSString*) {}
    void release() override { delete this; }
};

class OSCollectionIterator : public OSObject {
public:
    static OSCollectionIterator* withCollection(OSObject*) {
        return new OSCollectionIterator();
    }

    OSObject* getNextObject() { return nullptr; }
    void release() override { delete this; }
};

//-------------------------//
// Dummy I/O Kit classes
//-------------------------//
class IOService : public OSObject {
public:
    virtual bool init(OSDictionary* = nullptr) { return true; }
    virtual bool start(IOService*) { return true; }
    virtual void stop(IOService*) {}
    virtual bool setProperty(const char*, const char*) { return true; }
    virtual void free() {}
    void release() override { delete this; }
};

class IOMemoryMap : public OSObject {
public:
    void* getAddress() { return dummy_ptr; }
    size_t getSize() { return dummy_size; }

    void* dummy_ptr = nullptr;
    size_t dummy_size = 64;
};

class IOMemoryDescriptor : public OSObject {
public:
    static IOMemoryDescriptor* withAddressRange(vm_address_t addr, size_t len, int, task_t) {
        auto* d = new IOMemoryDescriptor();
        d->addr = (void*)addr;
        d->length = len;
        return d;
    }

    IOReturn prepare() { return kIOReturnSuccess; }
    IOMemoryMap* map() {
        auto* m = new IOMemoryMap();
        m->dummy_ptr = addr;
        m->dummy_size = length;
        return m;
    }
    void complete() {}
    size_t getLength() const { return length; }
    void release() override { delete this; }

protected:
    void* addr = nullptr;
    size_t length = 0;
};

class IOHIDDevice : public IOService {
public:
    virtual bool init(OSDictionary* = nullptr) override { return true; }
    virtual void free() override {}

    virtual OSString* newProductString() const { return nullptr; }
    virtual OSString* newSerialNumberString() const { return nullptr; }
    virtual OSNumber* newVendorIDNumber() const { return nullptr; }
    virtual OSNumber* newProductIDNumber() const { return nullptr; }

    virtual IOReturn newReportDescriptor(IOMemoryDescriptor**) const { return kIOReturnSuccess; }
    virtual IOReturn setReport(IOMemoryDescriptor*, IOHIDReportType, IOOptionBits = 0) { return kIOReturnSuccess; }
};

class IOBufferMemoryDescriptor : public IOMemoryDescriptor {
public:
    static IOBufferMemoryDescriptor* inTaskWithOptions(task_t, int, size_t len) {
        return new IOBufferMemoryDescriptor(len);
    }

    bool writeBytes(size_t, const void*, size_t) { return true; }

private:
    IOBufferMemoryDescriptor(size_t len) { length = len; }
};

//-------------------------//
// Dummy Method Dispatch
//-------------------------//
struct IOExternalMethodArguments {
    void* structureInput = nullptr;
    size_t structureInputSize = 0;
    void* structureOutput = nullptr;
    size_t structureOutputSize = 0;
    uint64_t* scalarInput = nullptr;
    uint32_t scalarInputCount = 0;
    uint64_t* scalarOutput = nullptr;
    uint32_t scalarOutputCount = 0;
    OSAsyncReference64 asyncReference = nullptr;
};

typedef IOReturn (*IOExternalMethodAction)(OSObject* target,
                                           void* reference,
                                           IOExternalMethodArguments* arguments);

struct IOExternalMethodDispatch {
    IOExternalMethodAction function;
    uint32_t checkScalarInputCount;
    uint32_t checkStructureInputSize;
    uint32_t checkScalarOutputCount;
    uint32_t checkStructureOutputSize;
};

//-------------------------//
// Dummy IOUserClient
//-------------------------//
class IOUserClient : public IOService {
public:
    virtual bool initWithTask(task_t, void*, UInt32, OSDictionary*) { return true; }

    virtual IOReturn externalMethod(uint32_t selector,
                                    IOExternalMethodArguments* arguments,
                                    IOExternalMethodDispatch* dispatch,
                                    OSObject* target,
                                    void* reference) {
        return kIOReturnSuccess;
    }

    virtual bool start(IOService* provider) override { return true; }
    virtual void stop(IOService* provider) override {}
};

//-------------------------//
// Dummy helpers
//-------------------------//
inline void sendAsyncResult64(OSAsyncReference64, IOReturn,
                              io_user_reference_t*, uint32_t) {}

inline void* IOMalloc(size_t size) {
    // return malloc(size);
}
inline void IOFree(void* ptr, size_t) {
    // free(ptr);
}

#define OSTypeAlloc(type) new type()
#define OSDynamicCast(type, obj) (dynamic_cast<type*>(obj))
#define OSDefineMetaClassAndStructors(className, superClassName) \
    className::className() = default;                            \
    className::~className() = default;
#define OSDeclareDefaultStructors(className) \
public:                                      \
    className();                             \
    virtual ~className();

//-------------------------//
// Dummy Enums
//-------------------------//


#endif // DUMMY_H
