#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

typedef struct _php_md5_ctx {
    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];
} PHP_MD5_CTX;

typedef struct _php_sha1_ctx {
    unsigned int state[5];
    unsigned int count[2];
    unsigned char buffer[64];
} PHP_SHA1_CTX;

#define PHPAPI
#define PS_CREATE_SID_ARGS int *newlen
#define PS_HASH_FUNC_MD5 0
#define PS_HASH_FUNC_SHA1 1
#define PS_HASH_FUNC_OTHER 2
#define HAVE_HASH_EXT
#define COMPILE_DL_HASH
#define PHP_WIN32
#define TSRMLS_C
#define TSRMLS_CC
#define SUCCESS 0
#define E_ERROR 1
#define E_WARNING 2
#define MIN(a,b) ((a)<(b)?(a):(b))
#define VCWD_OPEN open

typedef struct _zval {
    int type;
    char *strval;
    struct _HashTable *arrval;
} zval;

typedef struct _HashTable {
    int dummy;
} HashTable;

typedef struct _zend_executor_globals {
    HashTable symbol_table;
} zend_executor_globals;

extern zend_executor_globals EG;

typedef struct _ps_hash_ops {
    int context_size;
    int digest_size;
    void (*hash_init)(void *);
    void (*hash_update)(void *, unsigned char *, size_t);
    void (*hash_final)(unsigned char *, void *);
} ps_hash_ops;

typedef struct _ps_module {
    int hash_func;
    int entropy_length;
    char *entropy_file;
    int hash_bits_per_character;
    ps_hash_ops *hash_ops;
} ps_module;

extern ps_module PS;

void PHP_MD5Init(PHP_MD5_CTX *);
void PHP_MD5Update(PHP_MD5_CTX *, unsigned char *, size_t);
void PHP_MD5Final(unsigned char *, PHP_MD5_CTX *);
void PHP_SHA1Init(PHP_SHA1_CTX *);
void PHP_SHA1Update(PHP_SHA1_CTX *, unsigned char *, size_t);
void PHP_SHA1Final(unsigned char *, PHP_SHA1_CTX *);
char *spprintf(char **, size_t, const char *, ...);
void php_error_docref(const char *, int, const char *, ...);
void *emalloc(size_t);
void efree(void *);
double php_combined_lcg(void);
int php_win32_get_random_bytes(unsigned char *, size_t);
char *bin_to_readable(char *, int, char *, char);
int zend_hash_find(HashTable *, const char *, size_t, void **);
#define Z_TYPE_PP(ppzval) ((*ppzval)->type)
#define Z_STRVAL_PP(ppzval) ((*ppzval)->strval)
#define Z_ARRVAL_PP(ppzval) ((*ppzval)->arrval)
#define IS_ARRAY 7
#define IS_STRING 6

/* Fix macro issues */
#define EG(v) (EG.v)
#define PS(v) (PS.v)