#include <stdbool.h>
#include <stdlib.h>

struct spk_ldisc_data {
    struct {
        unsigned int done;
    } completion;
    bool buf_free;
};

struct tty_struct {
    struct {
        int (*write)(void);
    } *ops;
    void *disc_data;
};

static struct {
    int lock;
} speakup_tty_mutex;

static struct tty_struct *speakup_tty;

#define GFP_KERNEL 0
#define EOPNOTSUPP 1
#define EBUSY 2
#define ENOMEM 3

static inline void mutex_lock(void *lock) {}
static inline void mutex_unlock(void *lock) {}
static inline void init_completion(void *comp) {}
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }