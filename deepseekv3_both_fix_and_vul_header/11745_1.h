#include <stdlib.h>
#include <string.h>

struct DataBuf {
    unsigned char* pData_;
    size_t size_;
    void alloc(size_t size) {
        pData_ = (unsigned char*)malloc(size);
        size_ = pData_ ? size : 0;
    }
    DataBuf() : pData_(nullptr), size_(0) {}
};

class PngChunk {
public:
    static DataBuf readRawProfile(const DataBuf& text, bool iTXt);
};