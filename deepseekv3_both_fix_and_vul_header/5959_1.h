#include <string.h>
#include <stdlib.h>

typedef struct _zend_hash SUHOSIN_G_type;
extern SUHOSIN_G_type *suhosin_globals_cookie_plainlist;
extern SUHOSIN_G_type *suhosin_globals_cookie_cryptlist;
#define SUHOSIN_G(x) (suhosin_globals_##x)

#define TSRMLS_DC
#define TSRMLS_CC
#define estrndup strndup
#define efree free

int php_url_decode(char *str, int len);
void normalize_varname(char *var);
int zend_hash_exists(SUHOSIN_G_type *ht, char *arKey, unsigned int nKeyLength);
char *suhosin_encrypt_string(char *data, int data_len, char *key, int key_len, char *encrypt_key TSRMLS_DC);
char *php_url_encode(char const *s, int len, int *new_length);