#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ATTRIBUTE_UNUSED __attribute__((unused))

typedef long bfd_vma;
typedef unsigned char bfd_byte;

typedef struct bfd {
    unsigned long flags;
} bfd;

typedef struct asymbol {
    unsigned long flags;
    const char *name;
    void *section;
    void *the_bfd;
    bfd_vma value;
    union {
        void *p;
    } udata;
} asymbol;

typedef struct arelent {
    bfd_vma address;
    asymbol **sym_ptr_ptr;
    struct {
        int type;
    } *howto;
    bfd_vma addend;
} arelent;

typedef struct asection {
    const char *name;
    bfd_vma size;
    bfd_vma vma;
    void *owner;
} asection;

enum elf_i386_plt_type {
    plt_unknown,
    plt_lazy,
    plt_non_lazy,
    plt_pic,
    plt_second
};

struct elf_i386_plt {
    const char *name;
    asection *sec;
    bfd_byte *contents;
    enum elf_i386_plt_type type;
    unsigned int plt_got_offset;
    unsigned int plt_entry_size;
    long count;
};

struct elf_i386_lazy_plt_layout {
    const bfd_byte *plt0_entry;
    const bfd_byte *pic_plt0_entry;
    unsigned int plt0_got1_offset;
    unsigned int plt0_entry_size;
    const bfd_byte *plt_entry;
    const bfd_byte *pic_plt_entry;
    unsigned int plt_got_offset;
    unsigned int plt_entry_size;
};

struct elf_i386_non_lazy_plt_layout {
    const bfd_byte *plt_entry;
    const bfd_byte *pic_plt_entry;
    unsigned int plt_got_offset;
    unsigned int plt_entry_size;
};

enum elf_i386_os_type {
    is_normal,
    is_vxworks,
    is_nacl
};

struct elf_i386_backend_data {
    enum elf_i386_os_type os;
};

#define DYNAMIC (1 << 0)
#define EXEC_P (1 << 1)
#define BSF_LOCAL (1 << 0)
#define BSF_GLOBAL (1 << 1)
#define BSF_SYNTHETIC (1 << 2)
#define BSF_SECTION_SYM (1 << 3)

#define R_386_JUMP_SLOT 7
#define R_386_GLOB_DAT 6
#define R_386_IRELATIVE 42
#define R_386_TLS_DESC 41

#define H_GET_32(abfd, ptr) (*(int32_t*)(ptr))

extern long bfd_get_dynamic_reloc_upper_bound(bfd *);
extern long bfd_canonicalize_dynamic_reloc(bfd *, arelent **, asymbol **);
extern void *bfd_malloc(long);
extern void *bfd_zmalloc(long);
extern int bfd_get_section_contents(bfd *, asection *, void *, bfd_vma, bfd_vma);
extern asection *bfd_get_section_by_name(bfd *, const char *);
extern struct elf_i386_backend_data *get_elf_i386_backend_data(bfd *);
extern void bfd_sprintf_vma(bfd *, char *, bfd_vma);

extern struct elf_i386_lazy_plt_layout elf_i386_lazy_plt;
extern struct elf_i386_non_lazy_plt_layout elf_i386_non_lazy_plt;
extern struct elf_i386_lazy_plt_layout elf_i386_lazy_ibt_plt;
extern struct elf_i386_non_lazy_plt_layout elf_i386_non_lazy_ibt_plt;
extern struct elf_i386_lazy_plt_layout elf_i386_nacl_plt;

static int compare_relocs(const void *a, const void *b) {
    const arelent *reloc_a = *(const arelent **)a;
    const arelent *reloc_b = *(const arelent **)b;
    if (reloc_a->address < reloc_b->address) return -1;
    if (reloc_a->address > reloc_b->address) return 1;
    return 0;
}