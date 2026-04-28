#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct _mbfl_encoding mbfl_encoding;
typedef int mbfl_no_encoding;

typedef struct {
    mbfl_no_encoding *default_detect_order_list;
    int default_detect_order_list_size;
} MBSTRG_t;

extern MBSTRG_t MBSTRG;

#define MBSTRG(field) (MBSTRG.field)

extern char* string_memnstr(const char *haystack, const char *needle, int needle_len, const char *end);
extern mbfl_encoding* mbfl_no2encoding(mbfl_no_encoding no_encoding);
extern mbfl_encoding* mbfl_name2encoding(const char *name);

namespace req {
    extern char* strndup(const char *s, size_t n);
    extern void free(void *ptr);
}

MBSTRG_t MBSTRG = {
    NULL,
    0
};