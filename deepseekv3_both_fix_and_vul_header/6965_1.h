#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define SEEK_SET 0
#define MAIN_STARTCODE 0
#define STREAM_STARTCODE 0
#define SYNCPOINT_STARTCODE 0
#define INFO_STARTCODE 0
#define AV_LOG_ERROR 0
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define AVERROR_INVALIDDATA (-1)
#define AVIO_SEEKABLE_NORMAL 0

typedef struct AVFormatContext AVFormatContext;
typedef struct AVIOContext AVIOContext;

struct AVFormatContext {
    void *priv_data;
    AVIOContext *pb;
    int nb_streams;
};

struct AVIOContext {
    int seekable;
};

typedef struct NUTContext {
    AVFormatContext *avf;
    uint64_t next_startcode;
} NUTContext;

typedef struct FFFormatContext {
    int data_offset;
} FFFormatContext;

static int64_t find_startcode(AVIOContext *bc, int code, int64_t pos) { return 0; }
static int decode_main_header(NUTContext *nut) { return 0; }
static int decode_stream_header(NUTContext *nut) { return 0; }
static uint64_t find_any_startcode(AVIOContext *bc, int64_t pos) { return 0; }
static int64_t avio_tell(AVIOContext *bc) { return 0; }
static void decode_info_header(NUTContext *nut) {}
static void find_and_decode_index(NUTContext *nut) {}
static void avio_seek(AVIOContext *bc, int64_t pos, int whence) {}
static void av_assert0(int condition) {}
static void ff_metadata_conv_ctx(AVFormatContext *s, void *a, void *b) {}
static void *ff_nut_metadata_conv;
static FFFormatContext *ffformatcontext(AVFormatContext *s) { return NULL; }
static void av_log(AVFormatContext *s, int level, const char *fmt, ...) {}