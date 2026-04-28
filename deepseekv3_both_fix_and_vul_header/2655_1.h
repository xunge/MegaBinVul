#include <stdint.h>
#include <cstring>

#define AP4_ATOM_HEADER_SIZE 8
#define AP4_ATOM_TYPE_DATA 0x64617461

typedef uint32_t AP4_Size;
typedef uint8_t AP4_UI08;
typedef uint16_t AP4_UI16;
typedef uint32_t AP4_UI32;

enum {
    DATA_TYPE_BINARY,
    DATA_TYPE_STRING_UTF_8,
    DATA_TYPE_SIGNED_INT_BE,
    DATA_TYPE_JPEG,
    DATA_TYPE_GIF,
    LANGUAGE_ENGLISH
};

class AP4_Atom {
public:
    AP4_Atom(uint32_t type, uint32_t header_size) : m_Size32(0) {}
    uint32_t m_Size32;
};

class AP4_ByteStream {
public:
    virtual void Write(const void* data, uint32_t size) = 0;
};

class AP4_MemoryByteStream : public AP4_ByteStream {
public:
    AP4_MemoryByteStream() {}
    void Write(const void* data, uint32_t size) override {}
};

class AP4_String {
public:
    AP4_String() {}
    AP4_String(const char* str) {}
    const char* GetChars() const { return nullptr; }
    uint32_t GetLength() const { return 0; }
    bool operator==(const char* str) const { return false; }
};

class AP4_DataBuffer {
public:
    const uint8_t* GetData() const { return nullptr; }
    uint32_t GetDataSize() const { return 0; }
};

class AP4_MetaData {
public:
    class Value {
    public:
        enum Type {
            TYPE_STRING_UTF_8,
            TYPE_INT_08_BE,
            TYPE_INT_16_BE,
            TYPE_INT_32_BE,
            TYPE_JPEG,
            TYPE_GIF,
            TYPE_BINARY
        };
        
        Type GetType() const { return TYPE_BINARY; }
        AP4_String ToString() const { return AP4_String(); }
        int64_t ToInteger() const { return 0; }
        void ToBytes(AP4_DataBuffer& buffer) const {}
        const AP4_String& GetLanguage() const { static AP4_String s; return s; }
    };
};

class AP4_DataAtom : public AP4_Atom {
public:
    AP4_DataAtom(const AP4_MetaData::Value& value);
    
private:
    AP4_ByteStream* m_Source;
    uint32_t m_DataType;
    uint32_t m_DataLang;
};