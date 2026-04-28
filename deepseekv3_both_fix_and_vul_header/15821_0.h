#include <stdlib.h>
#include <sys/time.h>

typedef struct redisAsyncContext {
    struct {
        struct timeval *timeout;
    } c;
} redisAsyncContext;

static void *hiredis_safe_calloc(size_t nmemb, size_t size) {
    void *ptr = calloc(nmemb, size);
    if (ptr == NULL) {
        abort();
    }
    return ptr;
}