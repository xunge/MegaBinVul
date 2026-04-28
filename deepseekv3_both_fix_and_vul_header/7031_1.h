#include <stdint.h>
#include <string.h>
#include <inttypes.h>

#define COMPOSITE_IMAGES 1
#define CROP_INVERT 1
#define CROP_MIRROR 2
#define CROP_ROTATE 4
#define PHOTOMETRIC_MINISWHITE 0
#define PHOTOMETRIC_MINISBLACK 1
#define INVERT_DATA_ONLY 2
#define INVERT_DATA_AND_TAG 3
#define MIRROR_HORIZ 1
#define NUM_BUFF_OVERSIZE_BYTES 0

typedef unsigned long tsize_t;

struct image_data {
    int photometric;
    int spp;
    int bps;
    uint32_t width;
    uint32_t length;
    float xres;
    float yres;
};

struct crop_mask {
    int img_mode;
    int crop_mode;
    int photometric;
    uint32_t bufftotal;
    uint32_t combined_width;
    uint32_t combined_length;
    int mirror;
    uint16_t rotation;
    int selections;
    struct {
        uint32_t width;
        uint32_t length;
    } *regionlist;
};

struct buffinfo {
    unsigned char *buffer;
    tsize_t size;
};

extern void *_TIFFrealloc(void *, tsize_t);
extern void _TIFFfree(void *);
extern void _TIFFmemset(void *, int, tsize_t);
extern void *limitMalloc(tsize_t);
extern int extractCompositeRegions(struct image_data *, struct crop_mask *, unsigned char *, unsigned char *);
extern int extractSeparateRegion(struct image_data *, struct crop_mask *, unsigned char *, unsigned char *, int);
extern int invertImage(int, int, int, uint32_t, uint32_t, unsigned char *);
extern int mirrorImage(int, int, int, uint32_t, uint32_t, unsigned char *);
extern int rotateImage(int, struct image_data *, uint32_t *, uint32_t *, unsigned char **);
extern void TIFFError(const char *, const char *, ...);