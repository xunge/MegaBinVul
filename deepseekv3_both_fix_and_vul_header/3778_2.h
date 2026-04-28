#include <stdbool.h>
#include <string.h>

typedef enum {
    IDLE_INACTIVE,
    IDLE_ACTIVE
} IdleState;

typedef enum {
    IMHS_CONNECTED,
    IMHS_DISCONNECTED
} ImapHandleState;

typedef enum {
    NET_CLIENT_CRYPT_NONE,
    NET_CLIENT_CRYPT_ENCRYPTED
} NetClientCryptMode;

typedef enum {
    IMR_OK,
    IMR_NO,
    IMR_UNTAGGED,
    IMAP_SUCCESS,
    IMAP_CONNECT_FAILED,
    IMAP_UNSECURE,
    IMAP_PROTOCOL_ERROR
} ImapResult;

typedef ImapResult ImapResponse;

typedef enum {
    IMCAP_STARTTLS
} ImapCapability;

typedef struct {
    bool op_cancelled;
    bool has_capabilities;
    bool can_fetch_body;
    IdleState idle_state;
    void *sio;
    const char *host;
    NetClientCryptMode tls_mode;
    void (*auth_cb)(void);
    void *auth_arg;
    void (*cert_cb)(void);
    int timeout;
    ImapHandleState state;
    char *last_msg;
} ImapMboxHandle;

typedef struct {
    int dummy;
} GError;

#define FALSE false
#define TRUE true
#define _(x) x
#define error_safe(x) x
#define g_message(...)
#define g_clear_error(x)
#define g_object_unref(x)
#define g_signal_connect(a,b,c,d)
#define NET_CLIENT(x) x

void* net_client_siobuf_new(const char *host, int port);
bool net_client_connect(void *client, GError **error);
bool net_client_start_tls(void *client, GError **error);
void imap_mbox_handle_set_msg(ImapMboxHandle *handle, const char *fmt, ...);
ImapResult imap_cmd_step(ImapMboxHandle *handle, int flags);
void imap_handle_disconnect(ImapMboxHandle *handle);
bool imap_mbox_handle_can_do(ImapMboxHandle *handle, ImapCapability cap);
ImapResult imap_handle_starttls(ImapMboxHandle *handle, GError **error);