#include <stdint.h>
#include <string.h>

typedef unsigned int zend_uint;
typedef struct _zval_struct zval;
typedef struct _HashTable HashTable;

#define PHPAPI
#define TSRMLS_FETCH()
#define Z_OBJPROP_P(obj) ((HashTable*)0)
#define Z_TYPE_PP(ppzval) (0)
#define Z_STRVAL_PP(ppzval) (0)
#define Z_STRLEN_PP(ppzval) (0)
#define SUCCESS (0)
#define IS_STRING (0)
#define MAGIC_MEMBER ""

int zend_hash_find(HashTable *ht, const char *arKey, unsigned int nKeyLength, void **pData);
char *estrndup(const char *s, size_t length);