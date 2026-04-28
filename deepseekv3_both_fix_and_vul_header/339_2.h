#include <cstdint>
#include <iostream>
#include <memory>

typedef unsigned char byte;

enum ByteOrder {
    littleEndian,
    bigEndian
};

class Error {
public:
    Error(int code) : code_(code) {}
private:
    int code_;
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
    private:
        CiffComponent* ptr_;
    };
    static TypeId typeId(uint16_t tag);
    void setDir(uint16_t tag);
    void read(const byte* pData, uint32_t size, uint32_t offset, ByteOrder byteOrder);
    uint16_t tag() const;
};

class CiffDirectory : public CiffComponent {
public:
    void readDirectory(const byte* pData, uint32_t size, ByteOrder byteOrder);
    void add(const AutoPtr& component);
};

class CiffEntry : public CiffComponent {
};

uint32_t getULong(const byte* pData, ByteOrder byteOrder);
uint16_t getUShort(const byte* pData, ByteOrder byteOrder);