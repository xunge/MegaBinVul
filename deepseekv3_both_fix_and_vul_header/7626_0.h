#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef int pj_status_t;
typedef size_t pj_ssize_t;
typedef off_t pj_off_t;
typedef int pj_oshandle_t;
typedef unsigned int pj_uint32_t;
typedef unsigned short pj_uint16_t;

struct pj_pool_t {
    void* (*alloc)(struct pj_pool_t*, unsigned);
};
typedef struct pj_pool_t pj_pool_t;

struct pj_str_t {
    char *ptr;
    pj_ssize_t slen;
};
typedef struct pj_str_t pj_str_t;

struct pjmedia_audio_format_detail {
    int clock_rate;
    int channel_count;
};
typedef struct pjmedia_audio_format_detail pjmedia_audio_format_detail;

struct pjmedia_port {
    struct {
        struct pj_str_t name;
        struct {
            int clock_rate;
            int channel_count;
            int bits_per_sample;
            int samples_per_frame;
        } fmt;
        struct pjmedia_audio_format_detail *audio;
    } info;
};
typedef struct pjmedia_port pjmedia_port;

struct pjmedia_wave_hdr {
    struct {
        unsigned int riff;
        unsigned int wave;
    } riff_hdr;
    struct {
        unsigned int fmt;
        unsigned int len;
        unsigned short fmt_tag;
        unsigned short nchan;
        unsigned int sample_rate;
        unsigned int bytes_per_sec;
        unsigned short block_align;
        unsigned short bits_per_sample;
    } fmt_hdr;
    struct {
        unsigned int data;
        unsigned int len;
    } data_hdr;
};
typedef struct pjmedia_wave_hdr pjmedia_wave_hdr;

struct pjmedia_wave_subchunk {
    unsigned int id;
    unsigned int len;
};
typedef struct pjmedia_wave_subchunk pjmedia_wave_subchunk;

enum pjmedia_wave_fmt_tag {
    PJMEDIA_WAVE_FMT_TAG_PCM = 1,
    PJMEDIA_WAVE_FMT_TAG_ALAW = 6,
    PJMEDIA_WAVE_FMT_TAG_ULAW = 7
};
typedef enum pjmedia_wave_fmt_tag pjmedia_wave_fmt_tag;

struct file_reader_port {
    pjmedia_port base;
    pj_oshandle_t fd;
    pj_off_t fsize;
    unsigned start_data;
    unsigned data_len;
    unsigned data_left;
    pj_off_t fpos;
    pj_uint32_t bufsize;
    char *buf;
    char *readpos;
    unsigned options;
    pjmedia_wave_fmt_tag fmt_tag;
    pj_uint16_t bytes_per_sample;
};

#define THIS_FILE "wav_player.c"
#define SIGNATURE 0x12345678
#define BITS_PER_SAMPLE 16
#define PJMEDIA_FILE_PORT_BUFSIZE 1024
#define TRACE_(x) printf x

#define PJMEDIA_RIFF_TAG 0x46464952
#define PJMEDIA_WAVE_TAG 0x45564157
#define PJMEDIA_FMT_TAG 0x20746D66
#define PJMEDIA_DATA_TAG 0x61746164

#define PJ_EINVAL (-1)
#define PJ_ENOTFOUND (-2)
#define PJ_ENOMEM (-3)
#define PJMEDIA_ENOTVALIDWAVE (-4)
#define PJMEDIA_EWAVEUNSUPP (-5)
#define PJMEDIA_EWAVETOOSHORT (-6)
#define PJ_SUCCESS 0

#define PJ_O_RDONLY O_RDONLY
#define PJ_SEEK_CUR SEEK_CUR

#define PJ_ASSERT_RETURN(expr, retval) if (!(expr)) return (retval)
#define PJMEDIA_WAVE_NORMALIZE_SUBCHUNK(subchunk)
#define PJ_CHECK_OVERFLOW_UINT32_TO_LONG(expr, action)

#define PJ_DEF(type) type

static int pj_file_exists(const char *filename);
static pj_off_t pj_file_size(const char *filename);
static void pjmedia_wave_hdr_file_to_host(pjmedia_wave_hdr *hdr);
static int pj_file_open(pj_pool_t *pool, const char *filename, int flags, pj_oshandle_t *fd);
static int pj_file_read(pj_oshandle_t fd, void *buf, pj_ssize_t *size);
static int pj_file_close(pj_oshandle_t fd);
static int pj_file_setpos(pj_oshandle_t fd, pj_ssize_t offset, int whence);
static int pj_file_getpos(pj_oshandle_t fd, pj_off_t *pos);
static struct file_reader_port *create_file_port(pj_pool_t *pool);
static int pjmedia_format_get_audio_format_detail(void *fmt, int dummy);
static void pj_strdup2(pj_pool_t *pool, pj_str_t *dst, const char *src);
static void pjmedia_port_info_init(void *info, pj_str_t *name, int signature,
                                  int sample_rate, int nchan, int bits_per_sample,
                                  int samples_per_frame);
static int fill_buffer(struct file_reader_port *fport);
static void PJ_LOG(int level, const char *format, ...);