#include <stdint.h>
#include <stddef.h>

typedef struct {
    void* sem;
} uv_sem_t;

typedef struct {
    void* mutex_;
} uv_mutex_t;

typedef struct {
    uv_sem_t write_lock_;
    uv_mutex_t write_mutex_;
} uv_rwlock_fallback_t;

typedef struct {
    uv_rwlock_fallback_t fallback_;
} uv_rwlock_t;

int ReleaseSemaphore(void* hSemaphore, int lReleaseCount, void* lpPreviousCount);
uint32_t GetLastError(void);
void uv_mutex_unlock(uv_mutex_t* mutex);
void uv_fatal_error(uint32_t error, const char* syscall);