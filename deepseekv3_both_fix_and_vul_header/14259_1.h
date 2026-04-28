#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct TCP_Client_Connection TCP_Client_Connection;
typedef struct Priority_Queue Priority_Queue;

struct TCP_Client_Connection {
    int sock;
    Priority_Queue *priority_queue_start;
};

void wipe_priority_list(Priority_Queue *queue);
void kill_sock(int sock);
void crypto_memzero(void *ptr, size_t len);

#define nullptr NULL