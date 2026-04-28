#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define protected static
#define MAGIC_APPLE 0x0001
#define CDF_DEBUG
#define NOTMIME(ms) ((ms)->flags & 0x0002)
#define __arraycount(arr) (sizeof(arr)/sizeof((arr)[0]))

typedef struct magic_set magic_set;
typedef struct cdf_info cdf_info_t;
typedef struct cdf_header cdf_header_t;
typedef struct cdf_sat cdf_sat_t;
typedef struct cdf_stream cdf_stream_t;
typedef struct cdf_dir cdf_dir_t;
typedef struct cdf_directory cdf_directory_t;

struct magic_set {
    int flags;
};

struct cdf_info {
    int i_fd;
    const unsigned char *i_buf;
    size_t i_len;
};

struct cdf_header {
    size_t h_sec_size;
    size_t h_short_sec_size;
};

struct cdf_sat {
    void *sat_tab;
};

struct cdf_stream {
    void *sst_tab;
};

struct cdf_dir {
    cdf_directory_t *dir_tab;
    size_t dir_len;
};

struct cdf_directory {
    unsigned char d_name[32];
    unsigned char d_storage_uuid[16];
};

#define CDF_SEC_SIZE(h) ((h)->h_sec_size)
#define CDF_SHORT_SEC_SIZE(h) ((h)->h_short_sec_size)

static const char *name2desc = "description";
static const char *name2mime = "mimetype";

int cdf_read_header(const cdf_info_t *, cdf_header_t *);
int cdf_read_sat(const cdf_info_t *, const cdf_header_t *, cdf_sat_t *);
int cdf_read_ssat(const cdf_info_t *, const cdf_header_t *, const cdf_sat_t *, cdf_sat_t *);
int cdf_read_dir(const cdf_info_t *, const cdf_header_t *, const cdf_sat_t *, cdf_dir_t *);
int cdf_read_short_stream(const cdf_info_t *, const cdf_header_t *, const cdf_sat_t *, const cdf_dir_t *, cdf_stream_t *, const cdf_directory_t **);
int cdf_read_summary_info(const cdf_info_t *, const cdf_header_t *, const cdf_sat_t *, const cdf_sat_t *, const cdf_stream_t *, const cdf_dir_t *, cdf_stream_t *);
int cdf_file_summary_info(magic_set *, const cdf_header_t *, const cdf_stream_t *, const unsigned char *);
const char *cdf_app_to_mime(const char *, const char *);
int file_printf(magic_set *, const char *, ...);
void cdf_dump_header(const cdf_header_t *);
void cdf_dump_sat(const char *, const cdf_sat_t *, size_t);
void cdf_dump_dir(const cdf_info_t *, const cdf_header_t *, const cdf_sat_t *, const cdf_sat_t *, const cdf_stream_t *, const cdf_dir_t *);
void cdf_dump_summary_info(const cdf_header_t *, const cdf_stream_t *);
unsigned short cdf_tole2(unsigned short);