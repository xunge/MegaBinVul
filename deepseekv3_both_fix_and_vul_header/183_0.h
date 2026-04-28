#include <stddef.h>
#include <stdint.h>

typedef intptr_t njs_ret_t;
typedef uint8_t u_char;
typedef int nxt_bool_t;

typedef struct {
    u_char      *start;
    size_t      length;
} nxt_str_t;

typedef struct nxt_mp_s nxt_mp_t;

typedef struct {
    nxt_mp_t    *mem_pool;
} njs_vm_t;

#define nxt_inline static inline
#define nxt_length(str) (sizeof(str) - 1)
#define nxt_slow_path(cond) (cond)
#define NXT_OK 0
#define NXT_ERROR (-1)

static void *nxt_mp_alloc(nxt_mp_t *pool, size_t size);
static u_char *nxt_cpymem(u_char *dst, const u_char *src, size_t len);
static void njs_memory_error(njs_vm_t *vm);