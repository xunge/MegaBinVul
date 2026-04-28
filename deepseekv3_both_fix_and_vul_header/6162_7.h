#include <cassert>
#include <string>

class ExifKey {
public:
    ExifKey(const std::string& key);
    size_t size() const;
    void copy(unsigned char* buf, int byteOrder) const;
};

class ExifData {
public:
    class const_iterator {
    public:
        const ExifKey& operator*() const;
        const_iterator& operator++();
        bool operator!=(const const_iterator& other) const;
        const ExifKey* operator->() const;
    };
    const_iterator findKey(const ExifKey& key) const;
    const_iterator end() const;
};

class Image {
public:
    const ExifData& exifData() const;
};

class DataBuf {
public:
    unsigned char* pData_;
    DataBuf(long size);
};

class CiffHeader {
public:
    int byteOrder() const;
    void add(unsigned short crwTagId, unsigned short crwDir, const DataBuf& buf);
    void remove(unsigned short crwTagId, unsigned short crwDir);
};

struct CrwMapping {
    unsigned short crwTagId_;
    unsigned short crwDir_;
};

class CrwMap {
public:
    void encode0x080a(const Image& image, const CrwMapping* pCrwMapping, CiffHeader* pHead);
};