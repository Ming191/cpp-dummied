#ifndef DUMMY_H
#define DUMMY_H

#ifndef USE_REAL_TYPEINFO

namespace __cxxabiv1 {
class __pointer_type_info;
class __class_type_info;
} // namespace __cxxabiv1

namespace std {

class type_info {
public:
    virtual ~type_info();

    virtual bool __do_catch(const type_info* thrown_type, void** thrown_obj, unsigned outer) const noexcept;

    virtual bool __do_upcast(const __cxxabiv1::__class_type_info* target_type, void** obj_ptr) const noexcept;

    virtual const __cxxabiv1::__pointer_type_info* __as_pointer_type() const noexcept;

    bool operator==(const type_info& rhs) const noexcept {
        return this == &rhs;
    }

    bool operator!=(const type_info& rhs) const noexcept {
        return !(*this == rhs);
    }
};

}


#endif // !USE_REAL_TYPEINFO

#endif // DUMMY_H
