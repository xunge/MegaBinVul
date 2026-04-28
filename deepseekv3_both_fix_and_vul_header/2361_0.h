#include <stdlib.h>
#include <string.h>

#define C_OK 0
#define CLIENT_SLAVE (1<<0)
#define CLIENT_BLOCKED (1<<1)
#define CLIENT_CLOSE_AFTER_REPLY (1<<2)
#define CLIENT_CLOSE_ASAP (1<<3)
#define PROTO_REQ_INLINE 1
#define PROTO_REQ_MULTIBULK 2

typedef struct client {
    char *querybuf;
    int flags;
    int reqtype;
    int argc;
} client;

typedef struct {
    client *current_client;
} serverStruct;

extern serverStruct server;

int sdslen(const char *s);
int clientsArePaused(void);
int processInlineBuffer(client *c);
int processMultibulkBuffer(client *c);
void serverPanic(const char *msg);
void resetClient(client *c);
int processCommand(client *c);