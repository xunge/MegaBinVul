#include <sys/types.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

typedef int32_t cdf_secid_t;

typedef struct {
    size_t sst_len;
    const char *sst_tab;
} cdf_stream_t;

typedef struct {
    uint16_t h_sec_size_p2;
    uint16_t h_short_sec_size_p2;
} cdf_header_t;

#define CDF_SHORT_SEC_SIZE(h) (1 << (h)->h_short_sec_size_p2)
#define CDF_SHORT_SEC_POS(h, id) (id) * CDF_SHORT_SEC_SIZE(h)
#define DPRINTF(x)