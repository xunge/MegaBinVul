#include <stdbool.h>
#include <stddef.h>

#define fallthrough ((void)0)

typedef long loff_t;

struct fscache_cookie {
    unsigned long flags;
    unsigned int debug_id;
    unsigned int inval_counter;
    int state;
    void *lock;
};

enum {
    FSCACHE_COOKIE_RELINQUISHED,
    FSCACHE_COOKIE_DISABLED,
    FSCACHE_COOKIE_NO_DATA_TO_READ,
    FSCACHE_COOKIE_DO_INVALIDATE,
};

enum fscache_cookie_state {
    FSCACHE_COOKIE_STATE_INVALIDATING,
    FSCACHE_COOKIE_STATE_LOOKING_UP,
    FSCACHE_COOKIE_STATE_CREATING,
    FSCACHE_COOKIE_STATE_ACTIVE,
};

#define FSCACHE_INVAL_DIO_WRITE 0x01
#define fscache_access_invalidate_cookie 0

extern unsigned int fscache_n_invalidates;

void _enter(const char *fmt, ...);
void _leave(const char *fmt, ...);
void fscache_stat(unsigned int *);
void fscache_update_aux(struct fscache_cookie *cookie, const void *aux_data, loff_t *new_size);
bool fscache_begin_cookie_access(struct fscache_cookie *cookie, int access_type);
void __fscache_begin_cookie_access(struct fscache_cookie *cookie, int access_type);
void __fscache_set_cookie_state(struct fscache_cookie *cookie, int state);
void wake_up_cookie_state(struct fscache_cookie *cookie);
void fscache_queue_cookie(struct fscache_cookie *cookie, void (*func)(struct fscache_cookie *));
void fscache_cookie_get_inval_work(struct fscache_cookie *cookie);
void trace_fscache_invalidate(struct fscache_cookie *cookie, loff_t new_size);
void spin_lock(void *lock);
void spin_unlock(void *lock);
int test_bit(int nr, unsigned long *addr);
int test_and_set_bit(int nr, unsigned long *addr);
void set_bit(int nr, unsigned long *addr);
int WARN(int condition, const char *fmt, ...);