#include <stddef.h>
#include <assert.h>

#define CV_Assert(expr) assert(expr)

struct Size {
    int width;
    int height;
    bool empty() const { return width == 0 || height == 0; }
};

struct HOGDescriptor {
    Size cellSize;
    Size blockSize;
    Size blockStride;
    Size winSize;
    int nbins;
    size_t getDescriptorSize() const;
};