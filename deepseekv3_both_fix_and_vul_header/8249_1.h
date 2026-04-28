#include <stdlib.h>

typedef struct _zend_rsrc_list_entry {
    void *ptr;
    int type;
    int refcount;
} zend_rsrc_list_entry;

typedef struct _php_mcrypt {
    void *td;
} php_mcrypt;

#define TSRMLS_DC
#define efree free
#define mcrypt_generic_deinit(p) 
#define mcrypt_module_close(p)