#include <stddef.h>

#define CDF_DIR_TYPE_ROOT_STORAGE 5

struct cdf_directory_t {
    int d_type;
    int d_stream_first_sector;
    size_t d_size;
};

struct cdf_dir_t {
    size_t dir_len;
    struct cdf_directory_t *dir_tab;
};

struct cdf_stream_t {
    void *sst_tab;
    size_t sst_len;
    size_t sst_dirlen;
};

typedef struct cdf_info_s cdf_info_t;
typedef struct cdf_header_s cdf_header_t;
typedef struct cdf_sat_s cdf_sat_t;
typedef struct cdf_dir_t cdf_dir_t;
typedef struct cdf_stream_t cdf_stream_t;
typedef struct cdf_directory_t cdf_directory_t;

int cdf_read_long_sector_chain(const cdf_info_t *, const cdf_header_t *,
    const cdf_sat_t *, int, size_t, cdf_stream_t *);