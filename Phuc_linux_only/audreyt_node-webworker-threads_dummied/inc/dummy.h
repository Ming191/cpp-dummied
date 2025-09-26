// stubs.h
#ifndef STUBS_H
#define STUBS_H

#include <string>

// Stub types
class Local_Value {};
class Local_Object : public Local_Value {};
class Local_String : public Local_Value {};
class Local_Array : public Local_Value {};
class Local_Function : public Local_Value {};
class Local_Context {};
class Local_FunctionTemplate {};
class Nan_Persistent_String {};
class Nan_Persistent_Function {};
class Nan_Persistent_Context {};
class Nan_Persistent_Object {};
class Nan_Persistent_FunctionTemplate {};
class Nan_Persistent_ObjectTemplate {};
class Nan_HandleScope {};
class String_Utf8Value {
public:
    String_Utf8Value(const Local_Value&) {}
    String_Utf8Value(const Local_String&) {}
    char* operator*() { return nullptr; }
    int length() const { return 0; }
};
class Buffer {
public:
    static char* Data(const Local_Object&) { return nullptr; }
    static size_t Length(const Local_Object&) { return 0; }
    static bool HasInstance(const Local_Value&) { return false; }
};
class Nan {
public:
    static Local_FunctionTemplate New_FunctionTemplate(void (*)(void)) { return Local_FunctionTemplate(); }
    static Local_Object New_Object() { return Local_Object(); }
    static Local_Array New_Array(int) { return Local_Array(); }
    static Local_String New_String(const char*, int = -1) { return Local_String(); }
    static Local_Value Null() { return Local_Value(); }
    static Local_Value Undefined() { return Local_Value(); }
    static void DefineOwnProperty(Local_Object&, const Local_String&, const Local_Value&, int) {}
    static void SetInternalFieldPointer(Local_Object&, int, void*) {}
    static void* GetInternalFieldPointer(Local_Object&, int) { return nullptr; }
    static void AdjustExternalMemory(size_t) {}
    static void CallAsFunction(const Local_Value&, const Local_Object&, int, Local_Value[]) {}
    static void RunScript(const Local_Value&) {}
    static void CompileScript(const Local_String&) {}
    static void FatalException(void*) {}
    static void ThrowError(const Local_String&) {}
    static void ThrowTypeError(const char*) {}
    static Local_Object NewBuffer(char*, size_t) { return Local_Object(); }
};

// Stub enums and constants
enum PropertyAttribute { None, ReadOnly, DontDelete, DontEnum };
enum RegExp_Flags { kNone, kGlobal, kIgnoreCase, kMultiline };
static const PropertyAttribute attribute_ro_dd = static_cast<PropertyAttribute>(ReadOnly | DontDelete);

// Stub functions
void NanSetIsolateData(void*, void*) {}
void* NanGetIsolateData(void*) { return nullptr; }

#endif // STUBS_H