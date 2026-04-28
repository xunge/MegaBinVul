#include <stdlib.h>
#include <string.h>

#define ATTRIBUTE_UNUSED __attribute__((unused))

typedef long bfd_vma;
typedef unsigned char bfd_byte;

enum elf_i386_plt_type {
    plt_unknown,
    plt_lazy,
    plt_non_lazy,
    plt_pic,
    plt_second
};

struct elf_i386_plt {
    const char *name;
    void *sec;
    bfd_byte *contents;
    enum elf_i386_plt_type type;
    unsigned int plt_got_offset;
    unsigned int plt_entry_size;
    long count;
};

struct elf_i386_lazy_plt_layout {
    const bfd_byte *plt0_entry;
    const bfd_byte *pic_plt0_entry;
    const bfd_byte *plt_entry;
    const bfd_byte *pic_plt_entry;
    unsigned int plt0_got1_offset;
    unsigned int plt_got_offset;
    unsigned int plt0_entry_size;
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

typedef struct {
    unsigned long flags;
    struct elf_i386_backend_data *xvec;
    void *owner;
} bfd;

typedef struct {
    unsigned long flags;
    char *name;
    void *section;
    void *the_bfd;
    bfd_vma value;
    union {
        void *p;
    } udata;
} asymbol;

typedef struct {
    bfd_vma address;
    asymbol **sym_ptr_ptr;
    bfd_vma addend;
    struct {
        unsigned int type;
    } *howto;
} arelent;

typedef struct {
    const char *name;
    bfd_vma vma;
    unsigned long size;
    void *owner;
} asection;

#define BSF_LOCAL 0x1
#define BSF_GLOBAL 0x2
#define BSF_SYNTHETIC 0x4
#define BSF_SECTION_SYM 0x8

#define DYNAMIC 0x1
#define EXEC_P 0x2

#define R_386_JUMP_SLOT 0x7
#define R_386_GLOB_DAT 0x6
#define R_386_IRELATIVE 0x2a
#define R_386_TLS_DESC 0x2b

extern void *bfd_malloc(unsigned long);
extern void *bfd_zmalloc(unsigned long);
extern void free(void *);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern int memcmp(const void *, const void *, size_t);
extern void bfd_sprintf_vma(bfd *, char *, bfd_vma);

static int compare_relocs(const void *a, const void *b) {
    const arelent *ra = *(const arelent **)a;
    const arelent *rb = *(const arelent **)b;
    if (ra->address < rb->address) return -1;
    if (ra->address > rb->address) return 1;
    return 0;
}

static struct elf_i386_backend_data *get_elf_i386_backend_data(bfd *abfd) {
    return abfd->xvec;
}

static const struct elf_i386_lazy_plt_layout elf_i386_lazy_plt = {0};
static const struct elf_i386_non_lazy_plt_layout elf_i386_non_lazy_plt = {0};
static const struct elf_i386_lazy_plt_layout elf_i386_lazy_ibt_plt = {0};
static const struct elf_i386_non_lazy_plt_layout elf_i386_non_lazy_ibt_plt = {0};
static const struct elf_i386_lazy_plt_layout elf_i386_nacl_plt = {0};

static long bfd_get_dynamic_reloc_upper_bound(bfd *abfd) {
    return 0;
}

static long bfd_canonicalize_dynamic_reloc(bfd *abfd, arelent **relocs, asymbol **syms) {
    return 0;
}

static void *bfd_get_section_by_name(bfd *abfd, const char *name) {
    return NULL;
}

static int bfd_get_section_contents(bfd *abfd, asection *section, void *location, unsigned long offset, unsigned long count) {
    return 0;
}

static int H_GET_32(bfd *abfd, void *ptr) {
    return 0;
}