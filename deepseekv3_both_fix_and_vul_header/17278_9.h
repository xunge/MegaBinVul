#include <cstring>
#include <cstdint>
#include <string>
#include <vector>

namespace Exiv2 {
    typedef unsigned char byte;
    enum ByteOrder { littleEndian };
    namespace Internal {
        bool isTiffImageTag(uint16_t tag, int ifd);
        const int ifd0Id = 0;
    }
    class Error {
    public:
        enum { kerDataSourceOpenFailed = 1 };
        Error(int, const std::string&, const std::string&);
    };
    const int kerDataSourceOpenFailed = Error::kerDataSourceOpenFailed;
}

struct Value {
    size_t sizeDataArea() const;
    size_t count() const;
    uint32_t toLong(int) const;
    void setDataArea(const void*, size_t);
    Value& operator=(uint16_t);
    const Value& value() const;
};

struct BasicIo {
    int open();
    const char* path() const;
    const Exiv2::byte* mmap();
    long size() const;
};

struct ExifKey {
    ExifKey(uint16_t tag, const char* group);
    const char* groupName() const;
    uint16_t tag() const;
    const Value& value() const;
};

struct ExifData {
    struct const_iterator {
        const ExifKey* operator->() const;
        const_iterator& operator++();
        bool operator!=(const const_iterator&) const;
    };
    const_iterator begin() const;
    const_iterator end() const;
    void add(const ExifKey&, const Value*);
    Value& operator[](const std::string&);
};

struct DataBuf {
    DataBuf(uint32_t size);
    DataBuf(const Exiv2::byte* data, long size);
    Exiv2::byte* pData_;
    uint32_t size_;
};

struct IoCloser {
    IoCloser(BasicIo& io);
};

struct IptcData {};
struct XmpData {};

class MemIo {
public:
    const Exiv2::byte* mmap() const;
    long size() const;
};

namespace TiffParser {
    void encode(MemIo&, uint32_t, uint32_t, Exiv2::ByteOrder, const ExifData&, const IptcData&, const XmpData&);
}

class LoaderTiff {
public:
    DataBuf getData() const;
private:
    const char* group_;
    const std::string offsetTag_;
    const std::string sizeTag_;
    uint32_t size_;
    struct Image {
        const ExifData& exifData() const;
        BasicIo& io() const;
        std::string path() const;
        std::string mimeType() const;
    } image_;
};

std::string strError();

using namespace Exiv2;
using namespace Exiv2::Internal;