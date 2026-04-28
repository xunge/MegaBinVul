#include <stdlib.h>
#include <stdatomic.h>

#define GFP_KERNEL 0
#define ENOMEM 12
#define CHANNEL 1

struct net;
struct ppp_channel {
    void *ppp;
    int hdrlen;
};

struct ppp_file {
    int hdrlen;
    int index;
};

struct channel {
    struct ppp_channel *chan;
    struct net *chan_net;
    struct ppp_file file;
    struct {
        int count;
    } chan_sem;
    struct {
        int lock;
    } downl;
    struct {
        int lock;
    } upl;
    struct {
        struct channel *next;
        struct channel *prev;
    } list;
    int index;
#ifdef CONFIG_PPP_MULTILINK
    int lastseq;
#endif
    void *ppp;
};

struct ppp_net {
    struct {
        int lock;
    } all_channels_lock;
    int last_channel_index;
    struct {
        struct channel *next;
    } new_channels;
};

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void init_rwsem(void *sem) {}
static inline void spin_lock_init(void *lock) {}
static inline void rwlock_init(void *lock) {}
static inline void spin_lock_bh(void *lock) {}
static inline void list_add(void *list, void *head) {}
static inline void atomic_inc(atomic_int *count) { (*count)++; }
static inline void spin_unlock_bh(void *lock) {}

extern struct ppp_net *ppp_pernet(struct net *net);
extern atomic_int channel_count;
extern void init_ppp_file(struct ppp_file *file, int type);