typedef unsigned long DWORD;
#define INFINITE 0xFFFFFFFF
#define WAIT_OBJECT_0 0

typedef struct {
    void* Ptr;
} CRITICAL_SECTION;

typedef void* HANDLE;
typedef void* uv_mutex_t;

typedef struct {
    union {
        struct {
            CRITICAL_SECTION cs;
        } read_lock_;
        struct {
            HANDLE sem;
        } write_lock_;
        struct {
            uv_mutex_t read_mutex_;
            uv_mutex_t write_mutex_;
        };
    };
    unsigned int num_readers_;
} uv_rwlock_fallback_t;

typedef struct {
    uv_rwlock_fallback_t fallback_;
} uv_rwlock_t;

void EnterCriticalSection(CRITICAL_SECTION*);
void LeaveCriticalSection(CRITICAL_SECTION*);
DWORD WaitForSingleObject(HANDLE, DWORD);
DWORD GetLastError(void);
void uv_fatal_error(DWORD, const char*);
void uv_mutex_lock(uv_mutex_t*);
void uv_mutex_unlock(uv_mutex_t*);