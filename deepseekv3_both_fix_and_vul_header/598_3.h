#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <sys/time.h>

#define SW_FALSE 0
#define SW_TRUE 1
#define SW_STRL(s) s, sizeof(s)-1
#define PATH_MAX 4096
#define SW_HTTP_RFC1123_DATE_GMT "%a, %d %b %Y %H:%M:%S GMT"
#define SW_HTTP_RFC1123_DATE_UTC "%a, %d %b %Y %H:%M:%S UTC"
#define SW_HTTP_RFC850_DATE "%A, %d-%b-%y %H:%M:%S GMT"
#define SW_HTTP_ASCTIME_DATE "%a %b %e %H:%M:%S %Y"
#define SW_HTTP_SERVER_SOFTWARE "swoole-http-server"
#define HAVE_TCP_NOPUSH 1

#define SW_EVENT_TCP 1
#define SW_EVENT_SENDFILE 2
#define SW_EVENT_CLOSE 3

typedef struct {
    char *str;
    size_t length;
} swString;

typedef struct {
    int fd;
    int session_id;
    int tcp_nopush;
} swConnection;

typedef struct {
    off_t offset;
    size_t length;
    char filename[PATH_MAX];
} swSendFile_request;

typedef struct {
    int fd;
    int type;
    size_t len;
} swSendInfo;

typedef struct {
    swSendInfo info;
    size_t length;
    void *data;
} swSendData;

typedef struct {
    swString *buffer;
    size_t url_offset;
    size_t url_length;
    size_t header_length;
    int keep_alive;
} swHttpRequest;

typedef struct swServer {
    char *document_root;
    size_t document_root_len;
    void (*master_send)(struct swServer *, swSendData *);
    time_t now;
    struct {
        time_t now;
    } *gs;
} swServer;

extern char *swoole_get_mime_type(const char *filename);
extern int swSocket_tcp_nopush(int fd, int on);
extern int sw_snprintf(char *str, size_t size, const char *format, ...);
extern void swServer_master_send(swServer *serv, swSendData *resp);
extern void swWarn(const char *fmt, ...);