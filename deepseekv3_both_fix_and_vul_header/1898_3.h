#include <stdint.h>
#include <memory>
#include <cassert>

#define MAX_CU_SIZE 64
#define MAX_NUM_REF_PICS 16
#define ALIGNED_16(x) x __attribute__((aligned(16)))

enum LogType {
    LogMotion,
    LogTransform
};

void logtrace(LogType, const char*, ...);

enum {
    INTEGRITY_DECODING_ERRORS,
    UnusedForReference
};

enum {
    DE265_WARNING_BIT_DEPTH_OF_CURRENT_IMAGE_DOES_NOT_MATCH_SPS,
    DE265_WARNING_NONEXISTING_REFERENCE_PICTURE_ACCESSED,
    DE265_WARNING_BOTH_PREDFLAGS_ZERO
};

enum {
    SLICE_TYPE_P,
    SLICE_TYPE_B
};

struct MV {
    int x, y;
};

struct PBMotion {
    int predFlag[2];
    int refIdx[2];
    MV mv[2];
};

struct seq_parameter_set {
    int BitDepth_Y;
    int BitDepth_C;
    int SubWidthC;
    int SubHeightC;
    int WpOffsetBdShiftY;
    int WpOffsetBdShiftC;
};

struct pic_parameter_set {
    int weighted_pred_flag;
    int weighted_bipred_flag;
    std::shared_ptr<seq_parameter_set> sps;
};

struct slice_segment_header {
    int slice_type;
    int luma_log2_weight_denom;
    int ChromaLog2WeightDenom;
    int LumaWeight[2][16];
    int luma_offset[2][16];
    int ChromaWeight[2][16][2];
    int ChromaOffset[2][16][2];
    int RefPicList[2][16];
    std::shared_ptr<pic_parameter_set> pps;
};

struct de265_image {
    int integrity;
    int PicState;
    int PicOrderCntVal;
    int get_bit_depth(int) const;
    const void* get_image_plane(int) const;
    void* get_image_plane_at_pos_any_depth(int, int, int);
    int get_image_stride(int) const;
    int get_luma_stride() const;
    int get_chroma_stride() const;
    bool high_bit_depth(int) const;
    seq_parameter_set get_sps() const;
};

struct base_context {
    void add_warning(int, bool);
    const de265_image* get_image(int);
    struct {
        void put_unweighted_pred(void*, int, int16_t*, int, int, int, int);
        void put_weighted_pred(void*, int, int16_t*, int, int, int, int, int, int, int);
        void put_weighted_pred_avg(void*, int, int16_t*, int16_t*, int, int, int, int);
        void put_weighted_bipred(void*, int, int16_t*, int16_t*, int, int, int, int, int, int, int, int, int);
    } acceleration;
};

void mc_luma(base_context*, const seq_parameter_set*, int, int, int, int, int16_t*, int, const void*, int, int, int, int);
void mc_chroma(base_context*, const seq_parameter_set*, int, int, int, int, int16_t*, int, const void*, int, int, int, int);

int libde265_max(int a, int b) { return a > b ? a : b; }