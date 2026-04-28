#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *inbuf;
    int resp;
} ftpbuf_t;

char *estrdup(const char *s);

int ftp_putcmd(ftpbuf_t *ftp, const char *cmd, const char *arg);
int ftp_getresp(ftpbuf_t *ftp);