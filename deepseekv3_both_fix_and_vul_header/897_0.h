#include <stdbool.h>
#include <string.h>

typedef bool Bool;
#define TRUE true
#define FALSE false

typedef struct {
    char *name;
    bool enabled;
} SecTypeData;

extern SecTypeData *secTypes;