typedef unsigned long DWORD;
typedef void* HANDLE;

#define WAIT_OBJECT_0 0
#define WAIT_TIMEOUT 258
#define WAIT_FAILED 0xFFFFFFFF
#define UV_EAGAIN (-11)
#define UV_EIO (-5)

typedef struct uv_mutex_s {
    void* handle;
} uv_mutex_t;

typedef struct {
    uv_mutex_t write_mutex_;
    struct {
        HANDLE sem;
    } write_lock_;
} uv_rwlock_fallback_t;

typedef struct uv_rwlock_s {
    uv_rwlock_fallback_t fallback_;
} uv_rwlock_t;

DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
DWORD GetLastError(void);
int uv_translate_sys_error(DWORD sys_errno);
int uv_mutex_trylock(uv_mutex_t* mutex);