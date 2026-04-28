#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <algorithm>

typedef long long tinyexr_int64;
typedef unsigned long long tinyexr_uint64;

typedef struct EXRHeader {
    int num_channels;
    int compression_type;
    int data_window[4];
    int tile_size_x;
    int tile_size_y;
    int* requested_pixel_types;
    int num_custom_attributes;
    void* custom_attributes;
    int* pixel_types;
    void* channels;
    bool tiled;
    int line_order;
} EXRHeader;

typedef struct EXRImage {
    void* images;
    int width;
    int height;
    int num_channels;
    int num_tiles;
    struct EXRTile* tiles;
} EXRImage;

typedef struct EXRTile {
    void* images;
    int width;
    int height;
    int offset_x;
    int offset_y;
    int level_x;
    int level_y;
} EXRTile;

namespace tinyexr {
    typedef tinyexr_uint64 tinyexr_uint64;
    bool ComputeChannelLayout(std::vector<size_t>* channel_offset_list, int* pixel_data_size, size_t* channel_offset, int num_channels, void* channels);
    void* AllocateImage(int num_channels, void* channels, int* requested_pixel_types, int width, int height);
    void swap4(unsigned int* val);
    bool DecodePixelData(void* images, int* requested_pixel_types, const unsigned char* data_ptr, size_t data_len, int compression_type, int line_order, int data_width, int data_height, int width, int y, int line_no, int num_lines, size_t pixel_data_size, size_t num_custom_attributes, void* custom_attributes, size_t num_channels, void* channels, std::vector<size_t> channel_offset_list);
    bool DecodeTiledPixelData(void* images, int* width, int* height, int* requested_pixel_types, const unsigned char* data_ptr, size_t data_len, int compression_type, int line_order, int data_width, int data_height, int tile_x, int tile_y, int tile_size_x, int tile_size_y, size_t pixel_data_size, size_t num_custom_attributes, void* custom_attributes, size_t num_channels, void* channels, std::vector<size_t> channel_offset_list);
}

#define TINYEXR_COMPRESSIONTYPE_ZIP 1
#define TINYEXR_COMPRESSIONTYPE_PIZ 2
#define TINYEXR_COMPRESSIONTYPE_ZFP 3
#define TINYEXR_ERROR_INVALID_DATA -1
#define TINYEXR_ERROR_INVALID_HEADER -2
#define TINYEXR_ERROR_UNSUPPORTED_FEATURE -3
#define TINYEXR_SUCCESS 0