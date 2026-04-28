#include <stddef.h>
#include <string.h>

typedef int bfd_boolean;
typedef struct bfd bfd;
typedef struct asymbol asymbol;
typedef struct elf_symbol_type elf_symbol_type;
typedef struct elf_tdata {
    unsigned int cverdefs;
    struct Elf_Internal_Verdef *verdef;
    struct Elf_Internal_Verneed *verref;
} elf_tdata;
typedef struct Elf_Internal_Verneed Elf_Internal_Verneed;
typedef struct Elf_Internal_Vernaux Elf_Internal_Vernaux;
typedef struct Elf_Internal_Verdef Elf_Internal_Verdef;

#define VERSYM_HIDDEN 0x8000
#define VERSYM_VERSION 0x7fff
#define VER_FLG_BASE 0x1

extern unsigned int elf_dynversym(bfd *);
extern unsigned int elf_dynverdef(bfd *);
extern unsigned int elf_dynverref(bfd *);
extern elf_tdata *elf_get_tdata(bfd *);

#define elf_tdata(abfd) elf_get_tdata(abfd)

struct elf_symbol_type {
    unsigned int version;
};

struct Elf_Internal_Verneed {
    Elf_Internal_Verneed *vn_nextref;
    Elf_Internal_Vernaux *vn_auxptr;
};

struct Elf_Internal_Vernaux {
    unsigned int vna_other;
    const char *vna_nodename;
    Elf_Internal_Vernaux *vna_nextptr;
};

struct Elf_Internal_Verdef {
    unsigned int vd_flags;
    const char *vd_nodename;
};

struct asymbol {
    const char *name;
};

const char *_(const char *);