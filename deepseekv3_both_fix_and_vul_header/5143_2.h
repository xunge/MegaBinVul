#include <string.h>
#include <stdint.h>

#define FAILURE 0
#define SUCCESS 1
#define HASH_KEY_NON_EXISTENT 0

typedef unsigned int uint;
typedef unsigned long ulong;

typedef struct _phar_archive_data phar_archive_data;
typedef struct _phar_globals phar_globals;

struct _phar_globals {
    void *phar_alias_map;
    void *phar_fname_map;
    int manifest_cached;
};

struct _phar_archive_data {
    int ext_len;
    int is_data;
};

extern phar_globals *PHAR_GLOBALS;
#define PHAR_G(v) (PHAR_GLOBALS->v)
extern void *cached_alias;
extern void *cached_phars;

void phar_request_initialize();
int phar_check_str(const char *, const char *, int, int, int);
int zend_hash_exists(void *, const char *, int);
int zend_hash_num_elements(void *);
int zend_hash_find(void *, const char *, int, void **);
void zend_hash_internal_pointer_reset(void *);
int zend_hash_get_current_key_ex(void *, char **, uint *, ulong *, int, void *);
void zend_hash_move_forward(void *);
int zend_hash_get_current_data(void *, void **);

#define TSRMLS_DC
#define TSRMLS_C
#define TSRMLS_CC