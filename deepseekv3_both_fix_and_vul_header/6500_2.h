#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef int bfd_boolean;
#define TRUE 1
#define FALSE 0

typedef uint64_t bfd_vma;
typedef uint64_t bfd_size_type;

typedef struct bfd bfd;
typedef struct asection *sec_ptr;
typedef struct asymbol asymbol;
typedef struct arelent arelent;

struct asection {
    void *relocation;
    unsigned int reloc_count;
    unsigned int flags;
    bfd_vma rel_filepos;
    bfd_vma vma;
    asymbol **symbol_ptr_ptr;
};

struct arelent {
    bfd_vma address;
    asymbol **sym_ptr_ptr;
    void *howto;
};

typedef struct RELOC {
    unsigned char r_vaddr[4];
    unsigned char r_symndx[4];
    unsigned char r_type[2];
    unsigned char r_offset[4];
} RELOC;

struct internal_reloc {
    bfd_vma r_vaddr;
    long r_symndx;
    unsigned int r_type;
    bfd_vma r_offset;
};

typedef RELOC external_reloc;

#define SEC_CONSTRUCTOR (1 << 5)

enum bfd_error {
    bfd_error_bad_value
};

extern bfd_boolean coff_slurp_symbol_table(bfd *abfd);
extern unsigned int bfd_coff_relsz(bfd *abfd);
extern void *buy_and_read(bfd *abfd, bfd_vma offset, bfd_size_type size);
extern void *bfd_alloc(bfd *abfd, bfd_size_type size);
extern void coff_swap_reloc_in(bfd *abfd, void *src, struct internal_reloc *dst);
extern long obj_conv_table_size(bfd *abfd);
extern long *obj_convert(bfd *abfd);
extern void _bfd_error_handler(const char *fmt, ...);
extern void bfd_set_error(enum bfd_error error);

extern struct asection *bfd_abs_section_ptr;

#define RELOC_PROCESSING(cache_ptr, dst, symbols, abfd, asect)
#define RTYPE2HOWTO(cache_ptr, dst)
#define CALC_ADDEND(abfd, ptr, dst, cache_ptr)
#define _(x) x