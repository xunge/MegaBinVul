#include <string.h>

#define FTP_BUFSIZE 1024

typedef struct ftpbuf_t {
    char outbuf[FTP_BUFSIZE];
    char *extra;
    int fd;
} ftpbuf_t;

int slprintf(char *str, size_t size, const char *format, ...);
int my_send(ftpbuf_t *ftp, int fd, const char *data, int size);