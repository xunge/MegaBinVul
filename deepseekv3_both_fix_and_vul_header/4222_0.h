#include <stdint.h>
#include <stdlib.h>

typedef int pixman_bool_t;
typedef int pixman_format_code_t;

#define PIXMAN_FORMAT_BPP(format) ((format) & 0xff)

static int _pixman_multiply_overflows_int(int a, int b);
static int _pixman_addition_overflows_int(int a, int b);
static int _pixman_multiply_overflows_size(size_t a, size_t b);