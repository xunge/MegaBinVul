#include <sys/types.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>

#define SIZE_T_FORMAT "zu"

typedef int32_t cdf_secid_t;

typedef struct {
    uint16_t sec_size_p2;
    uint16_t short_sec_size_p2;
} cdf_header_t;

typedef struct {
    const uint8_t *sst_tab;
    size_t sst_len;
} cdf_stream_t;

#define CDF_SHORT_SEC_SIZE(h) (1 << (h)->short_sec_size_p2)
#define CDF_SHORT_SEC_POS(h, id) ((id) * CDF_SHORT_SEC_SIZE(h))
#define CDF_SEC_SIZE(h) (1 << (h)->sec_size_p2)

#define DPRINTF(x)