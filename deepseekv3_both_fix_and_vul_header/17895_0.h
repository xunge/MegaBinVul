#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *c;
    size_t len;
    size_t a;
} smart_str;

typedef struct _timelib_rel_time {
    int y, m, d, h, i, s;
    int days;
    int invert;
} timelib_rel_time;

static char *estrdup(const char *s);
static int slprintf(char *str, size_t size, const char *format, ...);
static void smart_str_appendl(smart_str *str, const char *append, size_t length);
static void smart_str_appendc(smart_str *str, char append);
static void smart_str_0(smart_str *str);