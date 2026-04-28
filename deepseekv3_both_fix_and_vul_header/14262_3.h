#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

#define MAX_INCOMING_CONNECTIONS 256
#define nullptr NULL

typedef struct Secure_Connection {
    // Add necessary fields here
} Secure_Connection;

typedef struct Onion {
    // Add necessary fields here
} Onion;

typedef struct bs_list {
    void *data;
    // Add other necessary fields
} bs_list;

typedef struct TCP_Server {
    uint32_t num_listening_socks;
    int *socks_listening;
    Onion *onion;
    bs_list accepted_key_list;
    int efd;
    Secure_Connection incoming_connection_queue[MAX_INCOMING_CONNECTIONS];
    Secure_Connection unconfirmed_connection_queue[MAX_INCOMING_CONNECTIONS];
    void *accepted_connection_array;
} TCP_Server;

void kill_sock(int sock);
void set_callback_handle_recv_1(Onion *onion, void *callback, void *object);
void bs_list_free(bs_list *list);
void wipe_secure_connection(Secure_Connection *conn);
void free_accepted_connection_array(TCP_Server *tcp_server);