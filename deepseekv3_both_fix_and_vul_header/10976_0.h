#include <string.h>
#include <stdlib.h>

#define SASL_OK 0
#define SASL_NOMEM -1

int _buf_alloc(char **out, size_t *alloclen, size_t needed);