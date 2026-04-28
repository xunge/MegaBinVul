#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef struct SBuf {
    // SBuf fields would be defined here
} SBuf;

typedef struct MBuf {
    // MBuf fields would be defined here
} MBuf;

typedef struct PgSocket {
    SBuf sbuf;
    bool wait_for_welcome;
    struct {
        struct {
            bool admin;
        } *db;
    } *pool;
    bool own_user;
    void *auth_user;
    uint8_t cancel_key[8];
    time_t request_time;
} PgSocket;

typedef struct PktHdr {
    int type;
    int len;
    MBuf data;
} PktHdr;

enum {
    PKT_SSLREQ,
    PKT_STARTUP_V2,
    PKT_STARTUP,
    PKT_CANCEL,
    BACKENDKEY_LEN = 8,
    AUTH_TRUST
};

extern int cf_auth_type;

bool incomplete_pkt(PktHdr *pkt);
void disconnect_client(PgSocket *client, bool flag, const char *msg);
bool finish_client_login(PgSocket *client);
void sbuf_prepare_skip(SBuf *sbuf, int len);
bool sbuf_answer(SBuf *sbuf, const char *data, int len);
bool decide_startup_pool(PgSocket *client, PktHdr *pkt);
bool admin_pre_login(PgSocket *client);
bool send_client_authreq(PgSocket *client);
bool mbuf_get_string(MBuf *mbuf, const char **str);
bool check_client_passwd(PgSocket *client, const char *passwd);
bool mbuf_avail_for_read(MBuf *mbuf);
bool mbuf_get_bytes(MBuf *mbuf, int len, const uint8_t **bytes);
void accept_cancel_request(PgSocket *client);
time_t get_cached_time(void);
void slog_noise(PgSocket *client, const char *msg);