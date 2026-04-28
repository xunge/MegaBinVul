#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

struct EXRChannelInfo {
    char name[256];
    int pixel_type;
    int x_sampling;
    int y_sampling;
    unsigned char p_linear;
    unsigned char pad[3];
};

struct EXRHeader {
    int num_channels;
    EXRChannelInfo* channels;
    int* pixel_types;
    int* requested_pixel_types;
    int compression_type;
    int data_window[4];
    int line_order;
    int tiled;
    int tile_size_x;
    int tile_size_y;
    int num_custom_attributes;
    void* custom_attributes;
};

struct EXRTile {
    void* images;
    int width;
    int height;
    int offset_x;
    int offset_y;
    int level_x;
    int level_y;
};

struct EXRImage {
    void* images;
    EXRTile* tiles;
    int num_tiles;
    int width;
    int height;
    int num_channels;
};

namespace tinyexr {
    typedef unsigned long long tinyexr_uint64;
    void swap4(unsigned int*);
    bool ComputeChannelLayout(std::vector<size_t>*, int*, size_t*, int, EXRChannelInfo*);
    void* AllocateImage(int, EXRChannelInfo*, int*, int, int);
    void DecodeTiledPixelData(void*, int*, int*, int*, const unsigned char*, size_t, int, int, int, int, int, int, int, int, size_t, size_t, void*, size_t, EXRChannelInfo*, const std::vector<size_t>&);
    bool DecodePixelData(void*, int*, const unsigned char*, size_t, int, int, int, int, int, int, int, int, size_t, size_t, void*, size_t, EXRChannelInfo*, const std::vector<size_t>&);
}

#define TINYEXR_COMPRESSIONTYPE_ZIP 0
#define TINYEXR_COMPRESSIONTYPE_PIZ 1
#define TINYEXR_COMPRESSIONTYPE_ZFP 2
#define TINYEXR_ERROR_INVALID_DATA -1
#define TINYEXR_ERROR_UNSUPPORTED_FEATURE -2
#define TINYEXR_SUCCESS 0