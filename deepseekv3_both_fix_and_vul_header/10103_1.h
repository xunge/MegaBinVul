#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct bfd bfd;
typedef bool bfd_boolean;

enum bfd_error {
    bfd_error_file_truncated,
    bfd_error_bad_value
};

extern void (*_bfd_error_handler)(const char *, ...);
extern void bfd_set_error(enum bfd_error);
extern const char *_(const char *);

#define ISPRINT(c) isprint(c)