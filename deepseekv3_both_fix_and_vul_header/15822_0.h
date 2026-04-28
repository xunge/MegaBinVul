#include <stdlib.h>
#include <string.h>

typedef struct redisCallback {
    // 定义redisCallback结构体的成员
    // 根据实际需要补充具体成员
} redisCallback;

static void *hiredis_safe_malloc(size_t size) {
    return malloc(size);
}