// bson.cc
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include "bson.h"
#include "allocator.h"
#include "dummy.h"

// DataStream methods
void DataStream::WriteObjectId(const Local_Object&, const Local_String&) {
    char buffer[12] = {0};
    memcpy(p, buffer, 12);
    p += 12;
}

void DataStream::CheckKey(const Local_String&) {
    // No-op
}

// Exception stub
void ThrowAllocatedStringException(size_t, const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    exit(1);
}

// BSONSerializer
BSONSerializer::BSONSerializer(BSON* bson, bool checkKeys, bool serializeFunctions, CountStream* stream)
    : bson(bson), checkKeys(checkKeys), serializeFunctions(serializeFunctions), countStream(stream), dataStream(nullptr) {}

BSONSerializer::BSONSerializer(BSON* bson, bool checkKeys, bool serializeFunctions, DataStream* stream)
    : bson(bson), checkKeys(checkKeys), serializeFunctions(serializeFunctions), countStream(nullptr), dataStream(stream) {}

void BSONSerializer::SerializeDocument(const Local_Value& value) {
    void* sizeLoc = dataStream ? dataStream->BeginWriteSize() : countStream->BeginWriteSize();
    if (dataStream) {
        dataStream->WriteByte(0);
        dataStream->CommitSize(sizeLoc);
    } else {
        countStream->WriteByte(0);
        countStream->CommitSize(sizeLoc);
    }
}

void BSONSerializer::SerializeArray(const Local_Value& value) {
    void* sizeLoc = dataStream ? dataStream->BeginWriteSize() : countStream->BeginWriteSize();
    if (dataStream) {
        dataStream->WriteByte(0);
        dataStream->CommitSize(sizeLoc);
    } else {
        countStream->WriteByte(0);
        countStream->CommitSize(sizeLoc);
    }
}

void BSONSerializer::SerializeValue(void* typeLoc, const Local_Value& value) {
    if (dataStream) {
        dataStream->CommitType(typeLoc, BSON_TYPE_NULL);
    } else {
        countStream->CommitType(typeLoc, BSON_TYPE_NULL);
    }
}

// BSONDeserializer
BSONDeserializer::BSONDeserializer(BSON* bson, char* data, size_t length)
    : bson(bson), pStart(data), p(data), pEnd(data + length - 1) {
    if (*pEnd != '\0') ThrowAllocatedStringException(64, "Missing end marker");
}

BSONDeserializer::BSONDeserializer(BSONDeserializer& parent, size_t length)
    : bson(parent.bson), pStart(parent.p), p(parent.p), pEnd(parent.p + length) {
    parent.p += length;
    if (pEnd > parent.pEnd) {
        ThrowAllocatedStringException(64, "Child document exceeds parent's bounds");
    }
    if (*(pEnd - 1) != '\0') {
        ThrowAllocatedStringException(64, "Missing end of document marker '\\0'");
    }
}

Local_Value BSONDeserializer::DeserializeDocument(bool) {
    uint32_t len = ReadUInt32();
    if (len < 5) ThrowAllocatedStringException(0, "Invalid document length");
    BSONDeserializer doc(*this, len - 4);
    // return doc.DeserializeDocumentInternal();
}

Local_Value BSONDeserializer::DeserializeDocumentInternal(bool) {
    return Local_Object();
}

Local_Value BSONDeserializer::DeserializeArray(bool) {
    uint32_t len = ReadUInt32();
    if (len < 5) ThrowAllocatedStringException(0, "Invalid array length");
    BSONDeserializer doc(*this, len - 4);
    return doc.DeserializeArrayInternal(true);
}

Local_Value BSONDeserializer::DeserializeArrayInternal(bool) {
    return Local_Array();
}

Local_Value BSONDeserializer::DeserializeValue(BsonType, bool) {
    return Local_Value();
}

Local_Value BSONDeserializer::ReadCString() {
    char* start = p;
    while (*p++ && p < pEnd) {}
    if (p > pEnd) return Local_Value();
    return Local_String();
}

int32_t BSONDeserializer::ReadRegexOptions() {
    return 0;
}

uint32_t BSONDeserializer::ReadIntegerString() {
    return 0;
}

Local_String BSONDeserializer::ReadString() {
    return Local_String();
}

Local_String BSONDeserializer::ReadObjectId() {
    p += 12;
    return Local_String();
}

// BSON methods
BSON::BSON() {}
BSON::~BSON() {}
void BSON::Initialize(Local_Object) {}
void BSON::BSONSerialize(Local_Value*) {}
void BSON::BSONDeserialize(Local_Value*) {}
void BSON::CalculateObjectSize(Local_Value*) {}
void BSON::SerializeWithBufferAndIndex(Local_Value*) {}
void BSON::BSONDeserializeStream(Local_Value*) {}
void BSON::New(Local_Value*) {}
Local_Object BSON::GetSerializeObject(const Local_Value&) { return Local_Object(); }