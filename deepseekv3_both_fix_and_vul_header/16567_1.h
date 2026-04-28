#include <vector>
#include <stdexcept>
#include <limits>

typedef unsigned char png_byte;

struct PngInfo {
    size_t height;
    size_t rowbytes;
};

class PngImg {
private:
    std::vector<png_byte*> rowPtrs_;
    png_byte* data_;
    PngInfo info_;
public:
    void InitStorage_();
};