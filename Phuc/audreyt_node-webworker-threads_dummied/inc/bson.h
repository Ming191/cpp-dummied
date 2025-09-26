// bson.h
#ifndef BSON_H
#define BSON_H

#include <cstdint>
#include <string>
#include "dummy.h"
enum BsonType {
    BSON_TYPE_NUMBER = 1,
    BSON_TYPE_STRING = 2,
    BSON_TYPE_OBJECT = 3,
    BSON_TYPE_ARRAY = 4,
    BSON_TYPE_BINARY = 5,
    BSON_TYPE_UNDEFINED = 6,
    BSON_TYPE_OID = 7,
    BSON_TYPE_BOOLEAN = 8,
    BSON_TYPE_DATE = 9,
    BSON_TYPE_NULL = 10,
    BSON_TYPE_REGEXP = 11,
    BSON_TYPE_CODE = 13,
    BSON_TYPE_SYMBOL = 14,
    BSON_TYPE_CODE_W_SCOPE = 15,
    BSON_TYPE_INT = 16,
    BSON_TYPE_TIMESTAMP = 17,
    BSON_TYPE_LONG = 18,
    BSON_TYPE_MAX_KEY = 0x7f,
    BSON_TYPE_MIN_KEY = 0xff
};

class BSON {
public:
    BSON();
    ~BSON();
    static void Initialize(Local_Object target);
    static void BSONSerialize(Local_Value* info);
    static void BSONDeserialize(Local_Value* info);
    static void CalculateObjectSize(Local_Value* info);
    static void SerializeWithBufferAndIndex(Local_Value* info);
    static void BSONDeserializeStream(Local_Value* info);
    static void New(Local_Value* info);
    Local_Object GetSerializeObject(const Local_Value& object);

private:
    // Stubbed persistent handles
    Nan_Persistent_Function longConstructor;
    Nan_Persistent_Function objectIDConstructor;
    Nan_Persistent_Function binaryConstructor;
    Nan_Persistent_Function codeConstructor;
    Nan_Persistent_Function dbrefConstructor;
    Nan_Persistent_Function symbolConstructor;
    Nan_Persistent_Function doubleConstructor;
    Nan_Persistent_Function timestampConstructor;
    Nan_Persistent_Function minKeyConstructor;
    Nan_Persistent_Function maxKeyConstructor;
    Nan_Persistent_String longString;
    Nan_Persistent_String objectIDString;
    Nan_Persistent_String binaryString;
    Nan_Persistent_String codeString;
    Nan_Persistent_String dbrefString;
    Nan_Persistent_String symbolString;
    Nan_Persistent_String doubleString;
    Nan_Persistent_String timestampString;
    Nan_Persistent_String minKeyString;
    Nan_Persistent_String maxKeyString;
    Nan_Persistent_String _bsontypeString;
    Nan_Persistent_String _longLowString;
    Nan_Persistent_String _longHighString;
    Nan_Persistent_String _objectIDidString;
    Nan_Persistent_String _binaryPositionString;
    Nan_Persistent_String _binarySubTypeString;
    Nan_Persistent_String _binaryBufferString;
    Nan_Persistent_String _doubleValueString;
    Nan_Persistent_String _symbolValueString;
    Nan_Persistent_String _dbRefRefString;
    Nan_Persistent_String _dbRefIdRefString;
    Nan_Persistent_String _dbRefDbRefString;
    Nan_Persistent_String _dbRefNamespaceString;
    Nan_Persistent_String _dbRefDbString;
    Nan_Persistent_String _dbRefOidString;
    Nan_Persistent_String _codeCodeString;
    Nan_Persistent_String _codeScopeString;
    Nan_Persistent_String _toBSONString;
};

class CountStream {
public:
    CountStream() : count(0) {}
    void WriteByte(int value) { ++count; }
    void WriteByte(const Local_Object&, const Local_String&) { ++count; }
    void WriteBool(const Local_Value&) { ++count; }
    void WriteInt32(int32_t value) { count += 4; }
    void WriteInt32(const Local_Value&) { count += 4; }
    void WriteInt32(const Local_Object&, const Local_String&) { count += 4; }
    void WriteInt64(int64_t value) { count += 8; }
    void WriteInt64(const Local_Value&) { count += 8; }
    void WriteDouble(double value) { count += 8; }
    void WriteDouble(const Local_Value&) { count += 8; }
    void WriteDouble(const Local_Object&, const Local_String&) { count += 8; }
    void WriteUInt32String(uint32_t name) { count += 5; } // Simplified
    void WriteLengthPrefixedString(const Local_String&) { count += 5; }
    void WriteObjectId(const Local_Object&, const Local_String&) { count += 12; }
    void WriteString(const Local_String&) { count += 5; }
    void WriteData(const char*, size_t length) { count += length; }
    void* BeginWriteType() { ++count; return nullptr; }
    void CommitType(void*, BsonType) {}
    void* BeginWriteSize() { count += 4; return nullptr; }
    void CommitSize(void*) {}
    size_t GetSerializeSize() const { return count; }
    void CheckKey(const Local_String&) {}

private:
    size_t count;
};

