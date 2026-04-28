#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef int32_t s32;
typedef double Double;

typedef enum {
    GF_FALSE = 0,
    GF_TRUE = 1
} GF_Bool;

typedef struct {
    int hdr_size;
    int frame_size;
    int sr_idx;
} ADTSHeader;

typedef struct {
    u64 pos;
    Double duration;
} ADTSIdx;

typedef struct {
    GF_Bool is_file;
    GF_Bool file_loaded;
    u32 index;
    u32 index_size;
    u32 index_alloc_size;
    ADTSIdx *indexes;
    u32 frame_size;
    u64 timescale;
    u32 bitrate;
    struct {
        s32 num;
        s32 den;
    } duration;
    void *ipid;
    void *opid;
} GF_ADTSDmxCtx;

typedef struct GF_Filter_t GF_Filter;
typedef struct GF_BitStream_t GF_BitStream;

typedef enum {
    GF_PROP_PID_FILEPATH,
    GF_PROP_PID_DURATION,
    GF_PROP_PID_FILE_CACHED
} GF_PropertyID;

typedef struct {
    union {
        char *string;
        GF_Bool boolean;
    } value;
} GF_PropertyValue;

typedef enum {
    GF_BITSTREAM_READ
} GF_BitStreamMode;

extern const u32 GF_M4ASampleRates[];
extern GF_BitStream *gf_bs_from_file(FILE *stream, GF_BitStreamMode mode);
extern GF_Bool adts_dmx_sync_frame_bs(GF_BitStream *bs, ADTSHeader *hdr);
extern u64 gf_bs_get_position(GF_BitStream *bs);
extern void gf_bs_skip_bytes(GF_BitStream *bs, u32 nbBytes);
extern void gf_bs_del(GF_BitStream *bs);
extern FILE *gf_fopen_ex(const char *filename, const char *mode, const char *sub_mode, GF_Bool shared);
extern void gf_fclose(FILE *stream);
extern GF_Bool gf_fileio_is_main_thread(const char *filename);
extern void *gf_realloc(void *ptr, size_t size);
extern const GF_PropertyValue *gf_filter_pid_get_property(void *pid, GF_PropertyID prop);
extern void gf_filter_pid_set_property(void *pid, GF_PropertyID prop, const void *value);
extern GF_Bool gf_sys_is_test_mode(void);

#define PROP_FRAC64(val) val