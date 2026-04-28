#include <stdint.h>
#include <string.h>

typedef int ret_t;
typedef unsigned int cuint_t;

typedef struct {
    char *buf;
    cuint_t len;
} cherokee_buffer_t;

#define ret_ok 0