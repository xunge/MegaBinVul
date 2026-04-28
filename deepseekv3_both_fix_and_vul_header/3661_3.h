#include <string.h>
#include <sys/types.h>

struct plugin;

struct client_session {
    int socket;
};

typedef struct {
    char *data;
    size_t len;
} mk_ptr_t;

struct session_request {
    char *uri;
    char *uri_processed;
    char *host;
    void *headers_toc;
};

#define PLUGIN_TRACE(fmt, ...)
#define MK_CLIENT_FORBIDDEN 403
#define MK_PLUGIN_RET_CLOSE_CONX -1
#define MK_PLUGIN_RET_NOT_ME 0

struct mk_api_t {
    int (*header_set_http_status)(struct session_request *, int);
    mk_ptr_t (*header_get)(void *, const char *, size_t);
};

extern struct mk_api_t *mk_api;

int mk_security_check_url(char *uri);
int mk_security_check_hotlink(char *uri_processed, char *host, mk_ptr_t referer);