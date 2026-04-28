#include <string.h>
#include <stdlib.h>

typedef struct _zend_hash_table zend_hash_table;
#define TSRMLS_DC
#define TSRMLS_CC
#define SUHOSIN_G(v) (v)

extern zend_hash_table *cookie_plainlist;
extern zend_hash_table *cookie_cryptlist;
extern int cookie_checkraddr;

extern int php_url_decode(char *str, int len);
extern void normalize_varname(char *var);
extern int zend_hash_exists(zend_hash_table *ht, const char *arKey, unsigned int nKeyLength);
extern char *suhosin_decrypt_string(char *value, int value_len, char *name, int name_len, char *key, int *new_len, int checkraddr TSRMLS_DC);
extern char *php_url_encode(char const *s, int len, int *new_length);
extern char *estrndup(const char *s, size_t len);
extern void efree(void *ptr);