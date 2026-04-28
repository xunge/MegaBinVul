#include <string.h>

typedef struct ftpbuf_t {
    char *syst;
    char *inbuf;
    int resp;
} ftpbuf_t;

extern int ftp_putcmd(ftpbuf_t *ftp, const char *cmd, const char *arg);
extern int ftp_getresp(ftpbuf_t *ftp);
extern char *estrdup(const char *s);