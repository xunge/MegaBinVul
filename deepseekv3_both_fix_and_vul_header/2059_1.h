#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

typedef int32_t cdf_secid_t;

typedef struct {
    cdf_secid_t *sat_tab;
} cdf_sat_t;

typedef struct {
    size_t sst_len;
    size_t sst_dirlen;
    unsigned char *sst_tab;
} cdf_stream_t;

typedef struct {
    uint16_t h_sec_size_p2;
} cdf_header_t;

#define CDF_SEC_SIZE(h) (1 << (h)->h_sec_size_p2)
#define CDF_LOOP_LIMIT 10000
#define CDF_TOLE4(x) (x)
#define SIZE_T_FORMAT "zu"
#define DPRINTF(x) 

#define EFTYPE EINVAL

size_t cdf_count_chain(const cdf_sat_t *sat, cdf_secid_t sid, size_t size);
ssize_t cdf_read_short_sector(const cdf_stream_t *sst, void *buf, size_t offs, size_t len, const cdf_header_t *h, cdf_secid_t sid);