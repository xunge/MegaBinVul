#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#ifdef HAVE_SYS_MMAN_H
#include <sys/mman.h>
#endif

typedef struct gerb_file {
    char *filename;
    void *data;
    size_t datalen;
    FILE *fd;
} gerb_file_t;

#define g_free free
#define GERB_FATAL_ERROR(msg, ...) fprintf(stderr, msg, ##__VA_ARGS__), exit(EXIT_FAILURE)