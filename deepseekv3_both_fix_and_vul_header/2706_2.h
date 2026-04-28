#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define ATTRIBUTE_UNUSED __attribute__((unused))

typedef uint64_t bfd_vma;
typedef unsigned char bfd_byte;

typedef struct bfd {
    unsigned long flags;
} bfd;

typedef struct asymbol {
    unsigned long flags;
    char *name;
    struct asection *section;
    struct bfd *the_bfd;
    bfd_vma value;
    union {
        void *p;
    } udata;
} asymbol;

typedef struct arelent {
    bfd_vma address;
    struct {
        int type;
    } *howto;
    asymbol **sym_ptr_ptr;
    bfd_vma addend;
} arelent;

typedef struct asection {
    bfd_vma size;
    bfd_vma vma;
    struct bfd *owner;
} asection;

enum elf_x86_64_plt_type {
    plt_unknown,
    plt_lazy,
    plt_non_lazy,
    plt_second
};

struct elf_x86_64_plt {
    const char *name;
    asection *sec;
    bfd_byte *contents;
    enum elf_x86_64_plt_type type;
    unsigned int plt_got_offset;
    unsigned int plt_got_insn_size;
    unsigned int plt_entry_size;
    long count;
};

struct elf_x86_64_lazy_plt_layout {
    const bfd_byte *plt0_entry;
    unsigned int plt0_got1_offset;
    unsigned int plt_got_offset;
    unsigned int plt_got_insn_size;
    unsigned int plt_entry_size;
    const bfd_byte *plt_entry;
};

struct elf_x86_64_non_lazy_plt_layout {
    const bfd_byte *plt_entry;
    unsigned int plt_got_offset;
    unsigned int plt_got_insn_size;
    unsigned int plt_entry_size;
};

#define DYNAMIC (1 << 0)
#define EXEC_P (1 << 1)
#define BSF_LOCAL (1 << 0)
#define BSF_GLOBAL (1 << 1)
#define BSF_SYNTHETIC (1 << 2)
#define BSF_SECTION_SYM (1 << 3)
#define R_X86_64_JUMP_SLOT 7
#define R_X86_64_GLOB_DAT 6
#define R_X86_64_IRELATIVE 37

static const struct elf_x86_64_lazy_plt_layout elf_x86_64_lazy_plt;
static const struct elf_x86_64_non_lazy_plt_layout elf_x86_64_non_lazy_plt;
static const struct elf_x86_64_lazy_plt_layout elf_x86_64_lazy_bnd_plt;
static const struct elf_x86_64_non_lazy_plt_layout elf_x86_64_non_lazy_bnd_plt;
static const struct elf_x86_64_lazy_plt_layout elf_x86_64_lazy_ibt_plt;
static const struct elf_x86_64_non_lazy_plt_layout elf_x86_64_non_lazy_ibt_plt;
static const struct elf_x86_64_lazy_plt_layout elf_x32_lazy_ibt_plt;
static const struct elf_x86_64_non_lazy_plt_layout elf_x32_non_lazy_ibt_plt;
static const struct elf_x86_64_lazy_plt_layout elf_x86_64_nacl_plt;

struct elf_x86_64_backend_data {
    int os;
};

static struct elf_x86_64_backend_data* get_elf_x86_64_backend_data(bfd *abfd) {
    return NULL;
}

#define is_normal 0
#define ABI_64_P(abfd) 1

static long bfd_get_dynamic_reloc_upper_bound(bfd *abfd) { return 0; }
static void *bfd_malloc(long size) { return malloc(size); }
static long bfd_canonicalize_dynamic_reloc(bfd *abfd, arelent **relocs, asymbol **syms) { return 0; }
static asection *bfd_get_section_by_name(bfd *abfd, const char *name) { return NULL; }
static int bfd_get_section_contents(bfd *abfd, asection *section, void *location, bfd_vma offset, bfd_vma count) { return 0; }
static void *bfd_zmalloc(long size) { return calloc(1, size); }
static void bfd_sprintf_vma(bfd *abfd, char *buf, bfd_vma value) { sprintf(buf, "%lx", value); }

#define H_GET_32(abfd, ptr) (*(int32_t*)(ptr))

static int compare_relocs(const void *a, const void *b) {
    const arelent *ra = *(const arelent **)a;
    const arelent *rb = *(const arelent **)b;
    if (ra->address < rb->address) return -1;
    if (ra->address > rb->address) return 1;
    return 0;
}