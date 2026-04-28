#include <stdlib.h>
#include <string.h>

typedef unsigned long bfd_vma;
typedef unsigned long bfd_size_type;
typedef long file_ptr;
typedef unsigned char bfd_byte;

struct asection {
    bfd_vma vma;
    bfd_size_type size;
    unsigned int flags;
    struct asection *next;
};

struct bfd_build_id {
    bfd_size_type size;
    unsigned char data[1];
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
    struct bfd_build_id *build_id;
};

struct external_IMAGE_DEBUG_DIRECTORY {
    unsigned long Characteristics;
    unsigned long TimeDateStamp;
    unsigned short MajorVersion;
    unsigned short MinorVersion;
    unsigned long Type;
    unsigned long SizeOfData;
    unsigned long AddressOfRawData;
    unsigned long PointerToRawData;
};

struct internal_IMAGE_DEBUG_DIRECTORY {
    unsigned long Type;
    unsigned long SizeOfData;
    unsigned long PointerToRawData;
};

typedef struct {
    unsigned long SignatureLength;
    unsigned char Signature[1];
} CODEVIEW_INFO;

#define PE_DEBUG_DATA 6
#define PE_IMAGE_DEBUG_TYPE_CODEVIEW 2
#define SEC_HAS_CONTENTS 0x100

typedef struct bfd bfd;
typedef struct pe_data_type pe_data_type;
typedef struct asection asection;

extern pe_data_type *pe_data(bfd *);
extern void _bfd_error_handler(const char *, ...);
extern void _bfd_XXi_swap_debugdir_in(bfd *, struct external_IMAGE_DEBUG_DIRECTORY *, struct internal_IMAGE_DEBUG_DIRECTORY *);
extern int _bfd_XXi_slurp_codeview_record(bfd *, file_ptr, unsigned long, CODEVIEW_INFO *);
extern int bfd_malloc_and_get_section(bfd *, asection *, bfd_byte **);
extern void *bfd_alloc(bfd *, bfd_size_type);