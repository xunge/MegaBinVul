#include <stdint.h>
#include <string.h>

typedef struct bs_list {
    // Add necessary bs_list fields here
    // (implementation details not provided in original code)
} bs_list;

typedef struct TCP_Secure_Connection {
    // Add necessary TCP_Secure_Connection fields here
    // (implementation details not provided in original code)
} TCP_Secure_Connection;

typedef enum {
    TCP_STATUS_NO_STATUS
} TCP_Connection_Status;

typedef struct {
    uint8_t *public_key;
    TCP_Connection_Status status;
} TCP_Accepted_Connection;

typedef struct TCP_Server {
    TCP_Accepted_Connection *accepted_connection_array;
    bs_list accepted_key_list;
    uint32_t size_accepted_connections;
    uint32_t num_accepted_connections;
} TCP_Server;

void crypto_memzero(void *data, size_t length);
int bs_list_remove(bs_list *list, const uint8_t *public_key, int index);
void realloc_connection(TCP_Server *tcp_server, size_t new_size);