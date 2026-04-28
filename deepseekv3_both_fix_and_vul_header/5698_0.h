#include <stdlib.h>

typedef struct _ftpbuf_t {
    int nb;
    int resp;
} ftpbuf_t;

int ftp_gc(ftpbuf_t *ftp);
int ftp_putcmd(ftpbuf_t *ftp, const char *cmd, const char *arg);
int ftp_getresp(ftpbuf_t *ftp);