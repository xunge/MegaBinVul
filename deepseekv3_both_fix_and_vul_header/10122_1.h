#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

typedef struct jp2_box_t jp2_box_t;
typedef struct jp2_boxinfo_t jp2_boxinfo_t;
typedef struct jas_stream_t jas_stream_t;

struct jp2_box_t {
    uint_fast32_t type;
    uint_fast64_t len;
    uint_fast64_t datalen;
    const jp2_boxinfo_t *info;
    const struct jp2_boxops_t *ops;
};

struct jp2_boxops_t {
    int (*getdata)(jp2_box_t *box, jas_stream_t *in);
};

struct jp2_boxinfo_t {
    const char *name;
    unsigned int flags;
    struct jp2_boxops_t ops;
};

extern jp2_boxinfo_t jp2_boxinfo_unk;
extern int jp2_getuint32(jas_stream_t *in, uint_fast32_t *val);
extern int jp2_getuint64(jas_stream_t *in, uint_fast64_t *val);
extern jp2_boxinfo_t *jp2_boxinfolookup(uint_fast32_t type);
extern void jp2_box_dump(jp2_box_t *box, FILE *out);
extern void jp2_box_destroy(jp2_box_t *box);
extern void *jas_malloc(size_t size);
extern void jas_eprintf(const char *format, ...);
extern int jas_getdbglevel(void);
extern jas_stream_t *jas_stream_memopen(char *buf, int bufsize);
extern int jas_stream_copy(jas_stream_t *out, jas_stream_t *in, int cnt);
extern void jas_stream_rewind(jas_stream_t *stream);
extern void jas_stream_close(jas_stream_t *stream);

#define JAS_DBGLOG(level, ...)
#define JP2_BOX_HDRLEN(ext) ((ext) ? 16 : 8)
#define JP2_BOX_SUPER 0x1
#define JP2_BOX_NODATA 0x2