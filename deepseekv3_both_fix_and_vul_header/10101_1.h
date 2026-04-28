#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int bfd_boolean;
typedef unsigned char bfd_byte;
typedef size_t bfd_size_type;

struct bfd;
typedef struct bfd bfd;

struct asection {
    unsigned long filepos;
    bfd_size_type size;
};
typedef struct asection asection;

#define SEEK_SET 0
#define EOF (-1)
#define TRUE 1
#define FALSE 0

#define HEX2(x) (0)
#define BFD_ASSERT(x)

extern int bfd_seek(bfd *, unsigned long, int);
extern bfd_size_type bfd_bread(void *, bfd_size_type, bfd *);
extern int ihex_get_byte(bfd *, bfd_boolean *);
extern void (*_bfd_error_handler)(const char *, ...);
extern void bfd_set_error(int);
extern void *bfd_realloc(void *, bfd_size_type);

enum bfd_error {
    bfd_error_no_error,
    bfd_error_bad_value
};