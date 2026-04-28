#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_REPOP_LENGTH 32

typedef uint64_t ut64;
typedef int64_t st64;
typedef uint32_t ut32;

typedef struct Operand {
    int type;
    int dest_size;
    int regs[2];
    int scale[2];
    ut64 offset;
    bool extended;
    int reg;
    int reg_size;
    bool explicit_size;
    int offset_sign;
    bool is_good_flag;
    char rep_op[MAX_REPOP_LENGTH];
    st64 immediate;
    int sign;
} Operand;

typedef struct RNum {
    ut64 value;
    void *userptr;
} RNum;

typedef struct RAsm {
    RNum *num;
} RAsm;

typedef struct RFlagItem {
    // Minimal definition
} RFlagItem;

typedef struct RCore {
    struct {
        RFlagItem *(*get)(void *flags, const char *str);
    } *flags;
} RCore;

typedef enum x86newTokenType {
    TT_SPECIAL,
    TT_WORD
} x86newTokenType;

typedef enum Register {
    X86R_UNDEFINED
} Register;

#define OT_MEMORY 1
#define OT_BYTE 2
#define OT_WORD 4
#define OT_DWORD 8
#define OT_QWORD 16
#define OT_OWORD 32
#define OT_TBYTE 64
#define OT_REGTYPE 128
#define OT_SEGMENTREG 256
#define OT_GPREG 512
#define OT_CONSTANT 1024

x86newTokenType getToken(const char *str, size_t *pos, size_t *nextpos);
Register parseReg(RAsm *a, const char *str, size_t *nextpos, int *reg_type);
void parse_segment_offset(RAsm *a, const char *str, size_t *nextpos, Operand *op, int reg_index);
st64 getnum(RAsm *a, const char *str);