#pragma once

#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <cstring> // for strstr
#include <cstdint>

namespace google {
namespace protobuf {

class Descriptor {
public:
    std::string full_name() const { return "DummyMessage"; }
};

class MethodDescriptor {
public:
    std::string name() const { return "DummyMethod"; }
    const Descriptor* input_type() const { static Descriptor d; return &d; }
    const Descriptor* output_type() const { static Descriptor d; return &d; }
};

class ServiceDescriptor {
public:
    std::string name() const { return "DummyService"; }
    int method_count() const { return 1; }
    const MethodDescriptor* method(int) const { static MethodDescriptor m; return &m; }
};

class FileDescriptor {
public:
    std::string package() const { return "dummy.package"; }
    int service_count() const { return 1; }
    const ServiceDescriptor* service(int) const { static ServiceDescriptor s; return &s; }
};

class UninterpretedOption {
public:
    class NamePart {
    public:
        std::string name_part() const { return "CmdID"; }
    };

    int name_size() const { return 1; }
    NamePart name(int) const { return NamePart(); }

    uint64_t positive_int_value() const { return 123; }
    std::string string_value() const { return "DummyString"; }
};

class MethodOptions {
public:
    int uninterpreted_option_size() const { return 1; }
    UninterpretedOption uninterpreted_option(int) const { return UninterpretedOption(); }
};

class MethodDescriptorProto {
public:
    std::string name() const { return "DummyMethod"; }
    const MethodOptions& options() const { static MethodOptions opt; return opt; }
};

class ServiceDescriptorProto {
public:
    int method_size() const { return 1; }
    const MethodDescriptorProto& method(int) const { static MethodDescriptorProto m; return m; }
};

class FileDescriptorProto {
public:
    int service_size() const { return 1; }
    const ServiceDescriptorProto& service(int) const { static ServiceDescriptorProto s; return s; }
};

} // namespace protobuf

namespace protobuf {
namespace compiler {

class MultiFileErrorCollector {
public:
    virtual void AddError(const std::string&, int, int, const std::string&) {}
    virtual ~MultiFileErrorCollector() = default;
};

class DiskSourceTree {
public:
    void MapPath(const std::string&, const std::string&) {}
};

class Importer {
public:
    Importer(DiskSourceTree*, MultiFileErrorCollector*) {}
    const protobuf::FileDescriptor* Import(const std::string&) const {
        static protobuf::FileDescriptor fd;
        return &fd;
    }
};

class SourceTreeDescriptorDatabase {
public:
    SourceTreeDescriptorDatabase(DiskSourceTree*) {}
    void RecordErrorsTo(MultiFileErrorCollector*) {}
    bool FindFileByName(const std::string&, protobuf::FileDescriptorProto* out) {
        *out = protobuf::FileDescriptorProto();
        return true;
    }
};

} // namespace compiler
} // namespace protobuf
} // namespace google

#pragma once

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EVFILT_READ    (-1)
#define EVFILT_WRITE   (-2)
#define EV_ADD         0x0001
#define EV_DELETE      0x0002
#define EPOLL_CTL_ADD  1
#define EPOLL_CTL_DEL  2
#define EPOLLIN        0x001
#define EPOLLOUT       0x004

struct kevent {
    uintptr_t fd;   // ✅ dùng cái này thay vì fd
    short filter;
    unsigned short flags;
    unsigned int fflags;
    intptr_t data;
    void *udata;
};

// Dummy kqueue
inline int kqueue() { return 0; }

// Dummy kevent
inline int kevent(int epfd, const struct kevent *changelist, int nchanges,
                  struct kevent *eventlist, int nevents, const struct timespec *timeout) {
    return 0; // giả lập không có sự kiện
}

// Dummy macro
#define EV_SET(kev, ident, filter, flags, fflags, data, udata) \
    do { \
        (kev)->ident = (ident); \
        (kev)->filter = (filter); \
        (kev)->flags = (flags); \
        (kev)->fflags = (fflags); \
        (kev)->data = (data); \
        (kev)->udata = (udata); \
    } while (0)

#ifdef __cplusplus
}
#endif
