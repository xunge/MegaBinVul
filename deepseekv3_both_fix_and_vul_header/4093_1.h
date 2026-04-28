#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ISERIES_LINE_LENGTH 256
#define ISERIES_HDR_LINES_TO_CHECK 10
#define ISERIES_FORMAT_UNICODE 1
#define WTAP_ERR_SHORT_READ -1
#define FALSE 0
#define TRUE 1

typedef int gboolean;
typedef unsigned int guint;
typedef unsigned char guint8;
typedef char gchar;

typedef struct wtap {
    void *priv;
    FILE *fh;
} wtap;

typedef struct {
    gboolean have_date;
    int format;
    int month;
    int day;
    int year;
} iseries_t;

#define g_malloc malloc