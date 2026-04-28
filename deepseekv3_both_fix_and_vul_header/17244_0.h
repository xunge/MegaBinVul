#include <stdbool.h>
#include <stdint.h>

#define MACH0_(x) x
#define REFERENCE_TYPE 0
#define REFERENCE_FLAG_UNDEFINED_LAZY 0
#define S_LAZY_SYMBOL_POINTERS 0
#define S_NON_LAZY_SYMBOL_POINTERS 0
#define SECTION_TYPE 0
#define R_BIN_RELOC_8 0
#define R_BIN_RELOC_16 0
#define R_BIN_RELOC_32 0
#define R_BIN_RELOC_64 0

typedef uint32_t ut32;

struct reloc_t {
    ut32 offset;
    ut32 addr;
    ut32 addend;
    int type;
};

struct MACH0_(obj_t) {
    int nsymtab;
    int nindirectsyms;
    int nsects;
    struct {
        ut32 flags;
        ut32 reserved1;
        ut32 offset;
        ut32 addr;
    } *sects;
    struct {
        ut32 n_desc;
    } *symtab;
    int *indirectsyms;
    int (*get_bits)(struct MACH0_(obj_t)*);
};