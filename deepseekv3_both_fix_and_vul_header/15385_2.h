#include <stdint.h>
#include <stdbool.h>
#include <cstddef>
#include <cassert>

#define MAX_NUM_REF_PICS 16
#define DE265_WARNING_INCORRECT_MOTION_VECTOR_SCALING 0
#define DE265_WARNING_NONEXISTING_REFERENCE_PICTURE_ACCESSED 0
#define INTEGRITY_DECODING_ERRORS 0
#define MODE_INTRA 0
#define LogMotion 0

typedef struct {
    int x;
    int y;
} MotionVector;

typedef struct {
    int predFlag[2];
    int refIdx[2];
    MotionVector mv[2];
} PBMotion;

typedef struct {
    int PicOrderCntVal;
    int integrity;
    int (*available_pred_blk)(int, int, int, int, int, int, int, int, int, int);
    int (*get_pred_mode)(int, int);
    PBMotion (*get_mv_info)(int, int);
    struct decctx* decctx;
} de265_image;

typedef struct {
    int RefPicList[2][MAX_NUM_REF_PICS];
    int LongTermRefPic[2][MAX_NUM_REF_PICS];
} slice_segment_header;

typedef struct {
    void (*add_warning)(int, bool);
    de265_image* (*get_image)(int);
} base_context;

typedef struct decctx {
    void (*add_warning)(int, bool);
} decctx;

bool scale_mv(MotionVector* out, MotionVector in, int distA, int distX) {
    return false;
}

void logtrace(int, const char*, ...) {}
void logmvcand(const PBMotion&) {}