#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define TRUE true
#define FALSE false
#define WAIT_TIMEOUT 0x102

typedef struct _MonoThread {
    pthread_t handle;
} MonoThread;

extern bool gc_disabled;
extern pthread_cond_t *shutdown_event;
extern bool finished;
extern MonoThread *gc_thread;
extern bool suspend_finalizers;

pthread_mutex_t handle_section;
pthread_mutex_t allocator_section;
pthread_mutex_t finalizer_mutex;
pthread_mutex_t reference_queue_mutex;

void g_message(const char *format, ...);
void g_warning(const char *format, ...);
MonoThread* mono_thread_internal_current(void);
void mono_gc_finalize_notify(void);
void mono_thread_internal_stop(MonoThread *thread);

static inline int ResetEvent(pthread_cond_t *cond) {
    return pthread_cond_broadcast(cond);
}

static inline int WaitForSingleObjectEx(pthread_cond_t *cond, unsigned ms, bool alertable) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_nsec += (ms % 1000) * 1000000;
    ts.tv_sec += ms / 1000 + ts.tv_nsec / 1000000000;
    ts.tv_nsec %= 1000000000;
    
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);
    int ret = pthread_cond_timedwait(cond, &mutex, &ts);
    pthread_mutex_unlock(&mutex);
    return ret == ETIMEDOUT ? WAIT_TIMEOUT : 0;
}

static inline void Sleep(unsigned ms) {
    usleep(ms * 1000);
}

static inline void DeleteCriticalSection(pthread_mutex_t *mutex) {
    pthread_mutex_destroy(mutex);
}