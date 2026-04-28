#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define TSRMLS_DC
#define TSRMLS_CC
#define E_WARNING 2
#define FTPTYPE_ASCII 1
#define FTP_BUFSIZE 4096

typedef struct _php_stream {
    int fd;
    // other stream fields
} php_stream;

typedef struct _databuf_t {
    int fd;
    char *buf;
    // other data buffer fields
} databuf_t;

typedef struct _ftpbuf_t {
    databuf_t *data;
    int resp;
    // other FTP buffer fields
} ftpbuf_t;

php_stream *php_stream_fopen_tmpfile(void);
void php_stream_close(php_stream *stream);
size_t php_stream_write(php_stream *stream, const char *buf, size_t count);
int php_stream_getc(php_stream *stream);
void php_stream_rewind(php_stream *stream);

void php_error_docref(const char *ref, int type, const char *format, ...);
int ftp_type(ftpbuf_t *ftp, int type);
databuf_t *ftp_getdata(ftpbuf_t *ftp TSRMLS_DC);
int ftp_putcmd(ftpbuf_t *ftp, const char *cmd, const char *path);
int ftp_getresp(ftpbuf_t *ftp);
databuf_t *data_close(ftpbuf_t *ftp, databuf_t *data);
void *ecalloc(size_t nmemb, size_t size);
databuf_t *data_accept(databuf_t *data, ftpbuf_t *ftp TSRMLS_DC);
int my_recv(ftpbuf_t *ftp, int fd, char *buf, int size);
void *safe_emalloc(size_t nmemb, size_t size, size_t offset);
void efree(void *ptr);