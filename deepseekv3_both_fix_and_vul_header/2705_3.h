#include <stdlib.h>
#include <string.h>

typedef long bfd_vma;
typedef unsigned char bfd_byte;

struct bfd {
    unsigned long flags;
};

struct asymbol {
    unsigned long flags;
    const char *name;
    void *section;
    void *the_bfd;
    bfd_vma value;
    union {
        void *p;
    } udata;
};

struct arelent {
    bfd_vma address;
    struct asymbol **sym_ptr_ptr;
    struct {
        int type;
    } *howto;
    bfd_vma addend;
};

struct asection {
    const char *name;
    bfd_vma size;
    bfd_vma vma;
    void *owner;
};

enum elf_i386_plt_type {
    plt_unknown,
    plt_lazy,
    plt_non_lazy,
    plt_pic,
    plt_second
};

struct elf_i386_plt {
    const char *name;
    struct asection *sec;
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
    unsigned int plt0_entry_size;
    unsigned int plt_entry_size;
    unsigned int plt0_got1_offset;
    unsigned int plt_got_offset;
};

struct elf_i386_non_lazy_plt_layout {
    const bfd_byte *plt_entry;
    const bfd_byte *pic_plt_entry;
    unsigned int plt_entry_size;
    unsigned int plt_got_offset;
};

struct elf_backend_data {
    int os;
};

#define ATTRIBUTE_UNUSED
#define DYNAMIC 0
#define EXEC_P 0
#define BSF_LOCAL 0
#define BSF_GLOBAL 0
#define BSF_SYNTHETIC 0
#define BSF_SECTION_SYM 0
#define R_386_JUMP_SLOT 0
#define R_386_GLOB_DAT 0
#define R_386_IRELATIVE 0
#define R_386_TLS_DESC 0

enum {
    is_normal,
    is_vxworks,
    is_nacl
};

#define H_GET_32(abfd, ptr) (*(int *)(ptr))

static int compare_relocs(const void *, const void *);
static struct elf_backend_data *get_elf_i386_backend_data(struct bfd *);
static void *bfd_malloc(size_t);
static void *bfd_zmalloc(size_t);
static long bfd_get_dynamic_reloc_upper_bound(struct bfd *);
static long bfd_canonicalize_dynamic_reloc(struct bfd *, struct arelent **, struct asymbol **);
static int bfd_get_section_contents(struct bfd *, struct asection *, void *, bfd_vma, bfd_vma);
static struct asection *bfd_get_section_by_name(struct bfd *, const char *);
static void bfd_sprintf_vma(struct bfd *, char *, bfd_vma);

extern const struct elf_i386_lazy_plt_layout elf_i386_lazy_plt;
extern const struct elf_i386_non_lazy_plt_layout elf_i386_non_lazy_plt;
extern const struct elf_i386_lazy_plt_layout elf_i386_lazy_ibt_plt;
extern const struct elf_i386_non_lazy_plt_layout elf_i386_non_lazy_ibt_plt;
extern const struct elf_i386_lazy_plt_layout elf_i386_nacl_plt;

typedef struct bfd bfd;
typedef struct asymbol asymbol;
typedef struct arelent arelent;
typedef struct asection asection;