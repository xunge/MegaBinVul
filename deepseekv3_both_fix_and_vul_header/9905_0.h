#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t used;
} String;

enum {
    OPSYMBOLS
};

int oper;
int need_real_defines;

void addstring(String *buff, const char *str);