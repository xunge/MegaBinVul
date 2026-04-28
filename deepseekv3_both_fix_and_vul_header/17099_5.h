#include <stddef.h>
#include <sys/types.h>

#define SNDRV_SEQ_LFLG_OUTPUT 0x1
#define SNDRV_SEQ_EXT_MASK 0xFFFF0000
#define SNDRV_SEQ_EXT_USRPTR 0x80000000
#define SNDRV_SEQ_EVENT_NONE 0
#define ENXIO 6
#define ENOMEM 12
#define EINVAL 22
#define EFAULT 14
#define O_NONBLOCK 04000

struct file {
    void *private_data;
    int f_flags;
};

struct snd_seq_client {
    int number;
    unsigned int accept_output;
    struct snd_seq_pool *pool;
    unsigned int convert32;
    struct mutex {
        int locked;
    } ioctl_mutex;
};

struct snd_seq_pool {
    int size;
};

struct snd_seq_event {
    int type;
    union {
        struct {
            int len;
            void *ptr;
        } ext;
        int raw32[8];
    } data;
    struct {
        int client;
    } source;
};

#define __user
#define __force

static inline int snd_seq_file_flags(struct file *file) { return 0; }
static inline int snd_BUG_ON(int condition) { return 0; }
static inline int snd_seq_write_pool_allocated(struct snd_seq_client *client) { return 0; }
static inline int snd_seq_pool_init(struct snd_seq_pool *pool) { return 0; }
static inline int check_event_type_and_length(struct snd_seq_event *event) { return 0; }
static inline int snd_seq_ev_is_reserved(struct snd_seq_event *event) { return 0; }
static inline int snd_seq_ev_is_variable(struct snd_seq_event *event) { return 0; }
static inline int snd_seq_ev_is_varusr(struct snd_seq_event *event) { return 0; }
static inline int snd_seq_client_enqueue_event(struct snd_seq_client *client, struct snd_seq_event *event, struct file *file, int nonblock, int atomic, int hop) { return 0; }
static inline int copy_from_user(void *to, const void *from, size_t n) { return 0; }
static inline void *compat_ptr(long uptr) { return (void *)uptr; }
static inline void mutex_lock(struct mutex *mutex) { mutex->locked = 1; }
static inline void mutex_unlock(struct mutex *mutex) { mutex->locked = 0; }