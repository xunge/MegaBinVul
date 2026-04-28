#include <cassert>
#include <cstring>
#include <cstdint>
#include <string>
#include <vector>

struct ExifKey {
    std::string key;
    ExifKey(const std::string& k) : key(k) {}
    size_t size() const { return 0; }
    void copy(uint8_t*, int) const {}
    size_t count() const { return 0; }
    int typeId() const { return 0; }
    long toLong() const { return 0; }
};

struct ExifData {
    struct const_iterator {
        const ExifKey* key;
        const_iterator() : key(nullptr) {}
        const_iterator(const ExifKey* k) : key(k) {}
        bool operator!=(const const_iterator& other) const { return key != other.key; }
        const ExifKey& operator*() const { return *key; }
        const ExifKey* operator->() const { return key; }
        const_iterator& operator++() { key++; return *this; }
    };
    const_iterator findKey(const ExifKey&) const { return const_iterator(); }
    const_iterator end() const { return const_iterator(); }
};

struct Image {
    const ExifData& exifData() const { static ExifData e; return e; }
};

struct CrwMapping {
    uint16_t crwTagId_;
    uint16_t crwDir_;
};

struct DataBuf {
    uint8_t* pData_;
    uint32_t size_;
    DataBuf(uint32_t s) : size_(s), pData_(new uint8_t[s]) {}
    ~DataBuf() { delete[] pData_; }
};

struct CiffComponent {
    uint32_t size() const { return 0; }
    const uint8_t* pData() const { return nullptr; }
};

struct CiffHeader {
    CiffComponent* findComponent(uint16_t, uint16_t) { return nullptr; }
    int byteOrder() const { return 0; }
    void add(uint16_t, uint16_t, const DataBuf&) {}
    void remove(uint16_t, uint16_t) {}
};

struct RotationMap {
    static int32_t degrees(uint16_t) { return 0; }
};

enum TypeId { unsignedShort };
enum ErrorCode { kerCorruptedMetadata };

struct Error {
    Error(ErrorCode) {}
};

void l2Data(uint8_t*, int32_t, int) {}

struct CrwMap {
    void encode0x1810(const Image&, const CrwMapping*, CiffHeader*);
};