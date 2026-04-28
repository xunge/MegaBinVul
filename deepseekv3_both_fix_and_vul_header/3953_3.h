#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#define MIRROR_HORIZ 0x01
#define MIRROR_VERT 0x02
#define MIRROR_BOTH (MIRROR_HORIZ | MIRROR_VERT)
#define ROTATE_ANY 0x0C
#define ROTATECW_90 0x04
#define ROTATECW_180 0x08
#define ROTATECW_270 0x0C
#define ORIENTATION_TOPLEFT 1

struct image_data {
    int adjustments;
    int spp;
    int bps;
    unsigned width;
    unsigned length;
    int orientation;
};

extern int TIFFError(const char*, const char*, ...);
extern int mirrorImage(int spp, int bps, uint16_t mirror, unsigned width, unsigned length, unsigned char *work_buff);
extern int rotateImage(uint16_t rotation, struct image_data *image, unsigned *width, unsigned *length, unsigned char **work_buff_ptr, ...);