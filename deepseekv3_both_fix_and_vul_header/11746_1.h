#include <stdlib.h>
#include <string.h>

struct DataBuf {
    unsigned char* pData_;
    size_t size_;
    void alloc(size_t size) {
        pData_ = (unsigned char*)malloc(size);
        size_ = size;
    }
    DataBuf() : pData_(nullptr), size_(0) {}
};

struct PngChunk {
    static DataBuf readRawProfile(const DataBuf& text, bool iTXt);
};