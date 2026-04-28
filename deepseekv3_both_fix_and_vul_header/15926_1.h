#include <pthread.h>

#define CRYPTO_LOCK 1
#define CRYPTO_UNLOCK 2
#define CRYPTO_READ 4
#define CRYPTO_WRITE 8

#define CHECK(condition) (void)(condition)

typedef struct {
    pthread_rwlock_t lock;
} uv_rwlock_t;

static uv_rwlock_t* locks;

void uv_rwlock_rdlock(uv_rwlock_t* lock);
void uv_rwlock_wrlock(uv_rwlock_t* lock);
void uv_rwlock_rdunlock(uv_rwlock_t* lock);
void uv_rwlock_wrunlock(uv_rwlock_t* lock);