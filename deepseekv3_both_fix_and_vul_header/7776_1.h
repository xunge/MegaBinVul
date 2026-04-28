#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define NJS_MAX_PATH PATH_MAX

typedef int njs_int_t;
typedef unsigned char u_char;
typedef int njs_bool_t;

typedef struct {
    u_char *start;
    size_t length;
} njs_str_t;

typedef struct {
    njs_str_t name;
    char path[NJS_MAX_PATH + 1];
    int fd;
    njs_str_t file;
} njs_module_info_t;

typedef struct njs_vm_s njs_vm_t;

#define njs_slow_path(expr) (expr)

#define NJS_OK 0
#define NJS_ERROR -1
#define NJS_DECLINED -2

static void *njs_cpymem(void *dst, const void *src, size_t n) {
    return memcpy(dst, src, n) + n;
}

static size_t njs_strlen(const u_char *s) {
    return strlen((const char *)s);
}