#include <string.h>

#define MYSOFA_EXPORT

struct MYSOFA_ATTRIBUTE {
    char *name;
    char *value;
    struct MYSOFA_ATTRIBUTE *next;
};