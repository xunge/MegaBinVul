#include <stdint.h>
#include <stdbool.h>

enum PredMode {
    MODE_SKIP,
    MODE_INTER
};

enum InterPredIdc {
    PRED_BI,
    PRED_L0,
    PRED_L1
};

enum {
    MAX_NUM_REF_PICS = 16,
    INTEGRITY_DECODING_ERRORS,
    DE265_WARNING_NONEXISTING_REFERENCE_PICTURE_ACCESSED
};

struct MotionVector {
    int32_t x;
    int32_t y;
};

struct PBMotion {
    int refIdx[2];
    int predFlag[2];
    MotionVector mv[2];
};

struct PBMotionCoding {
    bool merge_flag;
    int merge_idx;
    int inter_pred_idc;
    int refIdx[2];
    int mvd[2][2];
};

struct slice_segment_header {
};

struct de265_image {
    PredMode get_pred_mode(int x, int y);
    int integrity;
};

struct base_context {
    void add_warning(int warning, bool);
};

void derive_luma_motion_merge_mode(base_context* ctx,
                                 const slice_segment_header* shdr,
                                 de265_image* img,
                                 int xC, int yC, int xP, int yP,
                                 int nCS, int nPbW, int nPbH,
                                 int partIdx, int merge_idx,
                                 PBMotion* out_vi);

void logMV(int xP, int yP, int nPbW, int nPbH, const char* mode, PBMotion* out_vi);

MotionVector luma_motion_vector_prediction(base_context* ctx,
                                         const slice_segment_header* shdr,
                                         de265_image* img,
                                         const PBMotionCoding& motion,
                                         int xC, int yC, int nCS,
                                         int xP, int yP, int nPbW, int nPbH,
                                         int l, int refIdx, int partIdx);