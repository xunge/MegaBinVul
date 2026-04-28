#include <stddef.h>
#include <stdatomic.h>
#include <assert.h>

typedef struct malloc_state *mstate;
struct malloc_state {
    int mutex;
};

struct {
    size_t tcache_bins;
} mp_;

struct tcache_perthread_struct {
    void **entries;
};

extern void *(*__malloc_hook)(size_t, const void *);
extern struct malloc_state main_arena;
extern struct tcache_perthread_struct *tcache;

#define USE_TCACHE 1
#define SINGLE_THREAD_P 0
#define MAYBE_INIT_TCACHE()
#define DIAG_PUSH_NEEDS_COMMENT
#define DIAG_POP_NEEDS_COMMENT
#define LIBC_PROBE(x, y, z)
#define RETURN_ADDRESS(x) (0)
#define __builtin_expect(x, y) (x)
#define atomic_forced_read(x) (x)

size_t request2size(size_t);
size_t csize2tidx(size_t);
void *tcache_get(size_t);
void *_int_malloc(mstate, size_t);
void arena_get(mstate, size_t);
mstate arena_get_retry(mstate, size_t);
int chunk_is_mmapped(void *);
void *mem2chunk(void *);
mstate arena_for_chunk(void *);
void __libc_lock_unlock(int);