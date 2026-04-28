#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define PJ_MAXPATH 260
#define PJ_FALSE 0
#define PJ_TRUE 1
#define PJMEDIA_FILE_PORT_BUFSIZE 1024
#define BYTES_PER_SAMPLE 2
#define THIS_FILE "wav_playlist.c"

typedef int pj_status_t;
typedef int pj_bool_t;
typedef int64_t pj_off_t;
typedef size_t pj_ssize_t;
typedef int pj_oshandle_t;
typedef uint32_t pj_uint32_t;

typedef struct {
    char *ptr;
    int slen;
} pj_str_t;

typedef struct {
    void *info;
} pj_pool_t;

typedef struct {
    struct {
        void *fmt;
    } info;
} pjmedia_port;

typedef struct {
    unsigned channel_count;
    unsigned clock_rate;
    unsigned bits_per_sample;
    unsigned frame_time_usec;
    unsigned avg_bps;
    unsigned max_bps;
} pjmedia_audio_format_detail;

typedef struct {
    uint32_t riff;
    uint32_t wave;
} pjmedia_riff_hdr;

typedef struct {
    uint32_t fmt;
    uint32_t len;
    uint16_t fmt_tag;
    uint16_t nchan;
    uint32_t sample_rate;
    uint32_t avg_bytes_per_sec;
    uint16_t block_align;
    uint16_t bits_per_sample;
} pjmedia_fmt_hdr;

typedef struct {
    uint32_t data;
    uint32_t len;
} pjmedia_data_hdr;

typedef struct {
    pjmedia_riff_hdr riff_hdr;
    pjmedia_fmt_hdr fmt_hdr;
    pjmedia_data_hdr data_hdr;
} pjmedia_wave_hdr;

typedef struct {
    uint32_t id;
    uint32_t len;
} pjmedia_wave_subchunk;

struct playlist_port {
    pjmedia_port base;
    unsigned options;
    pj_oshandle_t *fd_list;
    pj_off_t *fsize_list;
    unsigned *start_data_list;
    unsigned *data_len_list;
    unsigned *data_left_list;
    pj_off_t *fpos_list;
    pj_uint32_t bufsize;
    char *buf;
    char *readpos;
    int current_file;
    int max_file;
};

#define PJ_EINVAL 1
#define PJ_ETOOSMALL 2
#define PJ_ENAMETOOLONG 3
#define PJ_ENOTFOUND 4
#define PJ_ENOMEM 5
#define PJ_SUCCESS 0
#define PJMEDIA_ENOTVALIDWAVE 6
#define PJMEDIA_EWAVEUNSUPP 7
#define PJMEDIA_EWAVETOOSHORT 8
#define PJ_O_RDONLY 0
#define PJ_SEEK_CUR 1

#define PJ_ASSERT_RETURN(expr, retval) do { if (!(expr)) return (retval); } while(0)
#define PJ_CHECK_OVERFLOW_UINT32_TO_LONG(expr, action)
#define PJMEDIA_WAVE_NORMALIZE_SUBCHUNK(subchunk)
#define PJMEDIA_RIFF_TAG 0x46464952
#define PJMEDIA_WAVE_TAG 0x45564157
#define PJMEDIA_FMT_TAG 0x20746D66
#define PJMEDIA_DATA_TAG 0x61746164

#define PJ_DEF(ret_type) ret_type

static pj_str_t pj_str(const char *s) {
    pj_str_t str;
    str.ptr = (char*)s;
    str.slen = strlen(s);
    return str;
}

static void pj_memcpy(void *dst, const void *src, size_t len) {
    memcpy(dst, src, len);
}

static int pj_file_exists(const char *filename) {
    return 0;
}

static int pj_file_size(const char *filename) {
    return 0;
}

static pj_status_t pj_file_open(pj_pool_t *pool, const char *filename, int mode, pj_oshandle_t *fd) {
    return PJ_SUCCESS;
}

static pj_status_t pj_file_read(pj_oshandle_t fd, void *buf, pj_ssize_t *size) {
    return PJ_SUCCESS;
}

static pj_status_t pj_file_setpos(pj_oshandle_t fd, pj_off_t offset, int whence) {
    return PJ_SUCCESS;
}

static pj_status_t pj_file_getpos(pj_oshandle_t fd, pj_off_t *pos) {
    return PJ_SUCCESS;
}

static void pj_file_close(pj_oshandle_t fd) {
}

static void pjmedia_wave_hdr_file_to_host(pjmedia_wave_hdr *wavehdr) {
}

static void *pj_pool_alloc(pj_pool_t *pool, size_t size) {
    return NULL;
}

static void *pj_pool_zalloc(pj_pool_t *pool, size_t size) {
    return NULL;
}

static pjmedia_audio_format_detail *pjmedia_format_get_audio_format_detail(void *fmt, int b) {
    return NULL;
}

static struct playlist_port *create_file_list_port(pj_pool_t *pool, const pj_str_t *label) {
    return NULL;
}

static pj_status_t file_fill_buffer(struct playlist_port *fport) {
    return PJ_SUCCESS;
}

#define PJ_LOG(level, args)
#define TRACE_(args)