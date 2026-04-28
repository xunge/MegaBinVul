#include <stdio.h>
#include <stdlib.h>

typedef struct _ftpbuf_t {
    int resp;
} ftpbuf_t;

extern int spprintf(char **str, size_t size, const char *format, ...);
extern void efree(void *ptr);
extern int ftp_putcmd(ftpbuf_t *ftp, const char *cmd, const char *arg);
extern int ftp_getresp(ftpbuf_t *ftp);