#include <string.h>
#include <stddef.h>

#define SYMNMLEN 8
#define C_SECTION 0x68
#define C_STAT 0x00

typedef unsigned long flagword;

#define SEC_HAS_CONTENTS 0x100
#define SEC_ALLOC 0x2
#define SEC_DATA 0x40
#define SEC_LOAD 0x1

typedef enum {
    bfd_error_invalid_target
} bfd_error_type;

struct asection {
    unsigned int target_index;
    struct asection *next;
    flagword flags;
    unsigned long vma;
    unsigned long lma;
    unsigned long size;
    unsigned long filepos;
    unsigned long rel_filepos;
    unsigned int reloc_count;
    unsigned long line_filepos;
    unsigned int lineno_count;
    void *userdata;
    unsigned int alignment_power;
};

struct bfd {
    struct asection *sections;
};

typedef struct bfd bfd;
typedef struct asection asection;

struct internal_syment {
    union {
        char _n_name[SYMNMLEN];
        struct {
            unsigned long _n_zeroes;
            unsigned long _n_offset;
        } _n_n;
    } _n;
    long n_value;
    short n_scnum;
    unsigned short n_type;
    unsigned char n_sclass;
    unsigned char n_numaux;
};

typedef struct {
    union {
        char e_name[SYMNMLEN];
        struct {
            unsigned long e_zeroes;
            unsigned long e_offset;
        } e;
    } e;
    unsigned long e_value;
    unsigned short e_scnum;
    unsigned short e_type;
    unsigned char e_sclass;
    unsigned char e_numaux;
} SYMENT;

#define H_GET_32(abfd, ptr) (*(unsigned long *)(ptr))
#define H_GET_16(abfd, ptr) (*(unsigned short *)(ptr))
#define H_GET_8(abfd, ptr) (*(unsigned char *)(ptr))

extern const char *_bfd_coff_internal_syment_name(bfd *, struct internal_syment *, char *);
extern void _bfd_error_handler(const char *, ...);
extern void bfd_set_error(bfd_error_type);
extern asection *bfd_get_section_by_name(bfd *, const char *);
extern void *bfd_alloc(bfd *, size_t);
extern asection *bfd_make_section_anyway_with_flags(bfd *, const char *, flagword);