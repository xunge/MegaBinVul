#include <stdlib.h>

typedef struct bfd bfd;
typedef int bfd_boolean;
#define bfd_error_no_symbols 0

struct asymbol;
typedef struct asymbol asymbol;

long bfd_get_dynamic_symtab_upper_bound(bfd *);
long bfd_get_symtab_upper_bound(bfd *);
void *bfd_malloc(long);
long bfd_canonicalize_dynamic_symtab(bfd *, asymbol **);
long bfd_canonicalize_symtab(bfd *, asymbol **);
void bfd_set_error(int);