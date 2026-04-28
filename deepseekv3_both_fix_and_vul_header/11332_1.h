#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define AFSTOKEN_K5_COMPONENTS_MAX 256
#define AFSTOKEN_STRING_MAX 1024
#define AFSTOKEN_K5_REALM_MAX 1024

struct krb5_principal {
    unsigned int n_name_parts;
    char **name_parts;
    char *realm;
};

#define GFP_KERNEL 0
#define ENOMEM (-12)
#define EINVAL (-22)

#define _enter(fmt, ...)
#define _leave(fmt, ...) 
#define _debug(fmt, ...)

typedef uint32_t __be32;

static void *kcalloc(size_t n, size_t size, int flags) {
    return calloc(n, size);
}

static void *kmalloc(size_t size, int flags) {
    return malloc(size);
}