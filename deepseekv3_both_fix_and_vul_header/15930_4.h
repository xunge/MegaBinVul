#include <pthread.h>
#include <errno.h>

typedef unsigned long DWORD;
#define WAIT_OBJECT_0 0
#define WAIT_TIMEOUT 258
#define WAIT_FAILED 0xFFFFFFFF

typedef struct {
    union {
        struct {
            pthread_mutex_t cs;
        } read_lock_;
        struct {
            pthread_mutex_t sem;
        } write_lock_;
        struct {
            pthread_mutex_t read_mutex_;
            pthread_mutex_t write_mutex_;
        };
    };
    unsigned int num_readers_;
} uv_rwlock_fallback_t;

typedef struct {
    uv_rwlock_fallback_t fallback_;
} uv_rwlock_t;

int uv_translate_sys_error(int err);
int uv_mutex_trylock(pthread_mutex_t* mutex);
void uv_mutex_unlock(pthread_mutex_t* mutex);
int TryEnterCriticalSection(pthread_mutex_t* mutex);
void LeaveCriticalSection(pthread_mutex_t* mutex);
DWORD WaitForSingleObject(pthread_mutex_t mutex, int timeout);
int GetLastError();

#define UV_EAGAIN (-11)
#define UV_EIO (-5)