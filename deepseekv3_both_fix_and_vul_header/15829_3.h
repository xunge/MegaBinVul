#include <stdlib.h>
#include <pthread.h>

#define CRYPTO_LOCK 1
#define CRYPTO_UNLOCK 0

typedef int CRYPTO_lock_t;
unsigned int CRYPTO_num_locks(void);
void *(*CRYPTO_get_locking_callback(void))(int, int, const char *, int);
void CRYPTO_set_locking_callback(void (*func)(int, int, const char *, int));

static pthread_mutex_t *ossl_locks;

static void sslLockInit(void *lock) {
    pthread_mutex_init((pthread_mutex_t *)lock, NULL);
}

static void opensslDoLock(int mode, int n, const char *file, int line) {
    if (mode & CRYPTO_LOCK) {
        pthread_mutex_lock(&ossl_locks[n]);
    } else {
        pthread_mutex_unlock(&ossl_locks[n]);
    }
}