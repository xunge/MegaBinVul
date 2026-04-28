#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct _ftpbuf_t {
    int resp;
    struct _databuf_t *data;
} ftpbuf_t;

typedef struct _databuf_t {
    int fd;
    char *buf;
} databuf_t;

typedef struct _php_stream {
    int dummy;
} php_stream;

#define TSRMLS_DC
#define TSRMLS_CC
#define E_WARNING 2
#define FTPTYPE_ASCII 1
#define FTP_BUFSIZE 4096

static php_stream *php_stream_fopen_tmpfile(void) { return NULL; }
static void php_error_docref(void *ref, int type, const char *msg) {}
static int ftp_type(ftpbuf_t *ftp, int type) { return 0; }
static databuf_t *ftp_getdata(ftpbuf_t *ftp TSRMLS_DC) { return NULL; }
static int ftp_putcmd(ftpbuf_t *ftp, const char *cmd, const char *path) { return 0; }
static int ftp_getresp(ftpbuf_t *ftp) { return 0; }
static databuf_t *data_close(ftpbuf_t *ftp, databuf_t *data) { return NULL; }
static void php_stream_close(php_stream *stream) {}
static char **ecalloc(size_t nmemb, size_t size) { return NULL; }
static databuf_t *data_accept(databuf_t *data, ftpbuf_t *ftp TSRMLS_DC) { return NULL; }
static size_t my_recv(ftpbuf_t *ftp, int fd, char *buf, size_t size) { return 0; }
static void php_stream_write(php_stream *stream, const char *buf, size_t len) {}
static void php_stream_rewind(php_stream *stream) {}
static char **safe_emalloc(size_t nmemb, size_t size, size_t add) { return NULL; }
static int php_stream_getc(php_stream *stream) { return 0; }
static void efree(void *ptr) {}