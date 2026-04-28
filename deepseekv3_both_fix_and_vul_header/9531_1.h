#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct bfd bfd;
typedef bool bfd_boolean;
typedef enum {
    bfd_error_no_error,
    bfd_error_file_truncated,
    bfd_error_bad_value
} bfd_error_type;

extern void bfd_set_error(bfd_error_type error);
extern void (*_bfd_error_handler)(const char *, ...);
extern const char *_(const char *);

#define ISPRINT(c) isprint(c)