#include <sys/types.h>
#include <assert.h>
#include <stdint.h>

typedef int64_t cdf_secid_t;

typedef struct cdf_info_t cdf_info_t;
typedef struct cdf_header_t cdf_header_t;

#define CDF_SEC_SIZE(h) (0)
#define CDF_SEC_POS(h, id) (0)

ssize_t cdf_read(const cdf_info_t *info, off_t pos, void *buf, size_t len);