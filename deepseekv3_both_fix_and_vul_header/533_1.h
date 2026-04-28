#include <string.h>

typedef struct fz_context fz_context;

typedef struct {
    char *utf8;
    int pos;
    int edited;
} editable_str;

int fz_chartorune(int *rune, const char *str);