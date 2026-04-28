#include <stdint.h>
#include <stddef.h>

typedef void* HANDLE;

struct uv_mutex_s {
    void* handle;
};

typedef struct uv_mutex_s uv_mutex_t;

typedef struct {
    union {
        struct {
            HANDLE sem;
        } write_lock_;
        struct {
            void* cs;
        } read_lock_;
        struct {
            uv_mutex_t read_mutex_;
            uv_mutex_t write_mutex_;
        };
        int num_readers_;
    } fallback_;
} uv_rwlock_t;

int uv_translate_sys_error(int error);
int uv_mutex_init(uv_mutex_t* mutex);
void uv_mutex_destroy(uv_mutex_t* mutex);