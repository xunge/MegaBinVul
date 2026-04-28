#include <stdio.h>
#include <stdlib.h>

typedef enum { FTPTYPE_ASCII, FTPTYPE_BINARY } ftptype_t;

typedef struct _php_stream {
    // 基本php_stream结构占位
} php_stream;

typedef struct _databuf_t {
    // 基本databuf_t结构占位
    int dummy;
} databuf_t;

typedef struct _ftpbuf_t {
    databuf_t *data;
    php_stream *stream;
    int lastch;
    int nb;
    int resp;
    // 其他必要字段
} ftpbuf_t;

#define TSRMLS_DC
#define TSRMLS_CC 
#define PHP_FTP_FAILED 0

// 函数声明
int ftp_type(ftpbuf_t *ftp, ftptype_t type);
databuf_t *ftp_getdata(ftpbuf_t *ftp TSRMLS_DC);
int ftp_putcmd(ftpbuf_t *ftp, const char *cmd, const char *arg);
int ftp_getresp(ftpbuf_t *ftp);
databuf_t *data_accept(databuf_t *data, ftpbuf_t *ftp TSRMLS_DC);
int ftp_nb_continue_write(ftpbuf_t *ftp TSRMLS_DC);
databuf_t *data_close(ftpbuf_t *ftp, databuf_t *data);