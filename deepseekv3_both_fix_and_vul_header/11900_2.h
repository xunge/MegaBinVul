#include <stdlib.h>
#include <string.h>

typedef struct bfd bfd;
typedef struct asymbol {
    long dummy;  // Placeholder for asymbol structure
} asymbol;

struct size_sym {
    size_t size;
    asymbol *sym;
};

enum bfd_error {
    bfd_error_no_symbols
};

extern int dynamic;
extern int show_synthetic;
extern int no_sort;
extern int sort_by_size;
extern int reverse_sort;
extern int sort_numerically;
extern bfd *sort_bfd;
extern int sort_dynamic;
extern asymbol *sort_x;
extern asymbol *sort_y;
extern int (*sorters[2][2])(const void *, const void *);

#define HAS_SYMS (1 << 0)

extern const char *_(const char *str);
extern void non_fatal(const char *format, ...);
extern void bfd_fatal(const char *filename);
extern void *xmalloc(size_t size);
extern long filter_symbols(bfd *abfd, int dynamic, void *minisyms, long symcount, unsigned int size);
extern long sort_symbols_by_size(bfd *abfd, int dynamic, void *minisyms, long symcount, unsigned int size, struct size_sym **symsizes);
extern void print_symbols(bfd *abfd, int dynamic, void *minisyms, long symcount, unsigned int size, bfd *archive_bfd);
extern void print_size_symbols(bfd *abfd, int dynamic, struct size_sym *symsizes, long symcount, bfd *archive_bfd);

// BFD function declarations
extern long bfd_get_file_flags(bfd *abfd);
extern const char *bfd_get_filename(bfd *abfd);
extern long bfd_read_minisymbols(bfd *abfd, int dynamic, void **minisyms, unsigned int *size);
extern enum bfd_error bfd_get_error(void);
extern long bfd_get_dynamic_symtab_upper_bound(bfd *abfd);
extern long bfd_canonicalize_dynamic_symtab(bfd *abfd, asymbol **syms);
extern long bfd_get_synthetic_symtab(bfd *abfd, long static_count, asymbol **static_syms, long dyn_count, asymbol **dyn_syms, asymbol **synthsyms);
extern asymbol *bfd_make_empty_symbol(bfd *abfd);