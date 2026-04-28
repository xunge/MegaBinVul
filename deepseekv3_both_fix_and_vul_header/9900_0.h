#include <string.h>

typedef struct {
    char *data;
    size_t used;
} String;

extern int need_real_defines;
extern int oper;

#define OPSYMBOLS 0

void addstring(String *buff, const char *str);