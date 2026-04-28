#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define SIZE_T_MAX ((size_t)-1)

struct array_list {
    void **array;
    size_t length;
    void (*free_fn)(void *);
};