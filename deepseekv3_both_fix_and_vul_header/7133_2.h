#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef double Double;

typedef struct {
    u64 num, den;
} GF_Fraction64;

typedef struct {
    u64 pos;
    Double duration;
} MHASIdx;

typedef struct {
    int index;
    int index_size;
    int index_alloc_size;
    Bool is_file;
    Bool file_loaded;
    u32 timescale;
    u32 bitrate;
    GF_Fraction64 duration;
    void *opid;
    void *ipid;
    MHASIdx *indexes;
} GF_MHASDmxCtx;

typedef struct {
    union {
        char *string;
        Bool boolean;
    } value;
} GF_PropertyValue;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Filter GF_Filter;

#define GF_TRUE 1
#define GF_FALSE 0
#define GF_BITSTREAM_READ 0
#define GF_PROP_PID_FILEPATH 0
#define GF_PROP_PID_DURATION 0
#define GF_PROP_PID_FILE_CACHED 0
#define PROP_FRAC64(val) val

static const u32 USACSampleRates[] = {96000, 88200, 64000, 48000, 44100, 32000, 24000, 22050, 16000, 12000, 11025, 8000, 7350};
static const u32 nb_usac_sr = sizeof(USACSampleRates)/sizeof(USACSampleRates[0]);

extern GF_BitStream *gf_bs_from_file(FILE *stream, int mode);
extern void gf_bs_del(GF_BitStream *bs);
extern u32 gf_bs_available(GF_BitStream *bs);
extern u32 gf_bs_peek_bits(GF_BitStream *bs, u32 numBits, u32 byte_offset);
extern void gf_bs_skip_bytes(GF_BitStream *bs, u32 nbBytes);
extern u64 gf_bs_get_position(GF_BitStream *bs);
extern u64 gf_mpegh_escaped_value(GF_BitStream *bs, u32 leading_bits, u32 esc1_bits, u32 esc2_bits);
extern u32 gf_bs_read_int(GF_BitStream *bs, u32 nBits);
extern u8 gf_bs_read_u8(GF_BitStream *bs);
extern void gf_bs_align(GF_BitStream *bs);
extern FILE *gf_fopen_ex(const char *path, const char *mode, const char *sub_mode, Bool use_cache);
extern void gf_fclose(FILE *stream);
extern Bool gf_fileio_is_main_thread(const char *path);
extern void *gf_realloc(void *ptr, size_t size);
extern const GF_PropertyValue *gf_filter_pid_get_property(void *pid, u32 property);
extern void gf_filter_pid_set_property(void *pid, u32 property, void *value);
extern Bool gf_sys_is_test_mode(void);