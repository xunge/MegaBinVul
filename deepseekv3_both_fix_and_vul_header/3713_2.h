#include <stddef.h>
#include <errno.h>

typedef struct {
    const void *sst_tab;
    size_t sst_dirlen;
    size_t sst_len;
} cdf_stream_t;

typedef struct {
    size_t h_min_size_standard_stream;
} cdf_header_t;

#define CDF_SHORT_SEC_SIZE(h) (1 << (h)->h_min_size_standard_stream)
#define CDF_SEC_SIZE(h) (1 << (h)->h_min_size_standard_stream)
#define SIZE_T_FORMAT "z"
#define DPRINTF(x)
#define EFTYPE EIO