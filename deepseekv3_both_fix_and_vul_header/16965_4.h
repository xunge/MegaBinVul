#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#ifdef HAVE_SYS_MMAN_H
#include <sys/mman.h>
#endif

typedef struct gerb_file {
    FILE *fd;
    int fileno;
    int ptr;
    int datalen;
    char *data;
    char *filename;
} gerb_file_t;

extern void *g_new(size_t size);
extern void g_free(void *ptr);
extern FILE *g_fopen(const char *filename, const char *mode);
extern char *g_strdup(const char *str);

#define dprintf(...) fprintf(stderr, __VA_ARGS__)
#define g_new(type, count) ((type*)malloc(sizeof(type)*(count)))