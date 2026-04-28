typedef unsigned long DWORD;
#define INFINITE 0xFFFFFFFF
#define WAIT_OBJECT_0 0

typedef struct uv_mutex_s {
    void* handle;
} uv_mutex_t;

typedef struct uv_semaphore_s {
    void* sem;
} uv_semaphore_t;

typedef struct uv_rwlock_fallback_s {
    uv_semaphore_t write_lock_;
    uv_mutex_t write_mutex_;
} uv_rwlock_fallback_t;

typedef struct uv_rwlock_s {
    uv_rwlock_fallback_t fallback_;
} uv_rwlock_t;

DWORD WaitForSingleObject(void* hHandle, DWORD dwMilliseconds);
DWORD GetLastError(void);
void uv_fatal_error(DWORD err, const char* syscall);
void uv_mutex_lock(uv_mutex_t* mutex);