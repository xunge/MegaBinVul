#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <sstream>

typedef unsigned long long tinyexr_uint64;

typedef enum {
    TINYEXR_COMPRESSIONTYPE_NONE,
    TINYEXR_COMPRESSIONTYPE_RLE,
    TINYEXR_COMPRESSIONTYPE_ZIPS,
    TINYEXR_COMPRESSIONTYPE_ZIP,
    TINYEXR_COMPRESSIONTYPE_PIZ,
    TINYEXR_COMPRESSIONTYPE_ZFP
} EXRCompressionType;

typedef enum {
    TINYEXR_SUCCESS = 0,
    TINYEXR_ERROR_INVALID_DATA,
    TINYEXR_ERROR_UNSUPPORTED_FEATURE
} EXRErrorCode;

typedef struct {
    int num_channels;
    int compression_type;
    int data_window[4];
    int tile_size_x;
    int tile_size_y;
    int line_order;
    int num_custom_attributes;
    int* requested_pixel_types;
    int* pixel_types;
    void* channels;
    void* custom_attributes;
    bool tiled;
} EXRHeader;

typedef struct {
    void* images;
    int width;
    int height;
    int offset_x;
    int offset_y;
    int level_x;
    int level_y;
} EXRTile;

typedef struct {
    void* images;
    EXRTile* tiles;
    int num_tiles;
    int num_channels;
    int width;
    int height;
} EXRImage;

namespace tinyexr {
    typedef unsigned long long tinyexr_uint64;
    bool ComputeChannelLayout(std::vector<size_t>* channel_offset_list, int* pixel_data_size, size_t* channel_offset, int num_channels, void* channels);
    void* AllocateImage(int num_channels, void* channels, int* requested_pixel_types, int width, int height);
    void swap4(unsigned int* val);
    bool DecodePixelData(void* images, int* requested_pixel_types, const unsigned char* data_ptr, size_t data_len, int compression_type, int line_order, int data_width, int data_height, int width, int y, int line_no, int num_lines, size_t pixel_data_size, size_t num_custom_attributes, void* custom_attributes, size_t num_channels, void* channels, const std::vector<size_t>& channel_offset_list);
    bool DecodeTiledPixelData(void* images, int* width, int* height, int* requested_pixel_types, const unsigned char* data_ptr, size_t data_len, int compression_type, int line_order, int data_width, int data_height, int offset_x, int offset_y, int tile_size_x, int tile_size_y, size_t pixel_data_size, size_t num_custom_attributes, void* custom_attributes, size_t num_channels, void* channels, const std::vector<size_t>& channel_offset_list);
}