class DataStream {
public:
    DataStream(char* buffer) : destinationBuffer(buffer), p(buffer) {}
    void WriteByte(int value) { *p++ = value; }
    void WriteByte(const Local_Object&, const Local_String&) { *p++ = 0; }
    void WriteInt32(int32_t value) { memcpy(p, &value, 4); p += 4; }
    void WriteInt64(int64_t value) { memcpy(p, &value, 8); p += 8; }
    void WriteDouble(double value) { memcpy(p, &value, 8); p += 8; }
    void WriteBool(const Local_Value&) { WriteByte(0); }
    void WriteInt32(const Local_Value&) { WriteInt32(0); }
    void WriteInt32(const Local_Object&, const Local_String&) { WriteInt32(0); }
    void WriteInt64(const Local_Value&) { WriteInt64(0); }
    void WriteDouble(const Local_Value&) { WriteDouble(0.0); }
    void WriteDouble(const Local_Object&, const Local_String&) { WriteDouble(0.0); }
    void WriteUInt32String(uint32_t name) { p += sprintf(p, "%u", name) + 1; }
    void WriteLengthPrefixedString(const Local_String&) { WriteInt32(1); WriteString(Local_String()); }
    void WriteObjectId(const Local_Object&, const Local_String&);
    void WriteString(const Local_String&) { *p++ = 0; }
    void WriteData(const char* data, size_t length) { memcpy(p, data, length); p += length; }
    void* BeginWriteType() { void* ret = p; p++; return ret; }
    void CommitType(void* begin, BsonType value) { *reinterpret_cast<unsigned char*>(begin) = value; }
    void* BeginWriteSize() { void* ret = p; p += 4; return ret; }
    void CommitSize(void* begin) { int32_t size = static_cast<int32_t>(p - static_cast<char*>(begin)); memcpy(begin, &size, 4); }
    size_t GetSerializeSize() const { return p - destinationBuffer; }
    void CheckKey(const Local_String&);

protected:
    char* const destinationBuffer;
    char* p;
};

class BSONSerializer {
public:
    BSONSerializer(BSON* bson, bool checkKeys, bool serializeFunctions, CountStream* stream);
    BSONSerializer(BSON* bson, bool checkKeys, bool serializeFunctions, DataStream* stream);
    void SerializeDocument(const Local_Value& value);
    void SerializeArray(const Local_Value& value);
    void SerializeValue(void* typeLocation, const Local_Value& value);

private:
    bool checkKeys;
    bool serializeFunctions;
    BSON* bson;
    CountStream* countStream;
    DataStream* dataStream;
};

class BSONDeserializer {
public:
    BSONDeserializer(BSON* bson, char* data, size_t length);
    BSONDeserializer(BSONDeserializer& parent, size_t length);
    Local_Value DeserializeDocument(bool promoteLongs);
    bool HasMoreData() const { return p < pEnd; }
    Local_Value ReadCString();
    uint32_t ReadIntegerString();
    int32_t ReadRegexOptions();
    Local_String ReadString();
    Local_String ReadObjectId();
    unsigned char ReadByte() { return *reinterpret_cast<unsigned char*>(p++); }
    int32_t ReadInt32() { int32_t v; memcpy(&v, p, 4); p += 4; return v; }
    uint32_t ReadUInt32() { uint32_t v; memcpy(&v, p, 4); p += 4; return v; }
    int64_t ReadInt64() { int64_t v; memcpy(&v, p, 8); p += 8; return v; }
    double ReadDouble() { double v; memcpy(&v, p, 8); p += 8; return v; }
    size_t GetSerializeSize() const { return p - pStart; }

private:
    Local_Value DeserializeArray(bool promoteLongs);
    Local_Value DeserializeValue(BsonType type, bool promoteLongs);
    Local_Value DeserializeDocumentInternal(bool promoteLongs);
    Local_Value DeserializeArrayInternal(bool promoteLongs);
    BSON* bson;
    char* const pStart;
    char* p;
    char* const pEnd;
};

#endif // BSON_H