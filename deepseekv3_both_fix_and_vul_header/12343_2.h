#include <cstdint>
#include <cstdlib>
#include <cstring>

#define HHVM_FUNCTION(name, ...) name(__VA_ARGS__)

typedef struct bc_struct {
    int n_scale;
} *bc_num;

struct String {
    const char* data() const;
    String(const char*, int);
};

enum { AttachString };

extern int64_t BCG(int);
extern int64_t adjust_scale(int64_t);
extern void bc_init_num(bc_num*);
extern void bc_free_num(bc_num*);
extern void php_str2num(bc_num*, char*);
extern void bc_sub(bc_num, bc_num, bc_num*, int64_t);
extern char* bc_num2str(bc_num);
extern int64_t bc_precision;