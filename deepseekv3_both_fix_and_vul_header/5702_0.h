#include <stdio.h>
#include <stdlib.h>

typedef enum {
    FTPTYPE_ASCII,
    FTPTYPE_IMAGE
} ftptype_t;

typedef struct ftpbuf {
    ftptype_t type;
    int resp;
} ftpbuf_t;

int ftp_putcmd(ftpbuf_t *ftp, const char *cmd, const char *arg);
int ftp_getresp(ftpbuf_t *ftp);