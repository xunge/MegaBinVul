#include <ctype.h>
#include <stdint.h>

typedef uint32_t ut32;
typedef uint64_t ut64;
typedef uint8_t ut8;

typedef struct {
    ut64 off;
    ut32 o;
} ArmOpcode;

typedef int (*AssembleFunc)(ArmOpcode *aop, ut64 off, const char *buf);

extern void arm_opcode_parse(ArmOpcode *aop, const char *buf);
extern AssembleFunc assemble[2];