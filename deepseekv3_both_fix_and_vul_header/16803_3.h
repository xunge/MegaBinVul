#include <stdint.h>

#define DE_CHAR_TIMES "×"

typedef struct deark deark;
typedef struct dbuf dbuf;
typedef int64_t i64;
typedef uint32_t u32;

struct fmtutil_macbitmap_info {
    int packing_type;
    double hdpi;
    double vdpi;
    int pixeltype;
    int pixelsize;
    int cmpcount;
    int cmpsize;
    int pdwidth;
    int npwidth;
    int rowbytes;
    u32 pmTable;
};

double pict_read_fixed(dbuf *f, i64 pos);
void de_dbg(deark *c, const char *fmt, ...);
void de_dbg_indent(deark *c, int indent);
uint16_t dbuf_getu16be(dbuf *f, i64 pos);
uint32_t dbuf_getu32be(dbuf *f, i64 pos);