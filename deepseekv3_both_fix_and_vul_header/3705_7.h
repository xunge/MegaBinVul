#include <stdint.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

typedef int64_t cdf_timestamp_t;

struct cdf_property_info_t {
    uint32_t pi_id;
    uint32_t pi_type;
    union {
        int16_t pi_s16;
        int32_t pi_s32;
        uint32_t pi_u32;
        float pi_f;
        double pi_d;
        struct {
            uint32_t s_len;
            const char *s_buf;
        } pi_str;
        cdf_timestamp_t pi_tp;
    };
};

struct cdf_directory_t {
    uint64_t d_storage_uuid[2];
};

struct magic_set;

extern const char *cdf_clsid_to_mime(const uint64_t[2], const void *);
extern const char *cdf_app_to_mime(const char *, const void *);
extern int cdf_print_property_name(char *, size_t, uint32_t);
extern void cdf_print_elapsed_time(char *, size_t, cdf_timestamp_t);
extern void cdf_timestamp_to_timespec(struct timespec *, cdf_timestamp_t);
extern char *cdf_ctime(const time_t *, char *);
extern int file_printf(struct magic_set *, const char *, ...);

#define NOTMIME(ms) (0)

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

static const void *clsid2mime;
static const void *app2mime;

static int cdf_file_property_info_root(struct magic_set *ms, const struct cdf_property_info_t *info,
    size_t count, const struct cdf_directory_t *root_storage);
static int cdf_file_property_info_clsid(struct magic_set *ms, const struct cdf_property_info_t *info,
    size_t count, const uint64_t clsid[2]);

#define private static
#define cdf_property_info_t struct cdf_property_info_t
#define cdf_directory_t struct cdf_directory_t