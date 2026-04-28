#include <sys/types.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#define SIZE_T_FORMAT "zu"

typedef int32_t cdf_secid_t;

typedef struct {
    uint16_t h_sec_size_p2;
    uint16_t h_short_sec_size_p2;
} cdf_header_t;

typedef struct {
    const void *sst_tab;
    size_t sst_len;
} cdf_stream_t;

#define CDF_SEC_SIZE(h) (1 << (h)->h_sec_size_p2)
#define CDF_SHORT_SEC_POS(h, id) ((id) * (1 << (h)->h_short_sec_size_p2))

#define DPRINTF(x)