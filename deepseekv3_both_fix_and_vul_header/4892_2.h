#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <time.h>

#define MK_CLIENT_BAD_REQUEST 400
#define MK_CLIENT_FORBIDDEN 403
#define MK_CLIENT_NOT_FOUND 404
#define MK_CLIENT_METHOD_NOT_ALLOWED 405
#define MK_CLIENT_REQUEST_TIMEOUT 408
#define MK_CLIENT_LENGTH_REQUIRED 411
#define MK_CLIENT_REQUEST_ENTITY_TOO_LARGE 413
#define MK_SERVER_INTERNAL_ERROR 500
#define MK_SERVER_NOT_IMPLEMENTED 501
#define MK_SERVER_HTTP_VERSION_UNSUP 505

#define MK_FALSE 0
#define SH_NOCGI 0
#define TCP_CORK_OFF 0
#define EXIT_ERROR -1
#define MK_HTTP_METHOD_HEAD 0

typedef struct mk_ptr_t {
    char *data;
    size_t len;
} mk_ptr_t;

struct mk_list {
    struct mk_list *next, *prev;
};

struct file_info {
    off_t size;
};

struct error_page {
    int status;
    char *real_path;
    struct mk_list _head;
};

struct host_conf {
    struct mk_list error_pages;
    char *host_signature;
};

struct session_headers {
    mk_ptr_t content_type;
    off_t content_length;
    off_t real_length;
    char *location;
    int cgi;
    int pconnections_left;
    time_t last_modified;
};

struct session_request {
    struct host_conf *host_conf;
    mk_ptr_t uri;
    int fd_file;
    int fd_is_fdt;
    off_t bytes_to_send;
    struct session_headers headers;
    struct file_info file_info;
    int method;
};

struct client_session {
    int socket;
};

struct config {
    int open_flags;
};

extern struct config *config;
extern void mk_header_set_http_status(struct session_request *sr, int status);
extern void mk_header_send(int socket, struct client_session *cs, struct session_request *sr);
extern int mk_http_send_file(struct client_session *cs, struct session_request *sr);
extern void mk_ptr_reset(mk_ptr_t *ptr);
extern void mk_ptr_free(mk_ptr_t *ptr);
extern void mk_ptr_set(mk_ptr_t *ptr, const char *str);
extern void mk_mem_free(void *ptr);
extern int mk_file_get_info(const char *path, struct file_info *finfo);
extern void mk_string_build(char **data, size_t *len, const char *format, ...);
extern mk_ptr_t *mk_request_set_default_page(const char *title, mk_ptr_t uri, char *signature);
extern int mk_socket_send(int socket, const char *buf, size_t len);
extern void mk_server_cork_flag(int socket, int flag);

#define mk_list_foreach(head, list) \
    for (head = (list)->next; head != (list); head = head->next)

#define mk_list_entry(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))