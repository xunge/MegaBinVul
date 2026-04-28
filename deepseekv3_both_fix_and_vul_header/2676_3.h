#include <stdlib.h>
#include <string.h>

typedef long bfd_vma;
typedef unsigned char bfd_byte;
typedef int bfd_boolean;
#define BSF_LOCAL 0
#define BSF_GLOBAL 0
#define BSF_SYNTHETIC 0
#define BSF_SECTION_SYM 0
#define TRUE 1
#define FALSE 0

struct bfd;
struct asection;
struct asymbol;
struct arelent;
struct reloc_howto_struct;

struct elf_backend_data {
    int target_id;
};
#define X86_64_ELF_DATA 0

struct elf_x86_plt {
    char *name;
    bfd_byte *contents;
    unsigned int plt_got_offset;
    unsigned int plt_entry_size;
    struct asection *sec;
    unsigned int type;
    long count;
};
#define plt_lazy 0

struct asection {
    bfd_vma vma;
    struct bfd *owner;
};

struct bfd {
    struct elf_backend_data *xvec;
};

struct arelent {
    bfd_vma address;
    struct asymbol **sym_ptr_ptr;
    bfd_vma addend;
    struct reloc_howto_struct *howto;
};

struct reloc_howto_struct {
    unsigned int type;
};

struct asymbol {
    unsigned int flags;
    struct asection *section;
    struct bfd *the_bfd;
    bfd_vma value;
    union {
        void *p;
        bfd_vma i;
    } udata;
    char *name;
};

typedef struct bfd bfd;
typedef struct asymbol asymbol;
typedef struct asection asection;
typedef struct arelent arelent;

extern void *bfd_malloc(long size);
extern void *bfd_zmalloc(long size);
extern long bfd_canonicalize_dynamic_reloc(bfd *abfd, arelent **dynrelbuf, asymbol **dynsyms);
extern int _bfd_x86_elf_compare_relocs(const void *, const void *);
extern bfd_vma elf_x86_64_get_plt_got_vma(struct elf_x86_plt *, bfd_vma, bfd_vma, bfd_vma);
extern bfd_boolean elf_x86_64_valid_plt_reloc_p(unsigned int);
extern bfd_vma elf_i386_get_plt_got_vma(struct elf_x86_plt *, bfd_vma, bfd_vma, bfd_vma);
extern bfd_boolean elf_i386_valid_plt_reloc_p(unsigned int);
extern struct elf_backend_data *get_elf_backend_data(bfd *abfd);
extern asection *bfd_get_section_by_name(bfd *abfd, const char *name);
extern void bfd_sprintf_vma(bfd *abfd, char *buf, bfd_vma value);
#define H_GET_32(abfd, ptr) (*(unsigned int *)(ptr))
#define ABI_64_P(abfd) (0)