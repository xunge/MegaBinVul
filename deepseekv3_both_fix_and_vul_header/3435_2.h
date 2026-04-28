#include <stdio.h>
#include <stdint.h>

typedef struct wtap {
    FILE *fh;
} wtap;

typedef int64_t gint64;
typedef char gchar;
#define _U_ __attribute__((unused))

static int file_getc(FILE *fh);
static gint64 file_tell(FILE *fh);
static int file_seek(FILE *fh, gint64 offset, int whence, int *err);