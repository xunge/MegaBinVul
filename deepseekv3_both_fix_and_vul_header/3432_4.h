#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef char gchar;

typedef struct wtap {
    void *fh;
    int file_type;
    int file_encap;
    int tsprecision;
    int (*subtype_read)(void);
    int (*subtype_seek_read)(void);
    int snapshot_length;
    void *priv;
} wtap;

struct _mpeg_magic {
    const char *match;
    size_t len;
};

typedef struct {
    struct {
        int secs;
        int nsecs;
    } now;
    int t0;
} mpeg_t;

extern struct _mpeg_magic magic[];
extern int file_read(char *, size_t, void *);
extern int file_error(void *, gchar **);
extern int file_seek(void *, long, int, int *);
extern void *g_malloc(size_t);

#define WTAP_ERR_CANT_READ 1
#define WTAP_FILE_MPEG 1
#define WTAP_ENCAP_MPEG 1
#define WTAP_FILE_TSPREC_NSEC 1
#define SEEK_SET 0

extern int mpeg_read;
extern int mpeg_seek_read;