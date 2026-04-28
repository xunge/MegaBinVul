#include <string.h>
#include <stdlib.h>

struct connection {
    char *request;
    char *method;
    char *authorization;
    int state;
    int header_only;
};

extern int num_requests;
extern char *auth_key;
extern int auth_enabled;

int parse_request(struct connection *conn);
void default_reply(struct connection *conn, int code, const char *status, const char *msg);
int is_https_redirect(struct connection *conn);
void redirect_https(struct connection *conn);
void process_get(struct connection *conn);

#define SEND_HEADER 0