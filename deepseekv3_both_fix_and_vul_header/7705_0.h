#include <string.h>
#include <ctype.h>

#define NUL '\0'
typedef unsigned char char_u;

static int vim_isdigit(int c);
static char_u *vim_strchr(const char_u *str, int c);
static int STRNCMP(const char_u *s1, const char_u *s2, size_t n);

static int vim_isdigit(int c) {
    return isdigit(c);
}

static char_u *vim_strchr(const char_u *str, int c) {
    return (char_u *)strchr((const char *)str, c);
}

static int STRNCMP(const char_u *s1, const char_u *s2, size_t n) {
    return strncmp((const char *)s1, (const char *)s2, n);
}