#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>

typedef struct libxl_ctx {
    void *xsh;
    void *xch;
} libxl_ctx;

typedef struct libxl__gc {} libxl__gc;
typedef unsigned int xs_transaction_t;

typedef struct xc_domaininfo {
    uint32_t domain;
} xc_domaininfo_t;

typedef struct libxl_dominfo {
    unsigned char uuid[16];
} libxl_dominfo;

typedef struct libxl__domain_userdata_lock {} libxl__domain_userdata_lock;

#define GC_INIT(ctx) libxl__gc *gc = NULL
#define CTX_LOCK
#define CTX_UNLOCK
#define GC_FREE
#define ERROR_LOCK_FAIL (-1)
#define LOGE(level, ...)
#define LOG(level, ...)
#define LIBXL_MIN_DOM0_MEM (0)
#define LIBXL_MAXMEM_CONSTANT (0)

static inline char *libxl__xs_get_dompath(libxl__gc *gc, uint32_t domid) { return NULL; }
static inline char *libxl__sprintf(libxl__gc *gc, const char *fmt, ...) { return NULL; }
static inline char *libxl__xs_read(libxl__gc *gc, xs_transaction_t t, char *path) { return NULL; }
static inline int libxl__fill_dom0_memory_info(libxl__gc *gc, uint32_t *current_target, uint32_t *current_max) { return 0; }
static inline libxl__domain_userdata_lock *libxl__lock_domain_userdata(libxl__gc *gc, uint32_t domid) { return NULL; }
static inline void libxl__unlock_domain_userdata(libxl__domain_userdata_lock *lock) {}
static inline int xs_transaction_start(void *xsh) { return 0; }
static inline int xs_transaction_end(void *xsh, xs_transaction_t t, int abort) { return 0; }
static inline int xc_domain_setmaxmem(void *xch, uint32_t domid, uint64_t memkb) { return 0; }
static inline int xc_domain_set_pod_target(void *xch, uint32_t domid, uint32_t target_pages, void *a, void *b, void *c) { return 0; }
static inline int xc_domain_getinfolist(void *xch, uint32_t domid, int max, xc_domaininfo_t *info) { return 0; }
static inline void libxl_dominfo_init(libxl_dominfo *ptr) {}
static inline void xcinfo2xlinfo(libxl_ctx *ctx, xc_domaininfo_t *info, libxl_dominfo *ptr) {}
static inline char *libxl__uuid2string(libxl__gc *gc, unsigned char *uuid) { return NULL; }
static inline void libxl__xs_write(libxl__gc *gc, xs_transaction_t t, char *path, const char *fmt, ...) {}
static inline void libxl_dominfo_dispose(libxl_dominfo *ptr) {}