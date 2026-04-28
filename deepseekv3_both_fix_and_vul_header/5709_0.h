#include <string.h>

typedef struct _ftpbuf_t {
    char *pwd;
    char *inbuf;
    int resp;
} ftpbuf_t;

char* estrndup(const char *s, size_t n);
int ftp_putcmd(ftpbuf_t *ftp, const char *cmd, const char *arg);
int ftp_getresp(ftpbuf_t *ftp);