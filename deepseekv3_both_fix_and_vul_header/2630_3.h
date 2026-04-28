#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POWERPC_LE_PE
#define COFF_WITH_pex64

#define PE_IMPORT_TABLE 1
#define SEC_HAS_CONTENTS 0x100
#define TRUE 1
#define FALSE 0

#define HighBitSet(x) ((x) & 0x80000000)
#define WithoutHighBit(x) ((x) & 0x7fffffff)

typedef int bfd_boolean;
typedef long bfd_signed_vma;
typedef unsigned long bfd_vma;
typedef unsigned long bfd_size_type;
typedef unsigned char bfd_byte;

struct internal_extra_pe_aouthdr {
    bfd_vma ImageBase;
    struct {
        bfd_vma VirtualAddress;
        bfd_vma Size;
    } DataDirectory[16];
};

typedef struct {
    struct internal_extra_pe_aouthdr pe_opthdr;
} pe_data_type;

typedef struct bfd {
    bfd_vma start_address;
    struct asection *sections;
} bfd;

struct asection {
    bfd_vma vma;
    bfd_size_type size;
    char *name;
    unsigned int flags;
    struct asection *next;
};

typedef struct asection asection;

static pe_data_type *pe_data(bfd *abfd) { return NULL; }
static asection *bfd_get_section_by_name(bfd *abfd, const char *name) { return NULL; }
static bfd_boolean bfd_malloc_and_get_section(bfd *abfd, asection *section, bfd_byte **data) { return FALSE; }
static bfd_boolean bfd_get_section_contents(bfd *abfd, asection *section, void *location, bfd_vma offset, bfd_size_type count) { return FALSE; }
static unsigned long bfd_get_32(bfd *abfd, const bfd_byte *addr) { return 0; }
static unsigned short bfd_get_16(bfd *abfd, const bfd_byte *addr) { return 0; }
static void *bfd_malloc(bfd_size_type size) { return malloc(size); }
#define _(x) x