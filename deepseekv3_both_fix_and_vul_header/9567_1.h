#include <pthread.h>

typedef struct _TsHashTable TsHashTable;
typedef struct _zend_hash zend_hash;

struct _TsHashTable {
    zend_hash *hash;
    pthread_mutex_t mx_reader;
    pthread_mutex_t mx_writer;
};

#define TS_HASH(ht) ((ht)->hash)
#define ZEND_API
#define ZTS

void begin_write(TsHashTable *ht);
void end_write(TsHashTable *ht);
void zend_hash_graceful_destroy(zend_hash *ht);
void tsrm_mutex_free(pthread_mutex_t mutex);