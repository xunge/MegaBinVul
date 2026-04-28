#include <cstdlib>
#include <cstring>

struct DataBuf {
    unsigned char* pData_;
    size_t size_;
    void alloc(size_t size) {
        pData_ = (unsigned char*)malloc(size);
        size_ = pData_ ? size : 0;
    }
    DataBuf() : pData_(nullptr), size_(0) {}
    ~DataBuf() { free(pData_); }
};

class PngChunk {
public:
    static DataBuf readRawProfile(const DataBuf& text, bool iTXt);
};