#include <stdlib.h>
#include <string.h>

#define GNU_DEBUGLINK ".gnu_debuglink"

typedef struct bfd bfd;
typedef struct asection asection;
typedef unsigned char bfd_byte;
typedef unsigned long bfd_size_type;

#define BFD_ASSERT(expr) ((void)0)

unsigned long bfd_get_32(bfd *abfd, void *ptr);
asection *bfd_get_section_by_name(bfd *abfd, const char *name);
bfd_size_type bfd_get_section_size(asection *sect);
int bfd_malloc_and_get_section(bfd *abfd, asection *sect, bfd_byte **contents);