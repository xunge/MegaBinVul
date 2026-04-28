#include <stddef.h>

typedef struct jv* jv;
typedef const char* pfunc;

struct dtoa_context {
    int dummy;  // placeholder for actual dtoa implementation
};

struct jv_parser {
    char* tokenbuf;
    int tokenpos;
    struct dtoa_context dtoa;
};

jv jv_true(void);
jv jv_false(void);
jv jv_null(void);
jv jv_number(double d);
double jvp_strtod(struct dtoa_context* d, const char* str, char** endptr);
pfunc value(struct jv_parser* p, jv val);
void TRY(pfunc result);