#include <stddef.h>
#include <stdint.h>
#include <errno.h>

typedef struct cdf_stream_s {
    const unsigned char *sst_tab;
} cdf_stream_t;

typedef struct cdf_header_s {
    // Add necessary fields here
} cdf_header_t;

typedef struct cdf_summary_info_header_s {
    uint16_t si_byte_order;
    uint16_t si_os_version;
    uint16_t si_os;
    uint32_t si_class;
    uint32_t si_count;
} cdf_summary_info_header_t;

typedef struct cdf_property_info_s {
    // Add necessary fields here
} cdf_property_info_t;

typedef struct cdf_section_declaration_s {
    uint32_t sd_offset;
} cdf_section_declaration_t;

#define CAST(type, var) ((type)(var))
#define CDF_SECTION_DECLARATION_OFFSET 0
#define CDF_TOLE2(x) (x)
#define CDF_TOLE4(x) (x)
#define CDF_LOOP_LIMIT 10000
#define DPRINTF(x)
#define EFTYPE 79

int cdf_check_stream_offset(const cdf_stream_t *sst, const cdf_header_t *h,
    const void *p, size_t tail, int line);
void cdf_swap_class(uint32_t *class);
int cdf_read_property_info(const cdf_stream_t *sst, const cdf_header_t *h,
    uint32_t offs, cdf_property_info_t **info, size_t *count, size_t *maxcount);