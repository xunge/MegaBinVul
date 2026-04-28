#include <stdint.h>
#include <string.h>

#define TCP_STATUS_CONNECTED 1
#define TCP_STATUS_NO_STATUS 0
#define MAX_INCOMING_CONNECTIONS 256

typedef struct TCP_Secure_Connection {
    int status;
} TCP_Secure_Connection;

typedef struct TCP_Server {
    TCP_Secure_Connection incoming_connection_queue[MAX_INCOMING_CONNECTIONS];
    TCP_Secure_Connection unconfirmed_connection_queue[MAX_INCOMING_CONNECTIONS];
    uint32_t unconfirmed_connection_queue_index;
    uint8_t secret_key[32];
} TCP_Server;

int read_connection_handshake(TCP_Secure_Connection *conn, const uint8_t *secret_key);
void kill_TCP_secure_connection(TCP_Secure_Connection *conn);
void crypto_memzero(void *data, size_t length);