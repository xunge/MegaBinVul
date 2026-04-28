#include <iostream>
#include <string>
#include <cstring>
#include <cstdint>

struct Error {
    Error(int code, const std::string& path, const char* str) {}
    Error(int code) {}
    Error(int code, const char* msg) {}
};

class Exiv2 {
public:
    struct ExifData;
    struct ExifKey {
        ExifKey(const char* key) {}
    };
};

class Exiv2::ExifData {
public:
    struct iterator {
        bool operator!=(const iterator&) { return false; }
        size_t count() { return 0; }
        size_t typeSize() { return 0; }
        void copy(void* pData, int bo) {}
        iterator* operator->() { return this; }
    };
    
    iterator findKey(const ExifKey&) { return iterator(); }
    iterator end() { return iterator(); }
};

class TiffParser {
public:
    static int decode(Exiv2::ExifData&, Exiv2::ExifData&, Exiv2::ExifData&, void*, uint32_t) { return 0; }
};

struct IccProfile {
    void* pData_;
    void alloc(size_t size) {}
};

class TiffImage {
public:
    struct Io {
        int open() { return 0; }
        std::string path() { return ""; }
        bool error() { return false; }
        bool eof() { return false; }
        void* mmap() { return nullptr; }
        size_t size() { return 0; }
    };

    void readMetadata();
    Exiv2::ExifData exifData_;
    Exiv2::ExifData iptcData_;
    Exiv2::ExifData xmpData_;
    IccProfile iccProfile_;
    Io* io_;
};

class IoCloser {
public:
    IoCloser(TiffImage::Io& io) {}
};

const int kerDataSourceOpenFailed = 0;
const int kerFailedToReadImageData = 1;
const int kerNotAnImage = 2;

bool isTiffType(TiffImage::Io&, bool) { return false; }
void clearMetadata() {}
void setByteOrder(int) {}
const char* strError() { return ""; }

typedef int ByteOrder;