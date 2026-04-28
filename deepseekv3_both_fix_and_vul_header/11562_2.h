#include <iostream>
#include <memory>
#include <stdexcept>

typedef unsigned char byte;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

enum ByteOrder {
    littleEndian,
    bigEndian
};

enum ErrorCode {
    kerCorruptedMetadata,
    kerNotACrwImage
};

class Error {
public:
    Error(ErrorCode code);
};

class CiffComponent {
public:
    enum TypeId {
        directory
    };
    class AutoPtr {
    public:
        AutoPtr() : ptr_(nullptr) {}
        AutoPtr(CiffComponent* ptr) : ptr_(ptr) {}
        ~AutoPtr() { delete ptr_; }
        CiffComponent* operator->() { return ptr_; }
        CiffComponent* ptr_;
    };
    static TypeId typeId(uint16_t tag);
    void setDir(uint16_t tag);
    void read(const byte* pData, uint32_t size, uint32_t offset, ByteOrder byteOrder);
};

class CiffDirectory : public CiffComponent {
public:
    void readDirectory(const byte* pData, uint32_t size, ByteOrder byteOrder);
    void add(AutoPtr component);
    uint16_t tag() const;
};

class CiffEntry : public CiffComponent {
};

uint32_t getULong(const byte* pData, ByteOrder byteOrder);
uint16_t getUShort(const byte* pData, ByteOrder byteOrder);