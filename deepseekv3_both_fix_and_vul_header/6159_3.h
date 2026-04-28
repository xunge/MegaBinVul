#include <cstdint>
#include <cstring>
#include <iostream>

struct DataBuf {
    uint8_t* pData_;
    uint16_t size_;
    DataBuf(uint16_t size) : size_(size), pData_(new uint8_t[size]) {}
    ~DataBuf() { delete[] pData_; }
};

enum class IfdId {};

enum class ByteOrder {};

class ExifData {
public:
    class Entry {
    public:
        IfdId ifdId() const { return IfdId(); }
        uint16_t tag() const { return 0; }
        uint16_t size() const { return 0; }
        void copy(uint8_t* buf, ByteOrder byteOrder) const {}
    };

    class const_iterator {
    public:
        Entry entry;
        const_iterator() = default;
        const Entry* operator->() const { return &entry; }
        const_iterator& operator++() { return *this; }
        bool operator!=(const const_iterator& other) const { return false; }
    };

    const_iterator begin() const { return const_iterator(); }
    const_iterator end() const { return const_iterator(); }
};

extern std::ostream EXV_ERROR;