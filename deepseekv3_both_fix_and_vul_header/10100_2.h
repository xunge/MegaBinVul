#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int bfd_vma;
typedef long file_ptr;
typedef unsigned int bfd_size_type;
typedef unsigned int flagword;
typedef enum { FALSE, TRUE } bfd_boolean;
typedef unsigned char bfd_byte;

struct bfd {
    bfd_vma start_address;
};

struct asection {
    bfd_vma vma;
    bfd_vma lma;
    bfd_size_type size;
    file_ptr filepos;
};

typedef struct bfd bfd;
typedef struct asection asection;

#define SEC_HAS_CONTENTS 0x1
#define SEC_LOAD 0x2
#define SEC_ALLOC 0x4
#define SEEK_SET 0

#define ISHEX(c) (((c) >= '0' && (c) <= '9') || \
                 ((c) >= 'A' && (c) <= 'F') || \
                 ((c) >= 'a' && (c) <= 'f'))
#define HEX2(p) ((unsigned int)(((p)[0] - '0') << 4) + ((p)[1] - '0'))
#define HEX4(p) ((unsigned int)(((p)[0] - '0') << 12) + \
                (((p)[1] - '0') << 8) + \
                (((p)[2] - '0') << 4) + \
                ((p)[3] - '0'))

extern int bfd_seek(bfd *, file_ptr, int);
extern file_ptr bfd_tell(bfd *);
extern int bfd_bread(void *, bfd_size_type, bfd *);
extern void *bfd_realloc(void *, bfd_size_type);
extern void *bfd_alloc(bfd *, bfd_size_type);
extern asection *bfd_make_section_with_flags(bfd *, const char *, flagword);
extern unsigned int bfd_count_sections(bfd *);
extern void bfd_set_error(int);
extern int ihex_get_byte(bfd *, bfd_boolean *);
extern void ihex_bad_byte(bfd *, unsigned int, int, bfd_boolean);

extern void (*_bfd_error_handler)(const char *, ...);
extern const char *_(const char *);

enum bfd_error {
    bfd_error_no_error,
    bfd_error_bad_value
};