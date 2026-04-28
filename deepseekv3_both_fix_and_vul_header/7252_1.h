#include <stdint.h>

#define R_API
typedef struct RBuffer RBuffer;
typedef int64_t st64;
typedef uint64_t ut64;
typedef uint8_t ut8;

#define R_BUF_CUR 0
#define R_BUF_SET 1

st64 r_buf_seek(RBuffer *b, st64 addr, int whence);
st64 r_buf_read(RBuffer *b, ut8 *buf, ut64 len);
#define r_return_val_if_fail(cond, ret) if (!(cond)) return (ret)