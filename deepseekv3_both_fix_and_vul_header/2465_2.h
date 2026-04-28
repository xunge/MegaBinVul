#include <string.h>
#include <stdint.h>

#define NT_GNU_BUILD_ID 3
#define FLAGS_DID_BUILD_ID 1

struct magic_set;
int file_printf(struct magic_set *, const char *, ...);

#define private static