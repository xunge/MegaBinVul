#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef unsigned char Bool;
#define GF_TRUE 1
#define GF_FALSE 0

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed long long s32;
typedef signed long long s64;

typedef enum {
    GF_OK = 0,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM,
    GF_ISOM_INCOMPLETE_FILE,
    GF_ISOM_INVALID_FILE,
    GF_SKIP_BOX
} GF_Err;

#define GF_ISOM_BOX_TYPE_VOID 0
#define GF_ISOM_BOX_TYPE_TOTL 0
#define GF_ISOM_BOX_TYPE_UUID 0
#define GF_ISOM_BOX_TYPE_MOOF 0
#define GF_ISOM_BOX_TYPE_MOOV 0
#define GF_ISOM_BOX_TYPE_SIDX 0
#define GF_ISOM_BOX_TYPE_SSIX 0
#define GF_ISOM_BOX_TYPE_STSD 0
#define GF_ISOM_BOX_TYPE_TREF 0
#define GF_ISOM_BOX_TYPE_IREF 0
#define GF_ISOM_BOX_TYPE_TRGR 0
#define GF_ISOM_BOX_TYPE_GRPL 0
#define GF_QT_SUBTYPE_RAW 0
#define GF_QT_SUBTYPE_RAW_VID 0
#define GF_QT_SUBTYPE_RAW_AUD 0
#define GF_ISOM_BOX_TYPE_REFT 0
#define GF_ISOM_BOX_TYPE_REFI 0
#define GF_ISOM_BOX_TYPE_TRGT 0
#define GF_ISOM_BOX_TYPE_GRPT 0

#define GF_ISOM_BS_COOKIE_NO_LOGS 0
#define GF_ISOM_BS_COOKIE_VISUAL_TRACK 0
#define GF_ISOM_BOX_COMPRESSED 0

#define LLD "%lld"
#define LLU "%llu"

typedef struct GF_BitStream {
    u64 position;
    u64 size;
    u8* data;
    u32 cookie;
} GF_BitStream;

typedef struct GF_Box {
    u32 type;
    u64 size;
    u32 internal_flags;
} GF_Box;

typedef struct GF_UUIDBox {
    GF_Box box;
    char uuid[16];
    u32 internal_4cc;
} GF_UUIDBox;

typedef struct GF_TrackReferenceTypeBox {
    GF_Box box;
    u32 reference_type;
} GF_TrackReferenceTypeBox;

typedef struct GF_ItemReferenceTypeBox {
    GF_Box box;
    u32 reference_type;
} GF_ItemReferenceTypeBox;

typedef struct GF_TrackGroupTypeBox {
    GF_Box box;
    u32 group_type;
} GF_TrackGroupTypeBox;

typedef struct GF_EntityToGroupTypeBox {
    GF_Box box;
    u32 grouping_type;
} GF_EntityToGroupTypeBox;

typedef struct GF_MovieFragmentBox {
    GF_Box box;
    s32 compressed_diff;
} GF_MovieFragmentBox;

typedef struct GF_MovieBox {
    GF_Box box;
    s32 compressed_diff;
    u64 file_offset;
} GF_MovieBox;

typedef struct GF_SegmentIndexBox {
    GF_Box box;
    s32 compressed_diff;
} GF_SegmentIndexBox;

typedef struct GF_SubsegmentIndexBox {
    GF_Box box;
    s32 compressed_diff;
} GF_SubsegmentIndexBox;

typedef enum {
    GF_LOG_DEBUG = 0,
    GF_LOG_ERROR,
    GF_LOG_WARNING,
    GF_LOG_CONTAINER
} GF_LogLevel;

typedef enum {
    GF_BITSTREAM_READ = 0
} GF_BitStreamMode;

static u32 unused_bytes = 0;

u32 gf_bs_get_cookie(GF_BitStream *bs);
u32 gf_bs_available(GF_BitStream *bs);
u64 gf_bs_get_position(GF_BitStream *bs);
u32 gf_bs_read_u32(GF_BitStream *bs);
u64 gf_bs_read_u64(GF_BitStream *bs);
void gf_bs_read_data(GF_BitStream *bs, char *data, u32 size);
void gf_bs_seek(GF_BitStream *bs, u64 offset);
u32 gf_bs_peek_bits(GF_BitStream *bs, u32 numBits, u32 byte_offset);
void gf_bs_skip_bytes(GF_BitStream *bs, u32 nbBytes);
GF_BitStream *gf_bs_new(u8 *data, u32 size, u32 mode);
void gf_bs_del(GF_BitStream *bs);

GF_Box *gf_isom_box_new(u32 type);
GF_Box *gf_isom_box_new_ex(u32 type, u32 parent_type, Bool skip_logs, Bool is_root_box);
void gf_isom_box_del(GF_Box *box);
GF_Err gf_isom_full_box_read(GF_Box *box, GF_BitStream *bs);
GF_Err gf_isom_box_read(GF_Box *box, GF_BitStream *bs);
const char *gf_4cc_to_str(u32 type);
u32 gf_isom_solve_uuid_box(char *uuid);
void *gf_malloc(u32 size);
void gf_free(void *ptr);
GF_Err gf_gz_decompress_payload(u8 *compressed, u32 compressed_size, u8 **uncompressed, u32 *uncompressed_size);
const char *gf_error_to_string(GF_Err e);
Bool gf_opts_get_bool(const char *category, const char *name);
u32 GF_4CC(char a, char b, char c, char d);

void GF_LOG(GF_LogLevel level, GF_LogLevel subsystem, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}