#include <errno.h>
#include <wchar.h>

#define FAT_LFN_LEN 255
#define ENAMETOOLONG 36
#define EINVAL 22

struct nls_table {
    int (*char2uni)(const unsigned char *, int, wchar_t *);
};

#define UTF16_HOST_ENDIAN 0