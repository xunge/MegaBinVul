#include <string.h>
#include <stddef.h>

#define LABEL_BUF_SIZE 256

int ossl_a2ulabel(const char *a, char *a_ulabel, size_t *a_size);