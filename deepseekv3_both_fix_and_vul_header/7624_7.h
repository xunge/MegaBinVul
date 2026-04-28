#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>

#define SIGNATURE 0x41564952
#define THIS_FILE "avi_reader.c"
#define VIDEO_CLOCK_RATE 90000
#define AVI_EOF (-1)
#define PJ_EEOF (-2)
#define PJ_SUCCESS 0
#define PJ_EINVAL (-3)
#define PJ_FALSE 0
#define PJ_TRUE 1
#define PJMEDIA_FRAME_TYPE_NONE 0
#define PJMEDIA_FRAME_TYPE_AUDIO 1
#define PJMEDIA_FRAME_TYPE_VIDEO 2
#define PJMEDIA_TYPE_AUDIO 1
#define PJMEDIA_TYPE_VIDEO 2
#define PJMEDIA_FORMAT_PCMA 1
#define PJMEDIA_FORMAT_PCMU 2
#define PJMEDIA_AVI_FILE_NO_LOOP 0x01
#define PJMEDIA_EVENT_CALLBACK 1
#define PJMEDIA_EVENT_PUBLISH_POST_EVENT 1
#define PJ_SEEK_SET SEEK_SET
#define PJ_SEEK_CUR SEEK_CUR

#define PJ_CHECK_OVERFLOW_UINT32_TO_LONG(val, action) \
    do { if ((val) > LONG_MAX) { action; } } while(0)

typedef int pj_status_t;
typedef int pj_bool_t;
typedef int64_t pj_off_t;
typedef uint8_t pj_uint8_t;
typedef uint16_t pj_uint16_t;
typedef uint32_t pj_uint32_t;
typedef long pj_ssize_t;
typedef void* pj_file_t;

typedef struct pj_timestamp {
    uint64_t u64;
} pj_timestamp;

typedef struct pjmedia_audio_format {
    int clock_rate;
    int avg_bps;
} pjmedia_audio_format;

typedef struct pjmedia_video_format {
    int avg_bps;
} pjmedia_video_format;

typedef struct pjmedia_format {
    int type;
    union {
        pjmedia_audio_format aud;
        pjmedia_video_format vid;
    } det;
} pjmedia_format;

typedef struct pjmedia_port_info {
    int signature;
    struct {
        char *ptr;
        int slen;
    } name;
    pjmedia_format fmt;
} pjmedia_port_info;

typedef struct pjmedia_port_data {
    void *pdata;
} pjmedia_port_data;

typedef struct pjmedia_port {
    pjmedia_port_info info;
    pjmedia_port_data port_data;
} pjmedia_port;

typedef struct pjmedia_frame {
    int type;
    int size;
    void *buf;
    pj_timestamp timestamp;
} pjmedia_frame;

typedef struct pjmedia_event {
    int type;
    void *src;
    void *data;
} pjmedia_event;

typedef pj_status_t (*pjmedia_port_cb)(pjmedia_port*, void*);
typedef pj_status_t (*pjmedia_port_data_cb)(pjmedia_port*, void*);

struct avi_reader_port {
    pjmedia_port base;
    pj_off_t start_data;
    pj_off_t size_left;
    pj_uint8_t pad;
    pj_bool_t eof;
    pj_bool_t subscribed;
    int fmt_id;
    unsigned stream_id;
    unsigned bits_per_sample;
    unsigned usec_per_frame;
    pj_timestamp next_ts;
    pj_file_t *fd;
    pjmedia_port_cb cb;
    pjmedia_port_data_cb cb2;
    unsigned options;
};

typedef struct pjmedia_avi_subchunk {
    pj_uint32_t id;
    pj_uint32_t len;
} pjmedia_avi_subchunk;

#define COMPARE_TAG(id, tag) (id == tag)
#define PJMEDIA_AVI_LIST_TAG 0x4C495354
#define PJMEDIA_AVI_RIFF_TAG 0x52494646

static void pj_assert(int expr) { if(!(expr)) {} }
static void PJ_LOG(int level, const char *format, ...) {}
static void TRACE_(const char *format, ...) {}
static pj_status_t pj_file_setpos(pj_file_t *fd, pj_off_t offset, int whence) { return 0; }
static pj_status_t pj_file_getpos(pj_file_t *fd, pj_off_t *pos) { return 0; }
static void pj_bzero(void *buf, size_t size) { memset(buf, 0, size); }
static pj_uint16_t pjmedia_ulaw2linear(pj_uint8_t val) { return 0; }
static pj_uint16_t pjmedia_alaw2linear(pj_uint8_t val) { return 0; }
static pj_status_t pjmedia_event_subscribe(void *pool, void *cb, void *user_data, void *port) { return 0; }
static void pjmedia_event_init(pjmedia_event *event, int type, void *src, void *port) {}
static void pjmedia_event_publish(void *pool, void *port, pjmedia_event *event, int flag) {}
static void file_on_event(pjmedia_event *event, void *user_data) {}
static pj_status_t file_read(pj_file_t *fd, void *buf, pj_ssize_t size) { return 0; }
static pj_status_t file_read3(pj_file_t *fd, void *buf, pj_ssize_t size, 
                             unsigned bits_per_sample, pj_ssize_t *size_read) { return 0; }