#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#define GRP_ENTRY_SIZE 4
#define GRP_COMDAT 1
#define SHT_GROUP 0x1
#define SEC_LINK_ONCE 0x100
#define SEC_LINK_DUPLICATES_DISCARD 0x200
#define FALSE 0
#define TRUE 1
#define SEEK_SET 0

typedef int bfd_boolean;
typedef uint64_t bfd_size_type;

typedef struct bfd bfd;
struct bfd {
    struct {
        void *any;
    } tdata;
};

typedef struct asection asection;
struct asection {
    unsigned int flags;
    const char *group_name;
    asection *next_in_group;
};

typedef struct Elf_Internal_Shdr Elf_Internal_Shdr;
struct Elf_Internal_Shdr {
    unsigned int sh_type;
    bfd_size_type sh_size;
    unsigned int sh_entsize;
    unsigned long sh_offset;
    asection *bfd_section;
    unsigned char *contents;
};

typedef struct elf_internal_group {
    unsigned int flags;
    Elf_Internal_Shdr *shdr;
} Elf_Internal_Group;

struct elf_obj_tdata {
    unsigned int num_group;
    unsigned int num_sections;
    Elf_Internal_Shdr **group_sect_ptr;
    Elf_Internal_Shdr **sections;
};

#define elf_tdata(bfd) ((struct elf_obj_tdata *)((bfd)->tdata.any))
#define elf_elfsections(bfd) (elf_tdata(bfd)->sections)
#define elf_numsections(bfd) (elf_tdata(bfd)->num_sections)
#define elf_next_in_group(sect) ((sect)->next_in_group)
#define elf_group_name(sect) ((sect)->group_name)

extern void *_bfd_alloc2(bfd *, bfd_size_type, bfd_size_type);
#define bfd_alloc2 _bfd_alloc2

extern int bfd_seek(bfd *, long, int);
extern bfd_size_type bfd_bread(void *, bfd_size_type, bfd *);

extern void _bfd_error_handler(const char *, ...);
#define _(x) x

extern void bfd_set_error(int);
#define bfd_error_bad_value 1

extern const char *group_signature(bfd *, Elf_Internal_Shdr *);

#define H_GET_32(abfd, ptr) (*(uint32_t *)(ptr))
#define BFD_ASSERT(expr) ((void)0)