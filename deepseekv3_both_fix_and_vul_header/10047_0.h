#include <stdbool.h>
#include <stdint.h>

typedef struct jas_stream_s jas_stream_t;
typedef struct jp2_box_s jp2_box_t;

struct jp2_box_ops_s {
    int (*putdata)(jp2_box_t *box, jas_stream_t *out);
};

struct jp2_box_info_s {
    unsigned int flags;
};

struct jp2_box_s {
    uint_fast64_t len;
    uint32_t type;
    struct jp2_box_info_s *info;
    struct jp2_box_ops_s *ops;
};

#define JP2_BOX_SUPER 0x1
#define JP2_BOX_NODATA 0x2
#define JP2_BOX_HDRLEN(ext) ((ext) ? 16 : 8)

jas_stream_t *jas_stream_memopen(char *buf, int bufsize);
long jas_stream_tell(jas_stream_t *stream);
void jas_stream_rewind(jas_stream_t *stream);
int jas_stream_copy(jas_stream_t *out, jas_stream_t *in, long n);
int jas_stream_close(jas_stream_t *stream);
int jp2_putuint32(jas_stream_t *out, uint32_t val);
int jp2_putuint64(jas_stream_t *out, uint64_t val);