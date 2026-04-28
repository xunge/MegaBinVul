#include <string.h>

#define MAXPATHLEN 4096

typedef struct _phar phar;
typedef struct _phar_entry_info phar_entry_info;

struct _phar {
    char *fname;
    size_t fname_len;
};

struct _phar_entry_info {
    char *filename;
    size_t filename_len;
    phar *phar;
    unsigned short inode;
};

#define TSRMLS_DC

unsigned int zend_get_hash_value(const char *str, size_t len);