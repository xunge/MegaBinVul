#include <stdint.h>
#include <stddef.h>
#include <limits.h>

#define UT64_MAX UINT64_MAX

typedef uint64_t ut64;
typedef uint8_t ut8;

typedef struct RBinFile RBinFile;
typedef struct RBuffer RBuffer;
typedef struct Sdb Sdb;
typedef struct r_bin_bflt_obj r_bin_bflt_obj;

RBuffer *r_buf_new(void);
void r_buf_set_bytes(RBuffer *buf, const ut8 *bytes, ut64 size);
void r_buf_free(RBuffer *buf);
r_bin_bflt_obj *r_bin_bflt_new_buf(RBuffer *buf);