#include <stdio.h>
#include <stdlib.h>

typedef unsigned long bfd_vma;
typedef bfd_vma ufile_ptr;

struct bfd;
struct asection {
    const char *name;
    unsigned long flags;
    unsigned int reloc_count;
};

typedef struct bfd bfd;
typedef struct asection asection;

struct arelent;
typedef struct arelent arelent;

extern arelent **syms;
extern void bfd_fatal(const char *);
extern void non_fatal(const char *, ...);
extern void dump_reloc_set(bfd *, asection *, arelent **, long);
extern int process_section_p(asection *);
extern void *xmalloc(size_t);

#define SEC_RELOC 0x100
#define BFD_IN_MEMORY 0x200
#define BFD_LINKER_CREATED 0x400
#define ATTRIBUTE_UNUSED __attribute__((unused))

int bfd_is_abs_section(asection *);
int bfd_is_und_section(asection *);
int bfd_is_com_section(asection *);
long bfd_get_reloc_upper_bound(bfd *, asection *);
const char *bfd_get_filename(bfd *);
unsigned long bfd_get_file_flags(bfd *);
ufile_ptr bfd_get_file_size(bfd *);
void bfd_set_error(int);
long bfd_canonicalize_reloc(bfd *, asection *, arelent **, arelent **);

#define bfd_error_file_truncated 1
#define _(x) x