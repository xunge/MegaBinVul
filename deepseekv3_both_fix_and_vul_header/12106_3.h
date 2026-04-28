#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef uint32_t GF_Err;
typedef uint32_t u32;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint64_t u64;
typedef int Bool;

#define GF_FALSE 0
#define GF_TRUE 1

#define GF_LOG_ERROR 1
#define GF_LOG_CONTAINER 2

#define GF_PROP_DATA 1

typedef struct {
    union {
        uint32_t uint;
        Bool boolean;
        struct {
            u8 *ptr;
            u32 size;
        } data;
    } value;
    uint32_t type;
} GF_PropertyValue;

typedef struct {
    u32 track_num;
    u32 track_id;
    u32 stsd_idx;
    u32 clear_stsd_idx;
    u32 nb_samples;
    u32 samples_in_frag;
    u32 crypt_byte_block;
    u32 skip_byte_block;
    u32 def_crypt_byte_block;
    u32 def_skip_byte_block;
    u32 cenc_key_info_crc;
    u32 def_cenc_key_info_crc;
    u32 cenc_state;
    u32 cenc_frag_protected;
    u32 cenc_multikey;
    u32 cenc_subsamples;
    u32 constant_IV_size;
    u32 has_seig;
    u32 has_brands;
    u32 reused_stsd;
    GF_PropertyValue *cenc_ki;
    void *ipid;
} TrackWriter;

typedef struct {
    u32 file;
    u32 psshs;
    u32 store;
    u32 cmaf;
    u32 saio32;
} GF_MP4MuxCtx;

typedef struct {
    void *data;
    uint32_t type;
} GF_FilterPacket;

typedef struct {
    void *ptr;
    u32 size;
} GF_BitStream;

#define GF_OK 0
#define GF_SERVICE_ERROR 1
#define GF_NON_COMPLIANT_BITSTREAM 2
#define GF_NOT_SUPPORTED 3
#define GF_OUT_OF_MEM 4

#define GF_ISOM_BOX_TYPE_SENC 0x73656E63
#define GF_ISOM_BOX_UUID_PSEC 0x70736563
#define GF_ISOM_BRAND_OPF2 0x6F706632
#define GF_ISOM_OMADRM_SCHEME 0x6F6D6472

#define GF_PROP_PCK_CENC_SAI 0
#define GF_PROP_PID_PROTECTION_SCHEME_TYPE 0
#define GF_PROP_PID_PROTECTION_SCHEME_VERSION 0
#define GF_PROP_PID_CENC_STSD_MODE 0
#define GF_PROP_PID_ENCRYPTED 0
#define GF_PROP_PID_CENC_STORE 0
#define GF_PROP_PID_CENC_PSSH 0

#define CENC_SETUP_ERROR 0
#define CENC_NEED_SETUP 1
#define CENC_SETUP_DONE 2
#define CENC_CONFIG 0
#define CENC_ADD_FRAG 1

#define MP4MX_PSSH_MOOV 0
#define MP4MX_PSSH_BOTH 1
#define MP4MX_MODE_FRAG 0

#define GF_BITSTREAM_WRITE 0

#define GF_4CC(a,b,c,d) ((a)<<24 | (b)<<16 | (c)<<8 | (d))

static GF_Err gf_filter_pck_get_crypt_flags(GF_FilterPacket *pck) { return 0; }
static const GF_PropertyValue *gf_filter_pck_get_property(GF_FilterPacket *pck, u32 prop) { return NULL; }
static const GF_PropertyValue *gf_filter_pid_get_property(void *ipid, u32 prop) { return NULL; }
static GF_Err gf_isom_clone_sample_description(u32 file, u32 track_num, u32 file2, u32 track_num2, u32 stsd_idx, void *a, void *b, u32 *clone_stsd_idx) { return 0; }
static GF_Err gf_isom_set_cenc_protection(u32 file, u32 track_num, u32 stsd_idx, u32 scheme_type, u32 scheme_version, Bool encrypted, u32 crypt_byte_block, u32 skip_byte_block, u8 *key_info, u32 key_info_size) { return 0; }
static u32 gf_isom_get_sample_description_count(u32 file, u32 track_num) { return 0; }
static Bool gf_isom_is_same_sample_description(u32 file, u32 track_num, u32 stsd_idx, u32 file2, u32 track_num2, u32 stsd_idx2) { return 0; }
static GF_Err gf_isom_remove_stream_description(u32 file, u32 track_num, u32 stsd_idx) { return 0; }
static GF_Err gf_isom_modify_alternate_brand(u32 file, u32 brand, Bool enable) { return 0; }
static GF_Err gf_isom_piff_allocate_storage(u32 file, u32 track_num, u32 a, u32 b, void *c) { return 0; }
static GF_Err gf_isom_cenc_allocate_storage(u32 file, u32 track_num) { return 0; }
static GF_Err gf_isom_fragment_set_cenc_sai(u32 file, u32 track_id, u8 *sai, u32 sai_size, Bool subsamples, u32 saio32, u32 multikey) { return 0; }
static GF_Err gf_isom_track_cenc_add_sample_info(u32 file, u32 track_num, u32 box_type, u8 *sai, u32 sai_size, Bool subsamples, u32 saio32, u32 multikey) { return 0; }
static GF_Err gf_isom_set_sample_cenc_group(u32 file, u32 track_num, u32 sample_num, Bool encrypted, u32 crypt_byte_block, u32 skip_byte_block, u8 *key_info, u32 key_info_size) { return 0; }
static GF_Err gf_isom_set_sample_cenc_default_group(u32 file, u32 track_num, u32 sample_num) { return 0; }
static GF_Err gf_isom_set_sample_group_description(u32 file, u32 track_num, u32 sample_num, u32 type, u32 a, u8 *data, u32 size, u32 b) { return 0; }
static void mp4_mux_cenc_insert_pssh(GF_MP4MuxCtx *ctx, TrackWriter *tkw, const GF_PropertyValue *p, u32 a) {}
static const char *gf_error_to_string(GF_Err e) { return ""; }
static void GF_LOG(u32 level, u32 category, const char *fmt, ...) {}

static GF_BitStream *gf_bs_new(void *data, u32 size, u32 mode) { return NULL; }
static void gf_bs_write_u16(GF_BitStream *bs, u16 val) {}
static void gf_bs_write_long_int(GF_BitStream *bs, u64 val, u32 bits) {}
static void gf_bs_write_u32(GF_BitStream *bs, u32 val) {}
static void gf_bs_get_content(GF_BitStream *bs, u8 **data, u32 *size) {}
static void gf_bs_del(GF_BitStream *bs) {}
static void *gf_malloc(u32 size) { return NULL; }
static void gf_free(void *ptr) {}

static u8 key_info_get_iv_size(const u8 *key_info, u32 nb_keys, u32 idx, u8 *const_iv_size, const u8 **const_iv) { return 0; }