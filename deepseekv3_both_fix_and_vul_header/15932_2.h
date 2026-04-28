typedef struct {
  union {
    struct {
      void* cs;
    } read_lock_;
    struct {
      void* sem;
    } write_lock_;
    struct {
      void* read_mutex_;
      void* write_mutex_;
    };
  } fallback_;
} uv_rwlock_t;

typedef struct uv_mutex_t_s uv_mutex_t;
struct uv_mutex_t_s {
  void* cs;
};

void DeleteCriticalSection(void*);
void CloseHandle(void*);
void uv_mutex_destroy(uv_mutex_t*);