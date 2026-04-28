#include <string.h>

typedef int ret_t;
typedef unsigned int cuint_t;

#define CHEROKEE_BUF_INIT {0}
#define ret_ok 0
#define ret_error -1

typedef struct {
    char *buf;
    unsigned int len;
} cherokee_buffer_t;

typedef struct {
    cherokee_buffer_t user;
    cherokee_buffer_t passwd;
} cherokee_validator_t;

#define TRACE(type, format, ...)