#include <string.h>
#include <stddef.h>

typedef struct _phar_archive_data phar_archive_data;
typedef int zend_bool;
#define FAILURE -1
#define SUCCESS 0

struct _phar_archive_data {
    void *virtual_dirs;
};

void *zend_memrchr(const void *s, int c, size_t n);
int zend_hash_add_empty_element(void *ht, const char *arKey, unsigned int nKeyLength);
#define TSRMLS_DC