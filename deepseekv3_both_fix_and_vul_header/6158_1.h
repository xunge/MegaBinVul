#include <cstring>
#include <cstdint>

enum IfdId {};
enum ByteOrder {};

struct DataBuf {
    uint8_t* pData_;
    uint16_t size_;
    DataBuf(uint16_t size) : size_(size), pData_(new uint8_t[size]) {}
    ~DataBuf() { delete[] pData_; }
};

class ExifData {
public:
    class const_iterator {
    public:
        const ExifData* parent;
        size_t index;
        
        const_iterator() : parent(nullptr), index(0) {}
        const_iterator(const ExifData* p, size_t i) : parent(p), index(i) {}
        
        const ExifData::const_iterator& operator*() const { return *this; }
        const ExifData::const_iterator* operator->() const { return this; }
        
        IfdId ifdId() const { return IfdId(); }
        uint16_t tag() const { return 0; }
        uint16_t size() const { return 0; }
        void copy(uint8_t*, ByteOrder) const {}
        
        const_iterator& operator++() { index++; return *this; }
        bool operator!=(const const_iterator& other) const { 
            return index != other.index; 
        }
    };
    
    const_iterator begin() const { return const_iterator(this, 0); }
    const_iterator end() const { return const_iterator(this, 0); }
};