#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct _bc_num *bc_num;

struct _bc_num {
    int n_scale;
};

struct String {
    char* m_data;
    size_t m_size;
    String(char* data, int) : m_data(data), m_size(strlen(data)) {}
    char* data() { return m_data; }
    const char* data() const { return m_data; }
};

enum { AttachString = 0 };

#define HHVM_FUNCTION(name, ...) name(__VA_ARGS__)

extern int64_t bc_precision;
#define BCG(var) (var)

extern int64_t adjust_scale(int64_t scale);
extern void bc_init_num(bc_num* num);
extern void php_str2num(bc_num* num, char* str);
extern void bc_add(bc_num a, bc_num b, bc_num* result, int64_t scale);
extern char* bc_num2str(bc_num num);
extern void bc_free_num(bc_num* num);