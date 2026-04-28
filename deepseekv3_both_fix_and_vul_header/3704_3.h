#include <stdint.h>
#include <stdlib.h>

struct magic_set;
typedef struct cdf_header_t cdf_header_t;
typedef struct cdf_stream_t cdf_stream_t;
typedef struct cdf_directory_t {
    uint8_t d_storage_uuid[16];
} cdf_directory_t;
typedef struct cdf_summary_info_header_t {
    uint16_t si_byte_order;
    uint16_t si_os;
    uint16_t si_os_version;
} cdf_summary_info_header_t;
typedef struct cdf_property_info_t cdf_property_info_t;

extern int cdf_unpack_summary_info(const cdf_stream_t *, const cdf_header_t *, 
    cdf_summary_info_header_t *, cdf_property_info_t **, size_t *);
extern int file_printf(struct magic_set *, const char *, ...);
extern const char *cdf_clsid_to_mime(const uint8_t[16], const void *);
extern int cdf_file_property_info(struct magic_set *, const cdf_property_info_t *, 
    size_t, const cdf_directory_t *);

#define NOTMIME(ms) (0)
static const void *clsid2desc;

#define private static