#include <stdlib.h>
#include <string.h>

#define ATTRIBUTE_UNUSED __attribute__((unused))

typedef unsigned long bfd_vma;

typedef struct bfd {
    unsigned long flags;
} bfd;

typedef struct asymbol {
    unsigned int flags;
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
    struct asymbol **sym_ptr_ptr;
    struct reloc_howto_struct *howto;
    bfd_vma addend;
} arelent;

typedef unsigned char bfd_byte;

typedef struct asection {
    char *name;
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

struct elf_x86_64_backend_data {
    int os;
};

struct reloc_howto_struct {
    int type;
};

#define DYNAMIC 0x1
#define EXEC_P 0x2
#define BSF_LOCAL 0x1
#define BSF_GLOBAL 0x2
#define BSF_SYNTHETIC 0x4
#define BSF_SECTION_SYM 0x8

#define R_X86_64_JUMP_SLOT 0
#define R_X86_64_GLOB_DAT 0
#define R_X86_64_IRELATIVE 0

#define H_GET_32(abfd, ptr) (*(unsigned int *)(ptr))
#define ABI_64_P(abfd) 1
#define is_normal 0

extern const struct elf_x86_64_lazy_plt_layout elf_x86_64_lazy_plt;
extern const struct elf_x86_64_non_lazy_plt_layout elf_x86_64_non_lazy_plt;
extern const struct elf_x86_64_lazy_plt_layout elf_x86_64_lazy_bnd_plt;
extern const struct elf_x86_64_non_lazy_plt_layout elf_x86_64_non_lazy_bnd_plt;
extern const struct elf_x86_64_lazy_plt_layout elf_x86_64_lazy_ibt_plt;
extern const struct elf_x86_64_non_lazy_plt_layout elf_x86_64_non_lazy_ibt_plt;
extern const struct elf_x86_64_lazy_plt_layout elf_x86_64_nacl_plt;
extern const struct elf_x86_64_lazy_plt_layout elf_x32_lazy_ibt_plt;
extern const struct elf_x86_64_non_lazy_plt_layout elf_x32_non_lazy_ibt_plt;

static int compare_relocs(const void *a, const void *b) {
    const arelent *rel_a = *(const arelent **)a;
    const arelent *rel_b = *(const arelent **)b;
    if (rel_a->address < rel_b->address) return -1;
    if (rel_a->address > rel_b->address) return 1;
    return 0;
}

static const struct elf_x86_64_backend_data *get_elf_x86_64_backend_data(bfd *abfd) {
    static struct elf_x86_64_backend_data data = {0};
    return &data;
}

static void bfd_sprintf_vma(bfd *abfd, char *buf, bfd_vma value) {
    sprintf(buf, "%lx", value);
}

static void *bfd_malloc(size_t size) {
    return malloc(size);
}

static void *bfd_zmalloc(size_t size) {
    return calloc(1, size);
}

static long bfd_get_dynamic_reloc_upper_bound(bfd *abfd) {
    return 1024;
}

static long bfd_canonicalize_dynamic_reloc(bfd *abfd, arelent **relocs, asymbol **syms) {
    return 0;
}

static int bfd_get_section_contents(bfd *abfd, asection *section, void *location, bfd_vma offset, bfd_vma count) {
    return 1;
}

static asection *bfd_get_section_by_name(bfd *abfd, const char *name) {
    static asection section = {0};
    return &section;
}