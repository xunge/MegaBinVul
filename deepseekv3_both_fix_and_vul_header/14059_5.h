#include <stdlib.h>
#include <string.h>

#define ATTRIBUTE_UNUSED __attribute__((unused))

typedef struct bfd bfd;
typedef struct asymbol asymbol;
typedef struct arelent arelent;
typedef unsigned char bfd_byte;
typedef unsigned long bfd_vma;
typedef struct asection asection;

struct bfd {
    unsigned int flags;
};

struct asymbol {
    unsigned int flags;
    asection *section;
    bfd *the_bfd;
    bfd_vma value;
    union {
        void *p;
        bfd_vma v;
    } udata;
    char *name;
};

struct asection {
    bfd_vma size;
    bfd_vma vma;
    bfd *owner;
};

struct arelent {
    bfd_vma address;
    asymbol **sym_ptr_ptr;
    struct reloc_howto_struct *howto;
    bfd_vma addend;
};

struct reloc_howto_struct {
    int type;
};

struct elf_x86_64_backend_data {
    int os;
};

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

#define DYNAMIC (1 << 1)
#define EXEC_P (1 << 2)

#define BSF_LOCAL (1 << 0)
#define BSF_GLOBAL (1 << 1)
#define BSF_SYNTHETIC (1 << 2)
#define BSF_SECTION_SYM (1 << 3)

#define R_X86_64_JUMP_SLOT 7
#define R_X86_64_GLOB_DAT 6
#define R_X86_64_IRELATIVE 42
#define R_X86_64_TLSDESC 36

#define ABI_64_P(abfd) (1)
#define H_GET_32(abfd, ptr) (*(int *)(ptr))
#define is_normal 0

extern const struct elf_x86_64_lazy_plt_layout elf_x86_64_lazy_plt;
extern const struct elf_x86_64_non_lazy_plt_layout elf_x86_64_non_lazy_plt;
extern const struct elf_x86_64_lazy_plt_layout elf_x86_64_lazy_bnd_plt;
extern const struct elf_x86_64_non_lazy_plt_layout elf_x86_64_non_lazy_bnd_plt;
extern const struct elf_x86_64_lazy_plt_layout elf_x86_64_lazy_ibt_plt;
extern const struct elf_x86_64_non_lazy_plt_layout elf_x86_64_non_lazy_ibt_plt;
extern const struct elf_x86_64_lazy_plt_layout elf_x32_lazy_ibt_plt;
extern const struct elf_x86_64_non_lazy_plt_layout elf_x32_non_lazy_ibt_plt;
extern const struct elf_x86_64_lazy_plt_layout elf_x86_64_nacl_plt;

static int compare_relocs(const void *a, const void *b) {
    const arelent *ra = *(const arelent **)a;
    const arelent *rb = *(const arelent **)b;
    if (ra->address < rb->address) return -1;
    if (ra->address > rb->address) return 1;
    return 0;
}

static struct elf_x86_64_backend_data *get_elf_x86_64_backend_data(bfd *abfd) {
    return NULL;
}

static void *bfd_malloc(size_t size) {
    return malloc(size);
}

static void bfd_sprintf_vma(bfd *abfd, char *buf, bfd_vma value) {
    sprintf(buf, "%lx", value);
}

static long bfd_get_dynamic_reloc_upper_bound(bfd *abfd) {
    return 0;
}

static long bfd_canonicalize_dynamic_reloc(bfd *abfd, arelent **relocs, asymbol **syms) {
    return 0;
}

static int bfd_get_section_contents(bfd *abfd, asection *section, void *location, bfd_vma offset, bfd_vma count) {
    return 0;
}

static asection *bfd_get_section_by_name(bfd *abfd, const char *name) {
    return NULL;
}

static void *bfd_zmalloc(size_t size) {
    return calloc(1, size);
}