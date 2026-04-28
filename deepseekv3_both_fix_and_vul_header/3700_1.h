#include <stdint.h>
#include <string.h>

#define private static
#define FILE_SEARCH 0
#define FILE_REGEX 1
#define FILE_BESTRING16 2
#define FILE_LESTRING16 3
#define FILE_STRING 4
#define FILE_PSTRING 5
#define REGEX_LINE_COUNT 0x01

struct magic_set {
    struct {
        const char *s;
        size_t s_len;
        uint32_t offset;
        size_t rm_len;
    } search;
};

struct magic {
    int str_flags;
    uint32_t str_range;
};

union VALUETYPE {
    char s[1];
};

#define RCAST(type, value) ((type)(value))
#define CAST(type, value) ((type)(value))