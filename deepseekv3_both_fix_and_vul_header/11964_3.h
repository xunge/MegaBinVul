#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <stddef.h>
#include <sys/types.h>

typedef uint32_t gunichar;

#define GLIB_CHECK_VERSION(a,b,c) 0

static size_t g_utf8_strlen(const char *p, ssize_t len);
static const char *g_utf8_find_next_char(const char *p, const char *end);
static gunichar g_utf8_get_char_validated(const char *p, ssize_t max_len);
static gunichar g_unichar_tolower(gunichar c);