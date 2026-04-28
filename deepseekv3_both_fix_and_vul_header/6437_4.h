#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef int bfd_boolean;
#define TRUE 1
#define FALSE 0

typedef struct bfd {
    void *coff_external_syms;
    long sym_filepos;
    size_t raw_syment_count;
} bfd;

typedef size_t bfd_size_type;

#define _(x) x
#define SEEK_SET 0

extern void _bfd_error_handler(const char *format, ...);
extern void *bfd_malloc(bfd_size_type size);
extern int bfd_seek(bfd *abfd, long int offset, int whence);
extern bfd_size_type bfd_bread(void *ptr, bfd_size_type size, bfd *abfd);

#define obj_coff_external_syms(abfd) ((abfd)->coff_external_syms)
#define bfd_coff_symesz(abfd) (sizeof(void *))
#define obj_raw_syment_count(abfd) ((abfd)->raw_syment_count)
#define obj_sym_filepos(abfd) ((abfd)->sym_filepos)