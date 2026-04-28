#include <stdio.h>
#include <errno.h>
#include <stdint.h>

typedef struct wtap {
    FILE *fh;
} wtap;

#define WTAP_ERR_CANT_READ 1
#define WTAP_ERR_SHORT_READ 2

typedef char gchar;
typedef uint32_t guint32;
typedef int64_t gint64;

extern int file_read(void *, size_t, FILE *);
extern int file_error(FILE *, gchar **);
extern int file_seek(FILE *, gint64, int, int *);
extern guint32 g_ntohl(guint32);