#include <stdint.h>
#include <stdbool.h>
#include <cstddef>
#include <assert.h>

#define MAX_NUM_REF_PICS 16
#define DE265_WARNING_INCORRECT_MOTION_VECTOR_SCALING 0
#define DE265_WARNING_NONEXISTING_REFERENCE_PICTURE_ACCESSED 0
#define INTEGRITY_DECODING_ERRORS 0
#define MODE_INTRA 0

struct MotionVector {
    int x;
    int y;
};

struct PBMotion {
    int predFlag[2];
    int refIdx[2];
    MotionVector mv[2];
};

struct base_context;

struct de265_image {
    int PicOrderCntVal;
    int integrity;
    int (*available_pred_blk)(int,int,int,int,int,int,int,int,int,int);
    int (*get_pred_mode)(int,int);
    PBMotion (*get_mv_info)(int,int);
    struct base_context* decctx;
};

struct slice_segment_header {
    int RefPicList[2][MAX_NUM_REF_PICS];
    int LongTermRefPic[2][MAX_NUM_REF_PICS];
};

struct base_context {
    void (*add_warning)(int, bool);
    de265_image* (*get_image)(int);
};

enum LogMotion {
    LogMotion
};

static void logtrace(enum LogMotion, const char*, ...) {}
static void logmvcand(const PBMotion&) {}
static bool scale_mv(MotionVector*, MotionVector, int, int) { return false; }