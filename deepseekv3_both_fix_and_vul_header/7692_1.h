#include <stdbool.h>

typedef struct RAnal {
    void *reg;
} RAnal;

bool r_reg_set_profile_string(void *reg, const char *p);