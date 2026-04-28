#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define SEEK_SET 0

typedef struct AVIOContext {
    unsigned char *buffer;
    int buffer_size;
    int write_flag;
    void *opaque;
    int (*read_packet)(void *opaque, uint8_t *buf, int buf_size);
    int (*write_packet)(void *opaque, uint8_t *buf, int buf_size);
    int64_t (*seek)(void *opaque, int64_t offset, int whence);
    int64_t pos;
} AVIOContext;

typedef struct AVFormatContext {
    AVIOContext *pb;
} AVFormatContext;

typedef struct ID3v2ExtraMeta {
    void *data;
    struct ID3v2ExtraMeta *next;
} ID3v2ExtraMeta;

typedef struct ID3v2EMFunc {
    void (*read)(AVFormatContext *s, AVIOContext *pb, int taglen, const char *tag, ID3v2ExtraMeta **extra_meta);
} ID3v2EMFunc;

#define AV_LOG_DEBUG 0
#define AV_LOG_WARNING 1
#define AV_LOG_ERROR 2
#define AV_LOG_INFO 3

#define ID3v2_FLAG_UNSYNCH 0x1
#define ID3v2_FLAG_COMPRESSION 0x2
#define ID3v2_FLAG_ENCRYPTION 0x4
#define ID3v2_FLAG_DATALEN 0x8

#define CONFIG_ZLIB 0

static int64_t avio_tell(AVIOContext *s) { return s->pos; }
static void avio_skip(AVIOContext *s, int64_t offset) { s->pos += offset; }
static int avio_read(AVIOContext *s, void *buf, int size) { return 0; }
static uint32_t avio_rb32(AVIOContext *s) { return 0; }
static uint16_t avio_rb16(AVIOContext *s) { return 0; }
static uint8_t avio_r8(AVIOContext *s) { return 0; }
static uint32_t avio_rb24(AVIOContext *s) { return 0; }
static void avio_seek(AVIOContext *s, int64_t offset, int whence) { s->pos = offset; }
static void av_log(void *avcl, int level, const char *fmt, ...) {}
static void av_fast_malloc(void *ptr, unsigned int *size, size_t min_size) {}
static void av_free(void *ptr) { free(ptr); }
static void ffio_init_context(AVIOContext *s, unsigned char *buffer, int buffer_size, int write_flag, void *opaque, int (*read_packet)(void *opaque, uint8_t *buf, int buf_size), int (*write_packet)(void *opaque, uint8_t *buf, int buf_size), int64_t (*seek)(void *opaque, int64_t offset, int whence)) {}
static unsigned int get_size(AVIOContext *pb, int size) { return 0; }
static void read_ttag(AVFormatContext *s, AVIOContext *pb, int taglen, const char *tag) {}
static const ID3v2EMFunc *get_extra_meta_func(const char *tag, int isv34) { return NULL; }