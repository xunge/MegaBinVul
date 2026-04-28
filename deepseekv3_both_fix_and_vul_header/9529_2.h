#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int bfd_vma;
typedef long file_ptr;
typedef unsigned int bfd_size_type;
typedef unsigned int flagword;
typedef unsigned char bfd_byte;
typedef enum { FALSE, TRUE } bfd_boolean;

enum bfd_error {
    bfd_error_no_error = 0,
    bfd_error_system_call,
    bfd_error_invalid_target,
    bfd_error_wrong_format,
    bfd_error_invalid_operation,
    bfd_error_no_memory,
    bfd_error_no_symbols,
    bfd_error_no_armor,
    bfd_error_bad_value
};

typedef struct bfd bfd;
typedef struct asection asection;

#define SEC_HAS_CONTENTS (1 << 0)
#define SEC_LOAD (1 << 1)
#define SEC_ALLOC (1 << 2)
#define SEEK_SET 0
#define EOF (-1)

struct bfd {
    bfd_vma start_address;
    file_ptr (*seek)(bfd *, file_ptr, int);
    file_ptr (*tell)(bfd *);
    bfd_size_type (*bread)(void *, bfd_size_type, bfd *);
    void *(*realloc)(void *, bfd_size_type);
    char *(*alloc)(bfd *, bfd_size_type);
    asection *(*make_section_with_flags)(bfd *, const char *, flagword);
    unsigned int (*count_sections)(bfd *);
    void (*set_error)(enum bfd_error);
};

struct asection {
    bfd_vma vma;
    bfd_vma lma;
    bfd_size_type size;
    file_ptr filepos;
};

extern int ihex_get_byte(bfd *, bfd_boolean *);
extern void ihex_bad_byte(bfd *, unsigned int, int, bfd_boolean);
extern void (*_bfd_error_handler)(const char *, ...);
extern const char *_(const char *);
extern void bfd_set_error(enum bfd_error);
extern int bfd_seek(bfd *, file_ptr, int);
extern file_ptr bfd_tell(bfd *);
extern bfd_size_type bfd_bread(void *, bfd_size_type, bfd *);
extern void *bfd_realloc(void *, bfd_size_type);
extern char *bfd_alloc(bfd *, bfd_size_type);
extern asection *bfd_make_section_with_flags(bfd *, const char *, flagword);
extern unsigned int bfd_count_sections(bfd *);
extern int ISHEX(int);
extern unsigned int HEX2(const char *);
extern unsigned int HEX4(const char *);