#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef int Bool;

#define GF_FALSE 0
#define GF_TRUE 1
#define GF_BITSTREAM_WRITE 1
#define GF_ESI_STREAM_WITHOUT_MPEG4_SYSTEMS 0x01
#define GF_LOG_DEBUG 1
#define GF_LOG_CONTAINER 2

#define GF_M2TS_AUDIO_AC3 0x81
#define GF_M2TS_VIDEO_VC1 0xEA
#define GF_M2TS_AUDIO_EC3 0x87
#define GF_M2TS_PRIVATE_DATA 0x06
#define GF_M2TS_MPEG4_IOD_DESCRIPTOR 0x1D
#define GF_M2TS_MPEG4_SL_DESCRIPTOR 0x1E
#define GF_M2TS_REGISTRATION_DESCRIPTOR 0x05
#define GF_M2TS_DVB_EAC3_DESCRIPTOR 0x7A
#define GF_M2TS_ISO_639_LANGUAGE_DESCRIPTOR 0x0A
#define GF_M2TS_TABLE_ID_PMT 0x02
#define GF_MEDIA_LANG_UND 0

typedef struct GF_BitStream GF_BitStream;

struct GF_M2TSDescriptor {
    u8 tag;
    u8 data_len;
    u8 *data;
};

struct GF_ObjectDescriptor {
    void *ESDescriptors;
};

struct GF_ESD {
    u32 ESID;
    void *slConfig;
};

struct GF_SLConfig {
    u8 dummy;
};

struct GF_M2TS_Mux_Stream {
    struct GF_M2TS_Mux_Stream *next;
    u32 pid;
    u8 mpeg2_stream_type;
    u32 table_needs_update;
    u32 table_needs_send;
    u32 refresh_rate_ms;
    struct {
        u32 stream_id;
        struct GF_SLConfig *sl_config;
        u32 caps;
        u32 lang;
    } *ifce;
    void *loop_descriptors;
    struct {
        u32 number;
        struct {
            u32 pid;
        } *pcr;
        struct GF_ObjectDescriptor *iod;
        void *loop_descriptors;
        struct GF_M2TS_Mux_Stream *streams;
    } *program;
};

struct GF_M2TS_Mux {
    void *dummy;
};

typedef struct GF_M2TS_Mux GF_M2TS_Mux;
typedef struct GF_M2TS_Mux_Stream GF_M2TS_Mux_Stream;
typedef struct GF_M2TSDescriptor GF_M2TSDescriptor;
typedef struct GF_ESD GF_ESD;
typedef struct GF_SLConfig GF_SLConfig;
typedef struct GF_ObjectDescriptor GF_ObjectDescriptor;

GF_BitStream *gf_bs_new(void *buffer, u32 size, u32 mode);
void gf_bs_write_int(GF_BitStream *bs, u32 value, u32 nBits);
void gf_bs_write_data(GF_BitStream *bs, const void *data, u32 length);
void gf_bs_get_content(GF_BitStream *bs, char **output, u32 *outSize);
void gf_bs_del(GF_BitStream *bs);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
void *gf_list_enum(void *list, u32 *index);
void gf_odf_write_descriptor(GF_BitStream *bs, void *desc);
void gf_free(void *ptr);
void gf_m2ts_mux_table_update(GF_M2TS_Mux_Stream *stream, u32 table_id, u32 program_number, u8 *payload, u32 length, Bool is_current, Bool is_next, Bool is_force);
void GF_LOG(u32 log_level, u32 log_tool, const char *fmt, ...);