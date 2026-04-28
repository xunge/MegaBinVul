#include <stdlib.h>
#include <string.h>

typedef int ret_t;
#define ret_ok 0

typedef struct {
    char *buf;
    size_t len;
} cherokee_buffer_t;

#define CHEROKEE_BUF_INIT {NULL, 0}

typedef struct {
    char *server_token;
} cherokee_server_t;

typedef struct {
    cherokee_buffer_t request;
} cherokee_connection_t;

typedef struct {
    cherokee_server_t *server;
    cherokee_connection_t *conn;
} cherokee_handler_server_info_t;

#define HANDLER_SRV(h) ((h)->server)
#define HANDLER_CONN(h) ((h)->conn)

#define PAGE_HEADER ""
#define PAGE_FOOT ""
#define AJAX_JS ""

void cherokee_buffer_add_str(cherokee_buffer_t *buffer, const char *str);
void cherokee_version_add(cherokee_buffer_t *buffer, const char *server_token);
void cherokee_buffer_replace_string(cherokee_buffer_t *buffer, const char *search, size_t search_len, const char *replace, size_t replace_len);
void cherokee_buffer_mrproper(cherokee_buffer_t *buffer);