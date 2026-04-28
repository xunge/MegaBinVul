#include <stdint.h>
#include <stdio.h>

typedef uint64_t bfd_vma;
typedef int (*fprintf_ftype)(void *stream, const char *format, ...);

typedef struct disassemble_info {
    fprintf_ftype fprintf_func;
    void *stream;
    unsigned int flags;
    void (*print_address_func)(bfd_vma addr, struct disassemble_info *info);
} disassemble_info;

#define OP6(insn) (((insn) >> 26) & 0x3f)
#define RT5(insn) (((insn) >> 21) & 0x1f)
#define RA5(insn) (((insn) >> 16) & 0x1f)
#define RB5(insn) (((insn) >> 11) & 0x1f)
#define IMMS(insn, bits) ((int32_t)((insn) << (32 - (bits))) >> (32 - (bits)))
#define IMMU(insn, bits) ((insn) & ((1 << (bits)) - 1))
#define __BIT(n) (1 << (n))
#define __GF(insn, pos, width) (((insn) >> (pos)) & ((1 << (width)) - 1))
#define __SEXT(val, bits) ((int32_t)((val) << (32 - (bits))) >> (32 - (bits)))
#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))

extern const char *mnemonic_op6[64];
extern const char *gpr_map[32];
extern const char *keyword_dpref[16];
extern const char *mnemonic_hwgp[8];
extern const char *mnemonic_br2[16];

#define INSN_HAS_RELOC (1 << 0)

void print_insn32_mem(bfd_vma pc, disassemble_info *info, uint32_t insn);
void print_insn32_alu1(bfd_vma pc, disassemble_info *info, uint32_t insn);
void print_insn32_alu2(bfd_vma pc, disassemble_info *info, uint32_t insn);
void print_insn32_jreg(bfd_vma pc, disassemble_info *info, uint32_t insn);
void print_insn32_misc(bfd_vma pc, disassemble_info *info, uint32_t insn);
void print_insn32_fpu(bfd_vma pc, disassemble_info *info, uint32_t insn);