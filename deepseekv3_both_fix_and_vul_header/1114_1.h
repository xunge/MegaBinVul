#include <cmath>
#include <cstdlib>

struct RawTile {
    void* data;
    unsigned int width;
    unsigned int height;
    int channels;
    unsigned int dataLength;
    int bpc;
};

class Transform {
public:
    void interpolate_bilinear(RawTile& in, unsigned int resampled_width, unsigned int resampled_height);
};

#define PARALLEL_THRESHOLD 65536