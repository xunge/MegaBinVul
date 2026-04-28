#include <string.h>

typedef struct field_info field_info;

struct field_info {
    char *value;
};

void fvalue_set_string(char **fv, const char *value);