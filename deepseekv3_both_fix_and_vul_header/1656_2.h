#include <stdatomic.h>
#include <stddef.h>
#include <sys/types.h>
#include <pthread.h>

#define SNDRV_PCM_STREAM_PLAYBACK 0
#define SNDRV_PCM_STREAM_CAPTURE 1
#define O_NONBLOCK 04000
#define ERESTARTSYS 512
#define SNDRV_PCM_ACCESS_RW_INTERLEAVED 0
#define SNDRV_PCM_ACCESS_RW_NONINTERLEAVED 1
#define SNDRV_PCM_IOCTL_DRAIN 0x40104d14
#define SNDRV_PCM_IOCTL_DROP 0x40044d15

struct snd_pcm_oss_file {
    struct snd_pcm_substream *streams[2];
};

struct snd_pcm_substream {
    struct snd_pcm_runtime *runtime;
    unsigned int f_flags;
    atomic_int mmap_count;
    struct snd_pcm *pcm;
};

struct snd_pcm_runtime {
    struct {
        unsigned int buffer_used;
        unsigned int period_bytes;
        unsigned int period_ptr;
        atomic_int rw_ref;
        pthread_mutex_t params_lock;
        unsigned char *buffer;
        int prepare;
        int format;
    } oss;
    struct {
        unsigned int appl_ptr;
    } *control;
    unsigned int period_size;
    unsigned int access;
};

typedef int snd_pcm_format_t;

static inline int atomic_read(const atomic_int *v) { return atomic_load(v); }
static inline void atomic_inc(atomic_int *v) { atomic_fetch_add(v, 1); }
static inline void atomic_dec(atomic_int *v) { atomic_fetch_sub(v, 1); }
static inline int mutex_lock_interruptible(pthread_mutex_t *lock) { return pthread_mutex_lock(lock); }
static inline int mutex_lock(pthread_mutex_t *lock) { return pthread_mutex_lock(lock); }
static inline int mutex_unlock(pthread_mutex_t *lock) { return pthread_mutex_unlock(lock); }