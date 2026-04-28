#include <string.h>

struct MYSOFA_ATTRIBUTE {
    char *name;
    char *value;
    struct MYSOFA_ATTRIBUTE *next;
};