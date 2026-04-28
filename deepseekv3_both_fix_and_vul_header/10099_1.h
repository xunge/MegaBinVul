#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct bfd bfd;
typedef bool bfd_boolean;

extern void bfd_set_error(int);
extern void (*_bfd_error_handler)(const char *, ...);
extern int bfd_error_file_truncated;
extern int bfd_error_bad_value;

#define ISPRINT(c) isprint(c)
#define _(str) str