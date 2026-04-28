#include <stdlib.h>

typedef struct _zend_compiler_globals {
    int default_dir;
} zend_compiler_globals;

#define DIRG(v) (compiler_globals.v)

extern zend_compiler_globals compiler_globals;

void zend_list_delete(int id);
void zend_list_addref(int id);

#define TSRMLS_DC