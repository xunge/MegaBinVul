#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t s32;
typedef int64_t s64;
typedef uint8_t u8;

#define GF_FILTER_NO_TS 0
#define GF_FILTER_NO_BO 0
#define GF_FILTER_SAP_1 1
#define GF_FILTER_SAP_4 4
#define GF_FILTER_SAP_4_PROL 5
#define GF_SHA1_DIGEST_SIZE 20
#define LLU "%lu"

typedef enum {
    GF_BITSTREAM_READ,
    GF_BITSTREAM_WRITE
} GF_BitStreamMode;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_FilterPacket GF_FilterPacket;
typedef u32 GF_FilterSAPType;
typedef struct GF_PropertyValue GF_PropertyValue;
typedef struct GF_NHMLDumpCtx GF_NHMLDumpCtx;

typedef enum {
    GF_PROP_PCK_SUBS
} GF_PropertyID;

typedef enum {
    GF_LOG_ERROR,
    GF_LOG_MEDIA
} GF_LogLevel;

typedef bool Bool;
#define GF_TRUE true
#define GF_FALSE false

struct GF_PropertyValue {
    union {
        struct {
            void *ptr;
            u32 size;
        } data;
    } value;
};

struct GF_NHMLDumpCtx {
    GF_BitStream *bs_w;
    GF_BitStream *bs_r;
    FILE *filep;
    u32 pck_num;
    u64 mdia_pos;
    u32 chksum;
    bool is_stpp;
    bool nhmlonly;
    bool pckp;
    bool first;
    char *nhml_buffer;
    u32 nhml_buffer_size;
    char *b64_buffer;
    u32 b64_buffer_size;
    u32 opid_nhml;
    u32 opid_mdia;
};

void gf_bs_write_data(GF_BitStream *bs, const char *data, u32 size);
GF_BitStream *gf_bs_new(const void *buffer, u32 size, GF_BitStreamMode mode);
void gf_bs_reassign_buffer(GF_BitStream *bs, const void *buffer, u32 size);
u32 gf_bs_available(GF_BitStream *bs);
u32 gf_bs_read_u32(GF_BitStream *bs);
u8 gf_bs_read_u8(GF_BitStream *bs);
void gf_bs_get_content_no_truncate(GF_BitStream *bs, char **output, u32 *out_size, u32 *alloc_size);
u32 gf_crc_32(const void *data, u32 size);
void gf_sha1_csum(const void *data, u32 size, u8 *hash);
u32 gf_base64_encode(const void *in, u32 in_size, char *out, u32 out_size);
void *gf_realloc(void *ptr, u32 size);
size_t gf_fwrite(const void *ptr, size_t size, FILE *stream);
GF_FilterPacket *gf_filter_pck_new_alloc(u32 pid, u32 size, u8 **data);
GF_FilterPacket *gf_filter_pck_new_ref(u32 pid, u32 offset, u32 size, GF_FilterPacket *src);
void gf_filter_pck_set_framing(GF_FilterPacket *pck, bool start, bool end);
void gf_filter_pck_send(GF_FilterPacket *pck);
void gf_filter_pck_merge_properties(GF_FilterPacket *src, GF_FilterPacket *dst);
u64 gf_filter_pck_get_dts(GF_FilterPacket *pck);
u64 gf_filter_pck_get_cts(GF_FilterPacket *pck);
GF_FilterSAPType gf_filter_pck_get_sap(GF_FilterPacket *pck);
u64 gf_filter_pck_get_byte_offset(GF_FilterPacket *pck);
u32 gf_filter_pck_get_duration(GF_FilterPacket *pck);
u32 gf_filter_pck_get_carousel_version(GF_FilterPacket *pck);
s32 gf_filter_pck_get_roll_info(GF_FilterPacket *pck);
const GF_PropertyValue *gf_filter_pck_get_property(GF_FilterPacket *pck, GF_PropertyID prop);
const GF_PropertyValue *gf_filter_pck_enum_properties(GF_FilterPacket *pck, u32 *idx, u32 *prop_4cc, const char **prop_name);
void GF_LOG(GF_LogLevel level, GF_LogLevel sub, const char *fmt, ...);
void nhmldump_pck_property(GF_NHMLDumpCtx *ctx, u32 prop_4cc, const char *prop_name, const GF_PropertyValue *p);