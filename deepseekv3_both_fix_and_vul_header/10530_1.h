#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int bfd_boolean;
#define TRUE 1
#define FALSE 0

typedef unsigned long bfd_size_type;

typedef struct {
    unsigned long d_tag;
    union {
        unsigned long d_val;
        void *d_ptr;
    } d_un;
} Elf_Internal_Dyn;

typedef struct {
    unsigned long sh_offset;
    unsigned long sh_size;
    unsigned long sh_entsize;
    unsigned long sh_name;
} Elf_Internal_Shdr;

typedef struct {
    unsigned short si_boundto;
    unsigned short si_flags;
} Elf_Internal_Syminfo;

typedef struct {
    unsigned short si_boundto;
    unsigned short si_flags;
} Elf_External_Syminfo;

typedef struct {
    unsigned char e_machine;
} Elf_Header;

typedef struct {
    unsigned long st_name;
    unsigned long st_value;
    unsigned long st_size;
    unsigned char st_info;
    unsigned char st_other;
    unsigned short st_shndx;
} Elf32_External_Sym;

typedef struct {
    unsigned long st_name;
    unsigned char st_info;
    unsigned char st_other;
    unsigned short st_shndx;
    unsigned long st_value;
    unsigned long st_size;
} Elf64_External_Sym;

#define DT_NULL         0
#define DT_NEEDED       1
#define DT_PLTRELSZ     2
#define DT_PLTGOT       3
#define DT_HASH         4
#define DT_STRTAB       5
#define DT_SYMTAB       6
#define DT_RELA         7
#define DT_RELASZ       8
#define DT_RELAENT      9
#define DT_STRSZ       10
#define DT_SYMENT      11
#define DT_INIT        12
#define DT_FINI        13
#define DT_SONAME      14
#define DT_RPATH       15
#define DT_SYMBOLIC    16
#define DT_REL         17
#define DT_RELSZ       18
#define DT_RELENT      19
#define DT_PLTREL      20
#define DT_DEBUG       21
#define DT_TEXTREL     22
#define DT_JMPREL      23
#define DT_BIND_NOW    24
#define DT_INIT_ARRAY  25
#define DT_FINI_ARRAY  26
#define DT_INIT_ARRAYSZ 27
#define DT_FINI_ARRAYSZ 28
#define DT_RUNPATH     29
#define DT_FLAGS       30
#define DT_PREINIT_ARRAY 32
#define DT_PREINIT_ARRAYSZ 33
#define DT_SYMTAB_SHNDX 34
#define DT_RELRSZ      35
#define DT_RELR        36
#define DT_RELRENT     37
#define DT_SYMINFO     0x6ffffef7
#define DT_SYMINENT    0x6ffffef8
#define DT_SYMINSZ     0x6ffffef9
#define DT_VERSYM      0x6ffffff0
#define DT_RELACOUNT   0x6ffffff9
#define DT_RELCOUNT    0x6ffffffa
#define DT_FLAGS_1     0x6ffffffb
#define DT_VERDEF      0x6ffffffc
#define DT_VERDEFNUM   0x6ffffffd
#define DT_VERNEED     0x6ffffffe
#define DT_VERNEEDNUM  0x6fffffff
#define DT_AUXILIARY   0x7ffffffd
#define DT_FILTER      0x7fffffff
#define DT_GNU_HASH    0x6ffffef5
#define DT_GNU_PRELINKED 0x6ffffdf5
#define DT_GNU_CONFLICTSZ 0x6ffffdf6
#define DT_GNU_LIBLISTSZ 0x6ffffdf7
#define DT_CONFIG      0x6ffffefa
#define DT_DEPAUDIT    0x6ffffefb
#define DT_AUDIT       0x6ffffefc
#define DT_PLTPADSZ    0x6ffffdfb
#define DT_MOVEENT     0x6ffffdfc
#define DT_MOVESZ      0x6ffffdfd
#define DT_FEATURE     0x6ffffdf9
#define DT_POSFLAG_1   0x6ffffdfa
#define DT_USED        0x6ffffdf8

