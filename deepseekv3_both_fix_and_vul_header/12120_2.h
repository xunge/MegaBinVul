#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

typedef uint64_t ut64;
typedef uint32_t ut32;
typedef uint16_t ut16;
typedef uint8_t ut8;

typedef struct {
    const char *name;
    int byte;
    int size;
} JavaOp;

typedef struct {
    ut64 addr;
    ut64 def_jmp;
} SwitchOp;

typedef struct RBinJavaObj RBinJavaObj;

#define JAVA_OPS_COUNT 256
#define IN_SWITCH_OP 0
#define BYTES_CONSUMED 0
#define USHORT(b, i) ((b[i] << 8) | b[i+1])
#define PFMT64x PRIx64

#define R_API 
#define R_LOG_DEBUG(...)

extern JavaOp JAVA_OPS[JAVA_OPS_COUNT];
extern SwitchOp SWITCH_OP;

extern int handle_switch_op(ut64 addr, const ut8 *bytes, int len, char *output, int outlen);
extern int enter_switch_op(ut64 addr, const ut8 *bytes, int len);
extern int update_bytes_consumed(int size);
extern char *r_bin_java_resolve_without_space(RBinJavaObj *obj, ut16 index);
extern char *r_bin_java_resolve_with_space(RBinJavaObj *obj, ut16 index);