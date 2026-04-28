#include <sys/time.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

typedef struct magic_set magic_set;
typedef struct cdf_directory_t {
    unsigned char d_storage_uuid[16];
} cdf_directory_t;
typedef int64_t cdf_timestamp_t;

typedef struct {
    uint32_t pi_id;
    uint32_t pi_type;
    union {
        int16_t pi_s16;
        int32_t pi_s32;
        uint32_t pi_u32;
        float pi_f;
        double pi_d;
        cdf_timestamp_t pi_tp;
        struct {
            uint32_t s_len;
            const char *s_buf;
        } pi_str;
    };
} cdf_property_info_t;

enum {
    CDF_NULL,
    CDF_SIGNED16,
    CDF_SIGNED32,
    CDF_UNSIGNED32,
    CDF_FLOAT,
    CDF_DOUBLE,
    CDF_LENGTH32_STRING,
    CDF_LENGTH32_WSTRING,
    CDF_FILETIME,
    CDF_CLIPBOARD,
    CDF_PROPERTY_NAME_OF_APPLICATION
};

extern const char *cdf_clsid_to_mime(const unsigned char *, const void *);
extern const char *cdf_app_to_mime(const char *, const void *);
extern int cdf_print_property_name(char *, size_t, uint32_t);
extern int cdf_print_elapsed_time(char *, size_t, cdf_timestamp_t);
extern int cdf_timestamp_to_timespec(struct timeval *, cdf_timestamp_t);
extern char *cdf_ctime(const time_t *, char *);
extern int file_printf(magic_set *, const char *, ...);
extern int NOTMIME(magic_set *);

static const void *clsid2mime;
static const void *app2mime;

#define private static