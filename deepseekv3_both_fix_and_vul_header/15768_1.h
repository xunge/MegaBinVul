#include <stdbool.h>
#include <stdint.h>

typedef uint32_t u32;
typedef bool Bool;

#define GF_EXPORT
#define GF_TRUE true
#define GF_FALSE false

struct __elementary_stream_ifce {
    u32 bit_rate;
    u32 stream_type;
    u32 object_type_indication;
    u32 timescale;
    u32 repeat_rate;
    u32 caps;
    struct __elementary_stream_ifce *depends_on_stream;
    void *output_ctrl;
    void *output_udta;
};

typedef struct GF_M2TS_Mux_PMT {
    Bool table_needs_update;
} GF_M2TS_Mux_PMT;

typedef struct GF_M2TS_Mux_Stream {
    u32 pid;
    u32 mpeg2_stream_id;
    u32 mpeg2_stream_type;
    u32 table_id;
    u32 bit_rate;
    u32 scheduling_priority;
    u32 min_bytes_copy_from_next;
    Bool is_pcr;
    Bool force_single_au;
    Bool prevent_two_au_start_in_pes;
    Bool set_initial_disc;
    struct GF_M2TS_Mux_Program *program;
    struct __elementary_stream_ifce *ifce;
    struct GF_M2TS_Mux_Stream *next;
    void *loop_descriptors;
    void *mx;
    struct {
        u32 num;
        u32 den;
    } ts_scale;
} GF_M2TS_Mux_Stream;

typedef struct GF_M2TS_Mux_Program {
    GF_M2TS_Mux_Stream *streams;
    GF_M2TS_Mux_Stream *pcr;
    GF_M2TS_Mux_PMT *pmt;
    Bool initial_disc_set;
    u32 mpeg4_signaling;
    struct {
        u32 au_pes_mode;
    } *mux;
} GF_M2TS_Mux_Program;

enum {
    GF_STREAM_VISUAL,
    GF_STREAM_AUDIO,
    GF_STREAM_OD,
    GF_STREAM_SCENE,
    GF_STREAM_TEXT
};

enum {
    GPAC_OTI_VIDEO_MPEG4_PART2,
    GPAC_OTI_VIDEO_AVC,
    GPAC_OTI_VIDEO_SVC,
    GPAC_OTI_VIDEO_HEVC,
    GPAC_OTI_VIDEO_LHVC,
    GPAC_OTI_VIDEO_MPEG1,
    GPAC_OTI_VIDEO_MPEG2_SIMPLE,
    GPAC_OTI_VIDEO_MPEG2_MAIN,
    GPAC_OTI_VIDEO_MPEG2_SNR,
    GPAC_OTI_VIDEO_MPEG2_SPATIAL,
    GPAC_OTI_VIDEO_MPEG2_HIGH,
    GPAC_OTI_VIDEO_MPEG2_422,
    GPAC_OTI_IMAGE_JPEG,
    GPAC_OTI_IMAGE_PNG,
    GPAC_OTI_AUDIO_MPEG1,
    GPAC_OTI_AUDIO_MPEG2_PART3,
    GPAC_OTI_AUDIO_AAC_MPEG4,
    GPAC_OTI_AUDIO_AAC_MPEG2_MP,
    GPAC_OTI_AUDIO_AAC_MPEG2_LCP,
    GPAC_OTI_AUDIO_AAC_MPEG2_SSRP,
    GPAC_OTI_AUDIO_AC3
};

enum {
    GF_M2TS_VIDEO_MPEG4,
    GF_M2TS_VIDEO_H264,
    GF_M2TS_VIDEO_SVC,
    GF_M2TS_VIDEO_HEVC,
    GF_M2TS_VIDEO_HEVC_TEMPORAL,
    GF_M2TS_VIDEO_SHVC,
    GF_M2TS_VIDEO_MPEG1,
    GF_M2TS_VIDEO_MPEG2,
    GF_M2TS_SYSTEMS_MPEG4_PES,
    GF_M2TS_AUDIO_MPEG1,
    GF_M2TS_AUDIO_MPEG2,
    GF_M2TS_AUDIO_LATM_AAC,
    GF_M2TS_AUDIO_AAC,
    GF_M2TS_AUDIO_AC3,
    GF_M2TS_METADATA_PES,
    GF_M2TS_SYSTEMS_MPEG4_SECTIONS
};

enum {
    GF_M2TS_TABLE_ID_MPEG4_OD,
    GF_M2TS_TABLE_ID_MPEG4_BIFS
};

enum {
    GF_M2TS_PACK_ALL,
    GF_M2TS_PACK_NONE
};

enum {
    GF_ESI_STREAM_WITHOUT_MPEG4_SYSTEMS
};

enum {
    GF_M2TS_MPEG4_SIGNALING_FULL
};

GF_M2TS_Mux_Stream *gf_m2ts_stream_new(u32 pid);
void *gf_list_new();
void gf_m2ts_stream_add_hierarchy_descriptor(GF_M2TS_Mux_Stream *stream);
GF_M2TS_Mux_Stream *gf_m2ts_find_stream(GF_M2TS_Mux_Program *program, u32 dummy, struct __elementary_stream_ifce *ifce);
void gf_m2ts_stream_set_default_slconfig(GF_M2TS_Mux_Stream *stream);
void gf_m2ts_stream_add_metadata_pointer_descriptor(GF_M2TS_Mux_Program *program);
void gf_m2ts_stream_add_metadata_descriptor(GF_M2TS_Mux_Stream *stream);
void gf_m2ts_output_ctrl();
void *gf_mx_new(const char *name);