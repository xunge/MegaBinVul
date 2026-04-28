#include <stdint.h>
#include <stddef.h>

#define DE_CREATEFLAG_IS_AUX 0

typedef struct deark deark;
typedef struct lctx lctx;
typedef int64_t i64;

struct lctx {
    void *iccprofile_file;
};

struct deark {
    void *infile;
};

void de_dbg(deark *c, const char *fmt, ...);
void *dbuf_create_output_file(deark *c, const char *ext, const char *modifier, int flags);
void dbuf_close(void *f);
void dbuf_copy(void *infile, i64 pos, i64 len, void *outfile);
uint32_t de_getu32be(i64 pos);