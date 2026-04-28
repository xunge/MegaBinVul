#include <stdint.h>

#define HHVM_FUNCTION(name, ...) name(__VA_ARGS__)

struct _bc_num {
    int n_scale;
};
typedef struct _bc_num *bc_num;

class String {
public:
    const char* data() const;
    String(const char*, int);
};

enum { AttachString };

extern int bc_precision;
#define BCG(x) (x)

void bc_init_num(bc_num* num);
void php_str2num(bc_num* num, char* str);
void bc_multiply(bc_num num1, bc_num num2, bc_num* result, int64_t scale);
char* bc_num2str(bc_num num);
void bc_free_num(bc_num* num);

static int64_t adjust_scale(int64_t scale) {
    return scale < 0 ? BCG(bc_precision) : scale;
}