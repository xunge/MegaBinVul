#include <stdlib.h>

typedef struct NBDClient NBDClient;
typedef struct NBDRequestData NBDRequestData;

void qemu_vfree(void *addr);
void g_free(void *ptr);
void nbd_update_can_read(NBDClient *client);
void nbd_client_put(NBDClient *client);

struct NBDRequestData {
    NBDClient *client;
    void *data;
};

struct NBDClient {
    int nb_requests;
};