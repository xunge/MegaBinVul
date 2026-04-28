#include <stdbool.h>

typedef struct PktBuf PktBuf;
typedef struct PgSocket PgSocket;

struct SBuf {
    // Add necessary SBuf fields here
    // (implementation details not provided in original code)
};

struct PgSocket {
    const char *auth_user;
    struct {
        const char *auth_user;
    } *db;
    void *pool;
    bool wait_for_user_conn;
    bool wait_for_user;
    struct SBuf sbuf;
    PgSocket *link;
    int ready;
};

extern PktBuf *pktbuf_dynamic(int size);
extern void pktbuf_write_ExtQuery(PktBuf *buf, const char *query, int nargs, const char *username);
extern int pktbuf_send_immediate(PktBuf *buf, PgSocket *client);
extern void pktbuf_free(PktBuf *buf);
extern bool sbuf_pause(struct SBuf *sbuf);
extern void *get_pool(void *db, const char *auth_user);
extern bool find_server(PgSocket *client);
extern void release_server(PgSocket *link);
extern void disconnect_client(PgSocket *client, bool flag, const char *msg);
extern void disconnect_server(PgSocket *link, bool flag, const char *msg);
extern void slog_noise(PgSocket *client, const char *msg);

extern const char *cf_auth_query;