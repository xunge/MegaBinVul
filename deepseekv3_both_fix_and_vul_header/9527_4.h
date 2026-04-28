#include <stdio.h>
#include <stdlib.h>

typedef unsigned long bfd_vma;
typedef unsigned char bfd_byte;
typedef long bfd_size_type;
typedef long file_ptr;
typedef int bfd_boolean;

#define TRUE 1
#define FALSE 0
#define SEC_HAS_CONTENTS 0x100
#define PE_EXPORT_TABLE 0

struct bfd;

struct asection {
    bfd_vma vma;
    bfd_size_type size;
    char *name;
    unsigned int flags;
    struct asection *next;
};

struct internal_extra_pe_aouthdr {
    bfd_vma ImageBase;
    struct {
        bfd_vma VirtualAddress;
        bfd_size_type Size;
    } DataDirectory[16];
};

struct pe_data_type {
    struct internal_extra_pe_aouthdr pe_opthdr;
};

struct bfd {
    struct asection *sections;
};

typedef struct bfd bfd;
typedef struct asection asection;
typedef struct pe_data_type pe_data_type;

extern bfd_boolean bfd_get_section_contents(bfd *abfd, asection *section, void *location, file_ptr offset, bfd_size_type count);
extern asection *bfd_get_section_by_name(bfd *abfd, const char *name);
extern void *bfd_malloc(bfd_size_type size);
extern void bfd_fprintf_vma(bfd *abfd, FILE *file, bfd_vma addr);
extern long bfd_get_32(bfd *abfd, const bfd_byte *addr);
extern short bfd_get_16(bfd *abfd, const bfd_byte *addr);
extern pe_data_type *pe_data(bfd *abfd);

#define _(x) x