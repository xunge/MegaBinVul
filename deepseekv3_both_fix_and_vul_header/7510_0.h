#include <stdbool.h>

typedef struct r_anal_t {
    void *reg;
} RAnal;

bool r_reg_set_profile_string(void *reg, const char *str);