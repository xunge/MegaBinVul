#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define GRP_ENTRY_SIZE 4
#define GRP_COMDAT 1
#define SHT_GROUP 0x1
#define SEC_LINK_ONCE 0x40
#define SEC_LINK_DUPLICATES_DISCARD 0x80
#define SEEK_SET 0

typedef struct bfd {
    struct {
        void *any;
    } tdata;
} bfd;

typedef struct asection {
    const char *name;
    unsigned int flags;
    struct asection *next_in_group;
} asection;

typedef struct Elf_Internal_Shdr {
    unsigned int sh_type;
    unsigned int sh_size;
    unsigned int sh_entsize;
    unsigned long sh_offset;
    unsigned char *contents;
    struct asection *bfd_section;
} Elf_Internal_Shdr;

typedef struct elf_internal_group {
    unsigned int flags;
    Elf_Internal_Shdr *shdr;
} Elf_Internal_Group;

typedef unsigned int bfd_size_type;
typedef int bfd_boolean;
#define FALSE 0
#define TRUE 1

typedef long file_ptr;

enum bfd_error {
    bfd_error_no_error,
    bfd_error_bad_value
};

struct elf_obj_tdata {
    unsigned int num_group;
    Elf_Internal_Shdr **group_sect_ptr;
    Elf_Internal_Shdr **elf_elfsections;
    unsigned int elf_numsections;
};

#define elf_tdata(bfd) ((struct elf_obj_tdata *)((bfd)->tdata.any))
#define elf_numsections(abfd) (elf_tdata(abfd)->elf_numsections)
#define elf_elfsections(abfd) (elf_tdata(abfd)->elf_elfsections)
#define elf_group_name(sect) ((sect)->name)
#define elf_next_in_group(sect) ((sect)->next_in_group)

static inline unsigned int H_GET_32(bfd *abfd, unsigned char *addr) {
    return *(uint32_t *)addr;
}

static void (*_bfd_error_handler)(const char *, ...);
static void bfd_set_error(enum bfd_error error);
static void *bfd_alloc2(bfd *abfd, bfd_size_type size, size_t count);
static int bfd_seek(bfd *abfd, file_ptr offset, int whence);
static bfd_size_type bfd_bread(void *ptr, bfd_size_type size, bfd *abfd);
static const char *group_signature(bfd *abfd, Elf_Internal_Shdr *shdr);