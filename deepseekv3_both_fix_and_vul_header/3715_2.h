#include <stdint.h>
#include <errno.h>
#include <stddef.h>

#define EFTYPE 79  /* Inappropriate file type or format */

typedef int32_t cdf_secid_t;

typedef struct {
    size_t sat_len;
    cdf_secid_t *sat_tab;
} cdf_sat_t;

#define CDF_LOOP_LIMIT 10000
#define DPRINTF(x)
#define CDF_TOLE4(x) (x)