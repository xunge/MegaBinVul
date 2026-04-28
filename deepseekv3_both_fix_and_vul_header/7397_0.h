#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned int tsize_t;

struct image_data {
    unsigned int width;
    unsigned int length;
    unsigned short photometric;
    unsigned short spp;
    unsigned short bps;
};

struct crop_mask {
    unsigned int combined_width;
    unsigned int combined_length;
    tsize_t bufftotal;
    unsigned int crop_mode;
    unsigned short photometric;
    unsigned short mirror;
    unsigned short rotation;
};

#define PHOTOMETRIC_MINISWHITE 0
#define PHOTOMETRIC_MINISBLACK 1
#define INVERT_DATA_ONLY 2
#define INVERT_DATA_AND_TAG 3
#define CROP_INVERT 1
#define CROP_MIRROR 2
#define CROP_ROTATE 4
#define MIRROR_HORIZ 1

void* limitMalloc(tsize_t size);
void* _TIFFrealloc(void* ptr, tsize_t size);
void _TIFFmemset(void* ptr, int val, tsize_t size);
void TIFFError(const char* module, const char* fmt, ...);
int invertImage(unsigned short photometric, unsigned short spp, unsigned short bps, 
                unsigned int width, unsigned int length, unsigned char* buffer);
int mirrorImage(unsigned short spp, unsigned short bps, unsigned short mirror, 
                unsigned int width, unsigned int length, unsigned char* buffer);
int rotateImage(unsigned short rotation, struct image_data* image, 
                unsigned int* width, unsigned int* length, unsigned char** buffer);