#include <stddef.h>

struct uv_mutex_s {
    void* handle;
};

typedef struct uv_mutex_s uv_mutex_t;

typedef struct {
  union {
    struct {
      void* cs;
    } read_lock_;
    struct {
      void* sem;
    } write_lock_;
    struct {
      uv_mutex_t read_mutex_;
      uv_mutex_t write_mutex_;
    };
  };
  unsigned int num_readers_;
} uv_rwlock_t__fallback;

typedef struct {
  uv_rwlock_t__fallback fallback_;
} uv_rwlock_t;

void uv_mutex_lock(uv_mutex_t* mutex);
void uv_mutex_unlock(uv_mutex_t* mutex);
void uv_fatal_error(int error, const char* syscall);
void EnterCriticalSection(void*);
void LeaveCriticalSection(void*);
int ReleaseSemaphore(void*, int, void*);
int GetLastError();