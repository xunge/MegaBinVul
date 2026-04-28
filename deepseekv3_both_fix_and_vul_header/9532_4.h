#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int bfd_boolean;
#define FALSE 0
#define TRUE 1

typedef long file_ptr;
typedef unsigned long bfd_size_type;
typedef unsigned long bfd_vma;
typedef unsigned char bfd_byte;

typedef struct bfd {
    bfd_vma start_address;
} bfd;

typedef struct asection {
    bfd_vma vma;
    bfd_vma lma;
    bfd_size_type size;
    file_ptr filepos;
} asection;

typedef unsigned int flagword;
#define SEC_HAS_CONTENTS (1 << 0)
#define SEC_LOAD (1 << 1)
#define SEC_ALLOC (1 << 2)

#define SEEK_SET 0
#define EOF (-1)

#define ISSPACE(c) (isspace(c))
#define ISHEX(c) (isxdigit(c))
#define HEX(p) (strtoul(p, NULL, 16))
#define NIBBLE(c) (isdigit(c) ? (c - '0') : (tolower(c) - 'a' + 10))

extern int bfd_seek(bfd *, file_ptr, int);
extern int srec_get_byte(bfd *, bfd_boolean *);
extern void srec_bad_byte(bfd *, unsigned int, int, bfd_boolean);
extern bfd_byte *bfd_malloc(bfd_size_type);
extern bfd_byte *bfd_realloc(void *, bfd_size_type);
extern void *bfd_alloc(bfd *, bfd_size_type);
extern bfd_boolean srec_new_symbol(bfd *, char *, bfd_vma);
extern file_ptr bfd_tell(bfd *);
extern int bfd_bread(void *, bfd_size_type, bfd *);
extern unsigned int bfd_count_sections(bfd *);
extern asection *bfd_make_section_with_flags(bfd *, char *, flagword);
extern void bfd_set_error(int);
extern void (*_bfd_error_handler)(const char *, ...);
extern const char * _(const char *);

#define bfd_error_bad_value 1