#include <string.h>
#include <stdint.h>
#include <time.h>

typedef unsigned int php_uint32;

typedef struct ps_sd {
    php_uint32 hv;
    time_t ctime;
    void *data;
    size_t alloclen;
    size_t datalen;
    struct ps_sd *next;
    char key[1];
} ps_sd;

typedef struct ps_mm {
    void *mm;
    ps_sd **hash;
    php_uint32 hash_max;
    php_uint32 hash_cnt;
} ps_mm;

#define TSRMLS_FETCH()
#define TSRMLS_CC
#define E_WARNING 0

void php_error_docref(const char *docref, int type, const char *format, ...);
size_t mm_available(void *mm);
const char *mm_error();
void *mm_malloc(void *mm, size_t size);
void hash_split(ps_mm *data);
php_uint32 ps_sd_hash(const char *key, int keylen);
void ps_mm_debug(const char *format, ...);