#define DF_ORIGIN      0x1
#define DF_SYMBOLIC    0x2
#define DF_TEXTREL     0x4
#define DF_BIND_NOW    0x8
#define DF_STATIC_TLS  0x10

#define DF_1_NOW       0x00000001
#define DF_1_GLOBAL    0x00000002
#define DF_1_GROUP     0x00000004
#define DF_1_NODELETE  0x00000008
#define DF_1_LOADFLTR  0x00000010
#define DF_1_INITFIRST 0x00000020
#define DF_1_NOOPEN    0x00000040
#define DF_1_ORIGIN    0x00000080
#define DF_1_DIRECT    0x00000100
#define DF_1_TRANS     0x00000200
#define DF_1_INTERPOSE 0x00000400
#define DF_1_NODEFLIB  0x00000800
#define DF_1_NODUMP    0x00001000
#define DF_1_CONFALT   0x00002000
#define DF_1_ENDFILTEE 0x00004000
#define DF_1_DISPRELDNE 0x00008000
#define DF_1_DISPRELPND 0x00010000
#define DF_1_NODIRECT  0x00020000
#define DF_1_IGNMULDEF 0x00040000
#define DF_1_NOKSYMS   0x00080000
#define DF_1_NOHDR     0x00100000
#define DF_1_EDITED    0x00200000
#define DF_1_NORELOC   0x00400000
#define DF_1_SYMINTPOSE 0x00800000
#define DF_1_GLOBAUDIT 0x01000000
#define DF_1_SINGLETON 0x02000000
#define DF_1_STUB      0x04000000
#define DF_1_PIE       0x08000000

#define DTF_1_PARINIT  0x1
#define DTF_1_CONFEXP  0x2

#define DF_P1_LAZYLOAD 0x1
#define DF_P1_GROUPPERM 0x2

#define EM_MIPS        8
#define EM_MIPS_RS3_LE 10
#define EM_PARISC      15
#define EM_IA_64       50

extern unsigned long dynamic_size;
extern bfd_boolean do_dynamic;
extern bfd_boolean is_32bit_elf;
extern Elf_Internal_Dyn *dynamic_section;
extern unsigned long dynamic_nent;
extern void *dynamic_symbols;
extern unsigned long *dynamic_info;
extern char *dynamic_strings;
extern unsigned long dynamic_strings_length;
extern Elf_Internal_Syminfo *dynamic_syminfo;
extern unsigned long dynamic_syminfo_offset;
extern unsigned long dynamic_syminfo_nent;
extern unsigned long dynamic_addr;
extern char *program_interpreter;
extern Elf_Header elf_header;
extern unsigned long string_table_length;
extern unsigned long num_dynamic_syms;
extern long archive_file_offset;
extern long archive_file_size;
extern unsigned long current_file_size;
extern unsigned long dynamic_info_DT_GNU_HASH;
extern unsigned long *version_info;

#define _(x) x
#define FULL_HEX 0
#define PREFIX_HEX 1
#define UNSIGNED 2
#define VALID_DYNAMIC_NAME(x) 0
#define GET_DYNAMIC_NAME(x) NULL
#define BYTE_GET(x) (x)
#define DT_VERSIONTAGIDX(tag) ((tag) - DT_VERSYM)

extern bfd_boolean get_32bit_dynamic_section(FILE *);
extern bfd_boolean get_64bit_dynamic_section(FILE *);
extern unsigned long offset_from_vma(FILE *, unsigned long, unsigned long);
extern void *get_data(void *, FILE *, unsigned long, int, long, const char *);
extern void *GET_ELF_SYMBOLS(FILE *, Elf_Internal_Shdr *, unsigned long *);
extern void error(const char *, ...);
extern void print_vma(unsigned long, int);
extern const char *get_dynamic_type(unsigned long);
extern void print_dynamic_flags(unsigned long);
extern int streq(const char *, const char *);
extern void dynamic_section_mips_val(Elf_Internal_Dyn *);
extern void dynamic_section_parisc_val(Elf_Internal_Dyn *);
extern void dynamic_section_ia64_val(Elf_Internal_Dyn *);