#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

struct qb_log_callsite {
    const char *function;
    uint32_t lineno;
    uint32_t tags;
    uint8_t priority;
    const char *format;
};

struct qb_log_target {
    void *instance;
    size_t max_line_length;
    const char *filename;
};

struct qb_ringbuffer_s;

extern struct qb_log_target *qb_log_target_get(int32_t target);
extern void *qb_rb_chunk_alloc(void *instance, size_t size);
extern void qb_util_perror(int priority, const char *format, ...);
extern void *qb_rb_lastref_and_ret(struct qb_ringbuffer_s **instance);
extern void qb_rb_close(void *instance);
extern size_t qb_vsnprintf_serialize(char *str, size_t size, const char *format, va_list ap);
extern int qb_rb_chunk_commit(void *instance, size_t size);

#define QB_LOG_MAX_LEN 1024
#define LOG_ERR 3