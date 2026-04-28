#include <stdlib.h>
#include <string.h>

typedef int bfd_boolean;
#define TRUE 1
#define FALSE 0

typedef struct bfd bfd;
typedef struct asection asection;
typedef unsigned long bfd_size_type;
typedef unsigned char bfd_byte;

struct bfd {
    unsigned int flags;
};

struct asection {
    unsigned int flags;
    unsigned int size;
    unsigned int entsize;
    unsigned int alignment_power;
    asection *output_section;
    bfd *owner;
    bfd_size_type rawsize;
};

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
#define SEC_MERGE 0x200
#define SEC_EXCLUDE 0x80
#define SEC_RELOC 0x100
#define SEC_STRINGS 0x400

void *bfd_alloc(bfd *, bfd_size_type);
void *sec_merge_init(unsigned int, unsigned int);
bfd_boolean bfd_get_full_section_contents(bfd *, asection *, bfd_byte **);