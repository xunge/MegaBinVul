#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

typedef struct {
    const uint8_t *sst_tab;
} cdf_stream_t;

typedef struct {
} cdf_header_t;

typedef struct {
    uint32_t pi_id;
    uint32_t pi_type;
    union {
        int16_t pi_s16;
        int32_t pi_s32;
        uint32_t pi_u32;
        int64_t pi_s64;
        uint64_t pi_u64;
        float pi_f;
        double pi_d;
        struct {
            uint32_t s_len;
            const char *s_buf;
        } pi_str;
        uint64_t pi_tp;
    };
} cdf_property_info_t;

typedef struct {
    uint32_t sh_len;
    uint32_t sh_properties;
} cdf_section_header_t;

typedef uint64_t cdf_timestamp_t;

#define EFTYPE EIO

#define CAST(type, var) ((type)(var))
#define CDF_TOLE2(x) (x)
#define CDF_TOLE4(x) (x)
#define CDF_TOLE8(x) (x)
#define CDF_GETUINT32(p, i) (*(const uint32_t *)((const uint8_t *)(p) + (i)*4))
#define DPRINTF(x)
#define SIZE_T_FORMAT "z"
#define CDF_ROUND(l, s) (((l) + (s) - 1) & ~((s) - 1))
#define CDF_VECTOR 0x00001000
#define CDF_ARRAY 0x00002000
#define CDF_BYREF 0x00004000
#define CDF_RESERVED 0x00008000
#define CDF_TYPEMASK 0x00000FFF
#define CDF_NULL 0
#define CDF_EMPTY 1
#define CDF_SIGNED16 2
#define CDF_SIGNED32 3
#define CDF_BOOL 11
#define CDF_UNSIGNED32 19
#define CDF_SIGNED64 20
#define CDF_UNSIGNED64 21
#define CDF_FLOAT 5
#define CDF_DOUBLE 6
#define CDF_LENGTH32_STRING 8
#define CDF_LENGTH32_WSTRING 9
#define CDF_FILETIME 64
#define CDF_CLIPBOARD 71

static inline int cdf_check_stream_offset(const cdf_stream_t *sst, const cdf_header_t *h,
    const void *p, size_t tail, int line) {
    (void)sst; (void)h; (void)p; (void)tail; (void)line;
    return 0;
}