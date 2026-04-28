#include <stdint.h>

#define C_OK 0
#define C_ERR -1

typedef struct client client;
typedef struct {
    long long proto_max_bulk_len;
} server_t;

extern server_t server;

int mustObeyClient(client *c);
void addReplyError(client *c, const char *msg);