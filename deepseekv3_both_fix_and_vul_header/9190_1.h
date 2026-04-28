#include <stdio.h>
#include <string.h>

#define ASCEND_MAGIC_STRINGS 4
#define ASCEND_DATE "Date:"

typedef long long gint64;
typedef unsigned int guint;
typedef char gchar;

typedef struct {
    const gchar *strptr;
    guint type;
} ascend_magic_t;

typedef struct {
    FILE *fh;
    struct {
        struct {
            struct {
                guint type;
            } ascend;
        } pseudo_header;
    } phdr;
} wtap;

extern ascend_magic_t ascend_magic[];

static int file_getc(FILE *fh);
static gint64 file_tell(FILE *fh);
static int file_error(FILE *fh, gchar **err_info);
static int file_seek(FILE *fh, gint64 offset, int whence, int *err);