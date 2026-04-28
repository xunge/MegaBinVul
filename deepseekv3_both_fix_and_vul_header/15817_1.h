#include <stdlib.h>
#include <pthread.h>

static pthread_mutex_t *ossl_locks;

typedef void (*CRYPTO_locking_cb)(int mode, int type, const char *file, int line);
typedef int (*CRYPTO_get_locking_cb)(void);
typedef int (*CRYPTO_num_locks_cb)(void);
typedef void (*CRYPTO_set_locking_cb)(CRYPTO_locking_cb);

extern CRYPTO_get_locking_cb CRYPTO_get_locking_callback;
extern CRYPTO_num_locks_cb CRYPTO_num_locks;
extern CRYPTO_set_locking_cb CRYPTO_set_locking_callback;
extern void *hiredis_safe_malloc(size_t size);
extern void sslLockInit(pthread_mutex_t *);
extern void opensslDoLock(int mode, int n, const char *file, int line);