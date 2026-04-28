#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

typedef struct _php_stream php_stream;

typedef enum {
    FTPTYPE_ASCII,
    FTPTYPE_IMAGE
} ftptype_t;

typedef struct _databuf_t {
    int fd;
    char *buf;
} databuf_t;

typedef struct _ftpbuf_t {
    databuf_t *data;
    int resp;
} ftpbuf_t;

#define TSRMLS_DC
#define TSRMLS_CC
#define FTP_BUFSIZE 4096
#define PHP_WIN32

int ftp_type(ftpbuf_t *ftp, ftptype_t type);
databuf_t *ftp_getdata(ftpbuf_t *ftp TSRMLS_DC);
int ftp_putcmd(ftpbuf_t *ftp, const char *cmd, const char *arg);
int ftp_getresp(ftpbuf_t *ftp);
databuf_t *data_accept(databuf_t *data, ftpbuf_t *ftp TSRMLS_DC);
ssize_t my_recv(ftpbuf_t *ftp, int fd, void *buf, size_t len);
int php_stream_write(php_stream *stream, const void *buf, size_t count);
int php_stream_putc(php_stream *stream, int c);
databuf_t *data_close(ftpbuf_t *ftp, databuf_t *data);