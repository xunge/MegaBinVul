#include <cassert>
#include <cstring>
#include <cstdint>

struct DataBuf {
    uint8_t* pData_;
    uint16_t size_;
    DataBuf(uint16_t size) : pData_(new uint8_t[size]), size_(size) {}
    ~DataBuf() { delete[] pData_; }
};

enum class IfdId {};

enum class ByteOrder {};

class ExifData {
public:
    struct Entry {
        IfdId ifdId() const { return IfdId{}; }
        uint16_t tag() const { return 0; }
        uint16_t size() const { return 0; }
        void copy(uint8_t*, ByteOrder) const {}
    };

    struct const_iterator {
        const Entry* operator->() const { return &entry; }
        bool operator!=(const const_iterator&) const { return false; }
        const_iterator& operator++() { return *this; }
        Entry entry;
    };
    
    const_iterator begin() const { return const_iterator(); }
    const_iterator end() const { return const_iterator(); }
};