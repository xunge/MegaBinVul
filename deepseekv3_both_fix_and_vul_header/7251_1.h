#include <stdint.h>

#define R_API
typedef int64_t st64;
typedef uint64_t ut64;
typedef uint8_t ut8;

typedef struct r_buffer_t RBuffer;

enum {
    R_BUF_CUR,
    R_BUF_SET
};

st64 r_buf_seek(RBuffer *b, st64 addr, int whence);
st64 r_buf_fread(RBuffer *b, ut8 *buf, const char *fmt, int n);