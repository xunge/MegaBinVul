#include <stdint.h>

typedef struct AVHWAccel {
    int (*decode_slice)(void);
} AVHWAccel;

typedef struct AVCodecContext {
    AVHWAccel *hwaccel;
    int profile;
} AVCodecContext;

typedef struct Picture {
    int f;
    int field_picture;
} Picture;

typedef struct ERContext {
    AVCodecContext *avctx;
    Picture cur_pic;
} ERContext;

#define FF_PROFILE_MPEG4_SIMPLE_STUDIO 0