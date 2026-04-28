#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>

typedef unsigned long int Lmid_t;
#define DL_NNS 0
#define __RTLD_OPENEXEC 0
#define RTLD_DEEPBIND 0
#define NO_TLS_OFFSET 0
#define lt_executable 0
#define SHARED 0
#define DL_DEBUG_UNUSED 0
#define internal_function

struct r_scope_elem {
    struct link_map **r_list;
};

struct libname_list {
    char *name;
    int dont_free;
};

struct auditstate {
    uintptr_t cookie;
};

struct link_map {
    struct link_map *l_real;
    struct r_scope_elem l_symbolic_searchlist;
    struct libname_list *l_libname;
    char *l_name;
    int l_type;
    int l_used;
    struct link_map *l_loader;
    long l_tls_offset;
    Lmid_t l_ns;
    struct r_scope_elem *l_scope_mem[1];
    struct r_scope_elem **l_scope;
    int l_scope_max;
    struct r_scope_elem *l_local_scope[1];
    struct r_scope_elem l_searchlist;
    char *l_origin;
    struct auditstate *l_audit;
};

struct rtld_global {
    struct {
        struct link_map *_ns_loaded;
    } dl_ns[1];
};

struct rtld_global_ro {
    unsigned int dl_naudit;
    unsigned int dl_debug_mask;
};

extern struct rtld_global _rtld_global;
extern struct rtld_global_ro _rtld_global_ro;

#define GL(name) _rtld_global.name
#define GLRO(name) _rtld_global_ro.name

extern char *__getcwd(char *buf, size_t size);
extern void *__mempcpy(void *dest, const void *src, size_t n);
#define INTUSE(name) name
extern int __libc_enable_secure;