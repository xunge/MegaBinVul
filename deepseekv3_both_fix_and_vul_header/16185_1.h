#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stdint.h>

struct archive_string {
    char *s;
    size_t length;
    size_t buffer_length;
};

struct archive_string_conv;

int archive_string_ensure(struct archive_string *, size_t);
int _utf8_to_unicode(uint32_t *pwc, const char *s, size_t n);

#define HAVE_WCRTOMB 1
#define MB_CUR_MAX 4