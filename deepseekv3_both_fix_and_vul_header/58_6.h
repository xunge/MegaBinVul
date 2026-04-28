#include <stdbool.h>
#include <stddef.h>
#include <cassert>
#include <vector>
#include <string>

typedef struct {
    unsigned short u;
} FP16;

typedef struct {
    float f;
} FP32;

typedef struct {
    int pixel_type;
} EXRChannelInfo;

typedef struct {
    const char* name;
    const char* type;
    const unsigned char* value;
    size_t size;
} EXRAttribute;

typedef struct {
    // ZFP compression parameters
} ZFPCompressionParam;

#define TINYEXR_COMPRESSIONTYPE_PIZ 1
#define TINYEXR_COMPRESSIONTYPE_ZIPS 2
#define TINYEXR_COMPRESSIONTYPE_ZIP 3
#define TINYEXR_COMPRESSIONTYPE_RLE 4
#define TINYEXR_COMPRESSIONTYPE_ZFP 5
#define TINYEXR_COMPRESSIONTYPE_NONE 6

#define TINYEXR_PIXELTYPE_HALF 0
#define TINYEXR_PIXELTYPE_FLOAT 1
#define TINYEXR_PIXELTYPE_UINT 2

namespace tinyexr {
    bool DecompressPiz(unsigned char* out, const unsigned char* in, size_t out_size, size_t in_size, int num_channels, const EXRChannelInfo* channels, int width, int num_lines);
    bool DecompressZip(unsigned char* out, unsigned long* out_size, const unsigned char* in, unsigned long in_size);
    bool DecompressRle(unsigned char* out, unsigned long out_size, const unsigned char* in, unsigned long in_size);
    void cpy2(void* dst, const void* src);
    void cpy4(void* dst, const void* src);
    void swap2(unsigned short* val);
    void swap4(unsigned int* val);
    FP32 half_to_float(FP16 h);
    bool FindZFPCompressionParam(ZFPCompressionParam* param, const EXRAttribute* attributes, int num_attributes, std::string* err);
    void DecompressZfp(float* out, int width, int height, int num_channels, const unsigned char* in, unsigned long in_size, const ZFPCompressionParam& param);
    
    typedef ::FP16 FP16;
    typedef ::FP32 FP32;
}

using FP16 = tinyexr::FP16;
using FP32 = tinyexr::FP32;
using tinyexr::half_to_float;