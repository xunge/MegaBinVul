#include <assert.h>
#include <stdlib.h>

#define MAX_NBD_REQUESTS 100

typedef struct NBDClient {
    unsigned int nb_requests;
} NBDClient;

typedef struct NBDRequestData {
    NBDClient *client;
} NBDRequestData;

#define g_new0(type, count) ((type*)calloc(count, sizeof(type)))
void nbd_client_get(NBDClient *client);
void nbd_update_can_read(NBDClient *client);