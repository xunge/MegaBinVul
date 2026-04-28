#include <stddef.h>

#define FALSE 0

typedef struct {
    unsigned int watch_id;
    void *conn;
    void *ice_connection;
    unsigned int protocol_timeout;
} GsmXSMPClientPrivate;

typedef struct {
    GsmXSMPClientPrivate *priv;
} GsmXSMPClient;

unsigned int g_source_remove(unsigned int tag);
void SmsCleanUp(void *conn);
void IceSetShutdownNegotiation(void *ice_connection, int flag);
void IceCloseConnection(void *ice_connection);