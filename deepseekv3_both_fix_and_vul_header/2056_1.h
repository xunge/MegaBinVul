#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define EFTYPE EIO

typedef struct {
    const uint8_t *sst_tab;
} cdf_stream_t;

typedef struct {
} cdf_header_t;

typedef struct {
    uint32_t sh_len;
    uint32_t sh_properties;
} cdf_section_header_t;

typedef struct {
    uint32_t pi_id;
    uint32_t pi_type;
    union {
        int16_t pi_s16;
        int32_t pi_s32;
        uint32_t pi_u32;
        int64_t pi_s64;
        uint64_t pi_u64;
        uint64_t pi_tp;
        struct {
            uint32_t s_len;
            const char *s_buf;
        } pi_str;
    };
} cdf_property_info_t;

typedef uint64_t cdf_timestamp_t;

#define CAST(type, var) ((type)(var))
#define CDF_TOLE2(x) (x)
#define CDF_TOLE4(x) (x)
#define CDF_TOLE8(x) (x)
#define CDF_GETUINT32(p, i) (*(const uint32_t *)((const uint8_t *)(p) + (i)*4))
#define CDF_ROUND(x, y) (((x) + (y) - 1) & ~((y) - 1))
#define DPRINTF(x)

#define CDF_VECTOR 0x1000
#define CDF_ARRAY 0x2000
#define CDF_BYREF 0x4000
#define CDF_RESERVED 0x8000
#define CDF_TYPEMASK 0x0FFF

#define CDF_NULL 0
#define CDF_EMPTY 1
#define CDF_SIGNED16 2
#define CDF_SIGNED32 3
#define CDF_BOOL 11
#define CDF_UNSIGNED32 19
#define CDF_SIGNED64 20
#define CDF_UNSIGNED64 21
#define CDF_LENGTH32_STRING 31
#define CDF_LENGTH32_WSTRING 32
#define CDF_FILETIME 64
#define CDF_CLIPBOARD 71

int cdf_check_stream_offset(const cdf_stream_t *, const cdf_header_t *,
    const void *, size_t, int);