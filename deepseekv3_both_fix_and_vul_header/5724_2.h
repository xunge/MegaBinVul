#include <stdlib.h>

#define TSRMLS_DC
#define DIRG(v) (default_dir_globals.v)

typedef struct _default_dir_globals {
    int default_dir;
} default_dir_globals_t;

extern default_dir_globals_t default_dir_globals;

void zend_list_delete(int id);
void zend_list_addref(int id);