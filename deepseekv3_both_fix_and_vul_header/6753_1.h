#include <stdlib.h>

#define AUTH_REQUEST_STATUS_ABORT 0

struct auth_client_request;
struct auth_client_connection {
    void *client;
};
struct auth_client_request {
    struct auth_client_connection *conn;
    unsigned int id;
    void *pool;
};

void auth_client_send_cancel(void *client, unsigned int id);
void call_callback(struct auth_client_request *request, int status, void *arg1, void *arg2);
void pool_unref(void **pool);