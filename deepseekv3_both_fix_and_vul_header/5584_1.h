#include <stdlib.h>

struct zip_error;
struct zip_dirent {
    /* minimal definition to make sizeof work */
    int dummy;  
};

struct zip_cdir {
    struct zip_dirent *entry;
    int nentry;
    unsigned long size;
    unsigned long offset;
    char *comment;
    unsigned int comment_len;
};

void _zip_error_set(struct zip_error *, int, int);

#define ZIP_ER_MEMORY 0