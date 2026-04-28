#include <stdint.h>

#define HHVM_FUNCTION(name, ...) name(__VA_ARGS__)

typedef struct {
    void* n_value;
    int n_len;
    int n_scale;
    int n_sign;
} bc_num;

struct String {
    const char* data() const;
};

extern int64_t adjust_scale(int64_t scale);
extern void bc_init_num(bc_num* num);
extern void bc_str2num(bc_num* num, char* str, int64_t scale);
extern int64_t bc_compare(bc_num num1, bc_num num2);
extern void bc_free_num(bc_num* num);
extern int64_t BCG(int64_t);
extern int64_t bc_precision;