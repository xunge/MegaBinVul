#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <errno.h>

#define SW_FALSE 0
#define SW_TRUE 1
#define SW_STRL(str) str, sizeof(str)-1
#define SW_HTTP_RFC1123_DATE_GMT "%a, %d %b %Y %H:%M:%S GMT"
#define SW_HTTP_RFC1123_DATE_UTC "%a, %d %b %Y %H:%M:%S UTC"
#define SW_HTTP_RFC850_DATE "%A, %d-%b-%y %H:%M:%S GMT"
#define SW_HTTP_ASCTIME_DATE "%a %b %e %H:%M:%S %Y"
#define SW_HTTP_SERVER_SOFTWARE "swoole"
#define SW_EVENT_TCP 1
#define SW_EVENT_SENDFILE 2
#define SW_EVENT_CLOSE 3

typedef struct {
    int fd;
    int type;
    size_t len;
} swDataHead;

typedef struct {
    swDataHead info;
    size_t length;
    void *data;
} swSendData;

typedef struct {
    off_t offset;
    size_t length;
} swSendFile_request;

typedef struct {
    char *str;
    size_t length;
} swString;

typedef struct {
    swString *buffer;
    size_t url_offset;
    size_t url_length;
    size_t header_length;
    int keep_alive;
} swHttpRequest;

typedef struct {
    int session_id;
    int fd;
    int tcp_nopush;
} swConnection;

typedef struct {
    time_t now;
} swGlobalStats;

typedef struct {
    char *document_root;
    size_t document_root_len;
    swGlobalStats *gs;
} swServer;

extern char *swoole_get_mime_type(const char *filename);
extern int swServer_master_send(swServer *serv, swSendData *resp);
extern int swSocket_tcp_nopush(int fd, int enable);
extern int sw_snprintf(char *str, size_t size, const char *format, ...);