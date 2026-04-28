#include <stdint.h>
#include <assert.h>
#include <vector>
#include <cstdarg>

enum PredMode {
    MODE_INTRA
};

enum Integrity {
    INTEGRITY_UNAVAILABLE_REFERENCE,
    INTEGRITY_DECODING_ERRORS
};

enum de265_warning {
    DE265_WARNING_COLLOCATED_MOTION_VECTOR_OUTSIDE_IMAGE_AREA,
    DE265_WARNING_INVALID_SLICE_HEADER_INDEX_ACCESS,
    DE265_WARNING_INCORRECT_MOTION_VECTOR_SCALING
};

enum LogMotion {
    LogMotion
};

struct MotionVector {
    int x;
    int y;
};

struct PBMotion {
    int predFlag[2];
    MotionVector mv[2];
    int refIdx[2];
};

struct slice_segment_header;

struct de265_image {
    int get_width() const;
    int get_height() const;
    PredMode get_pred_mode(int x, int y) const;
    const PBMotion& get_mv_info(int x, int y) const;
    int get_SliceHeaderIndex(int x, int y) const;
    int PicOrderCntVal;
    Integrity integrity;
    std::vector<const slice_segment_header*> slices;
};

struct slice_segment_header {
    int num_ref_idx_l0_active;
    int num_ref_idx_l1_active;
    int RefPicList[2][16];
    bool LongTermRefPic[2][16];
    int RefPicList_POC[2][16];
    int collocated_from_l0_flag;
};

struct base_context {
    bool has_image(int pic) const;
    const de265_image* get_image(int pic) const;
    void add_warning(de265_warning, bool);
};

void logtrace(enum LogMotion, const char*, ...);
void logmvcand(const PBMotion&);
bool scale_mv(MotionVector*, MotionVector, int, int);