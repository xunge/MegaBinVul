#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef int bfd_boolean;
#define TRUE 1
#define FALSE 0

typedef struct bfd {
    unsigned int flags;
} bfd;

typedef struct asection {
    unsigned int flags;
    unsigned int size;
    unsigned int entsize;
    unsigned int alignment_power;
    struct asection *output_section;
    struct bfd *owner;
    unsigned int rawsize;
} asection;

typedef unsigned char bfd_byte;
typedef size_t bfd_size_type;

struct sec_merge_info {
    struct sec_merge_info *next;
    struct sec_merge_sec_info *chain;
    void *htab;
};

struct sec_merge_sec_info {
    struct sec_merge_sec_info *next;
    asection *sec;
    void **psecinfo;
    void *htab;
    void *first_str;
    bfd_byte contents[1];
};

#define DYNAMIC 0x1
#define SEC_MERGE 0x100
#define SEC_EXCLUDE 0x200
#define SEC_RELOC 0x400
#define SEC_STRINGS 0x800

void *sec_merge_init(unsigned int entsize, int flags);
void *bfd_alloc(bfd *abfd, bfd_size_type amt);
bfd_boolean bfd_get_full_section_contents(bfd *abfd, asection *sec, bfd_byte **contents);