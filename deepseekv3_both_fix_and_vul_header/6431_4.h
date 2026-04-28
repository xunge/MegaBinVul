#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define _(x) x

typedef int bfd_boolean;
typedef unsigned long bfd_vma;
typedef unsigned long bfd_size_type;

struct bfd;

struct asymbol {
    char *name;
    bfd_vma value;
};

struct alent {
    int line_number;
    union {
        struct asymbol *sym;
        bfd_vma offset;
    } u;
};

struct asection {
    struct alent *lineno;
    unsigned long lineno_count;
    unsigned long size;
    bfd_vma line_filepos;
    bfd_vma vma;
};

struct LINENO {
    unsigned long l_lnno;
    union {
        unsigned long l_symndx;
        bfd_vma l_paddr;
    } l_addr;
};

struct internal_lineno {
    unsigned long l_lnno;
    union {
        unsigned long l_symndx;
        bfd_vma l_paddr;
    } l_addr;
};

struct coff_symbol_type {
    struct asymbol symbol;
    struct alent *lineno;
};

struct combined_entry_type {
    bfd_boolean is_sym;
    union {
        struct {
            union {
                struct {
                    char _n_zeroes[4];
                } _n_n;
            } _n;
        } syment;
    } u;
};

extern void _bfd_error_handler(const char *, ...);
extern void *bfd_alloc(struct bfd *, bfd_size_type);
extern void bfd_release(struct bfd *, void *);
extern unsigned int bfd_coff_linesz(struct bfd *);
extern void *buy_and_read(struct bfd *, bfd_vma, bfd_size_type);
extern void bfd_coff_swap_lineno_in(struct bfd *, struct LINENO *, struct internal_lineno *);
extern unsigned long obj_raw_syment_count(struct bfd *);
extern struct combined_entry_type *obj_raw_syments(struct bfd *);
extern struct coff_symbol_type *obj_symbols(struct bfd *);
extern unsigned int bfd_get_symcount(struct bfd *);
extern const char *bfd_asymbol_name(struct asymbol *);
extern bfd_vma bfd_section_vma(struct bfd *, struct asection *);
extern int coff_sort_func_alent(const void *, const void *);

#define BFD_ASSERT(expr) ((void)0)