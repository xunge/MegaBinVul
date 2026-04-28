#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <poll.h>

#define MAX_HEADER_LENGTH 8192
#define NO_MSG NULL
#define SSL_ERROR_WANT_READ 2
#define SSL_ERROR_WANT_WRITE 3

enum HttpState {
    SNIFFING_SSL,
    COMMAND,
    HEADERS,
    PAYLOAD,
    DISCARD_PAYLOAD,
    WEBSOCKET
};

struct ServerConnection;
struct HttpConnection;
struct Trie;
struct SSLConfig {
    int enabled;
    int force;
};

struct HttpConnection {
    struct ServerConnection *connection;
    struct Trie *server;
    struct SSLConfig *ssl;
    void *sslHndl;
    int lastError;
    int closed;
    int headerLength;
    int state;
    int partialLength;
    char *partial;
    int expecting;
    int isPartialReply;
    int isSuspended;
    char *msg;
    int msgLength;
    void (*callback)(void);
    void *arg;
};

struct ServerConnection {
    int timeout;
};

struct Trie {
    // Trie structure definition would go here
};

void debug(const char *msg);
int httpRead(struct HttpConnection *http, char *buf, int size);
void httpSendReply(struct HttpConnection *http, int code, const char *status, const char *msg);
void httpCloseRead(struct HttpConnection *http);
int httpGetChar(struct HttpConnection *http, char *buf, int bytes, int *offset);
int httpPromoteToSSL(struct HttpConnection *http, char *buf, int bytes);
int httpParseCommand(struct HttpConnection *http, int offset, char *buf, int bytes, int firstSpace, int lastSpace, int lineLength);
int httpParseHeaders(struct HttpConnection *http, struct Trie *handlers, int offset, char *buf, int bytes, int colon, int lineLength);
int httpParsePayload(struct HttpConnection *http, int offset, char *buf, int len);
int httpHandleWebSocket(struct HttpConnection *http, int offset, char *buf, int bytes);
void httpHandleCommand(struct HttpConnection *http, struct Trie *handlers);
void httpSetState(struct HttpConnection *http, int state);
void httpConsumePayload(struct HttpConnection *http, const char *data, int len);
int httpWrite(struct HttpConnection *http, const char *msg, int len);
struct ServerConnection *httpGetServerConnection(struct HttpConnection *http);
int serverGetTimeout(struct ServerConnection *connection);
void serverSetTimeout(struct ServerConnection *connection, int timeout);
struct Trie *serverGetHttpHandlers(struct Trie *server);
void sslFreeHndl(void **ssl);
int sslBlockSigPipe(void);
int sslUnblockSigPipe(void);
void dcheck(int condition);
int SSL_shutdown(void *ssl);
int SSL_get_error(void *ssl, int ret);
int ERR_peek_error(void);
void ERR_clear_error(void);