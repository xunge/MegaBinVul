#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define TSRMLS_DC
#define PHP_FTP_MOREDATA   1
#define PHP_FTP_FINISHED   2
#define PHP_FTP_FAILED     3
#define FTPTYPE_ASCII      1
#define FTP_BUFSIZE        4096

typedef struct _ftpbuf_t {
    int type;
    int nb;
    int resp;
    void *stream;
    struct ftp_data_t *data;
} ftpbuf_t;

typedef struct ftp_data_t {
    int fd;
    char *buf;
} ftp_data_t;

int data_writeable(ftpbuf_t *ftp, int fd);
int my_send(ftpbuf_t *ftp, int fd, char *buf, int size);
struct ftp_data_t* data_close(ftpbuf_t *ftp, struct ftp_data_t *data);
int ftp_getresp(ftpbuf_t *ftp);