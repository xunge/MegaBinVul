#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {
    FTPTYPE_ASCII
} ftptype_t;

#define FTP_BUFSIZE 8192
#define TSRMLS_DC
#define TSRMLS_CC

struct _databuf_t {
    char *buf;
    int fd;
};

struct _ftpbuf_t {
    struct _databuf_t *data;
    int resp;
};

typedef struct _ftpbuf_t ftpbuf_t;
typedef struct _databuf_t databuf_t;
typedef struct _php_stream php_stream;

int php_stream_eof(php_stream *stream);
int php_stream_getc(php_stream *stream);
int ftp_type(ftpbuf_t *ftp, ftptype_t type);
databuf_t *ftp_getdata(ftpbuf_t *ftp TSRMLS_DC);
int ftp_putcmd(ftpbuf_t *ftp, const char *cmd, const char *arg);
int ftp_getresp(ftpbuf_t *ftp);
databuf_t *data_accept(databuf_t *data, ftpbuf_t *ftp TSRMLS_DC);
int my_send(ftpbuf_t *ftp, int fd, const char *buf, int size);
databuf_t *data_close(ftpbuf_t *ftp, databuf_t *data);