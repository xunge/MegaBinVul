#include <stdbool.h>
#include <string.h>

#define FALSE false
#define TRUE true
#define NUM_ELEM(arr) (sizeof(arr)/sizeof(arr[0]))
#define SSH_CHANNEL_INVALID (-1)

enum {
    STATUS_DONT_SEND_USER_NAME = 1,
    STATUS_DONT_SEND_CREDENTIALS = 2
};

struct SSHState {
    void *outbuf;
    size_t outbuflen;
    void *precompress_outbuf;
    size_t precompress_outbuflen;
    void *postdecompress_inbuf;
    size_t postdecompress_inbuflen;
    void *payload;
    bool compressing;
    bool decompressing;
    unsigned int status_flags;
    size_t payload_datalen;
    char *hostname;
    char *server_ID;
    unsigned int receiver_sequence_number;
    unsigned int sender_sequence_number;
    void *packet_handlers[16]; // Assuming fixed size array
};

struct Settings {
    int ssh_protocol_version;
};

typedef struct {
    struct SSHState ssh_state;
    char ssh2_keys[64]; // Assuming fixed size array
    int userauth_success;
    int shell_id;
    int session_nego_status;
    struct Settings settings;
    int kex_status;
    bool ssh2_autologin;
    bool ask4passwd;
    int userauth_retry_count;
    void *decomp_buffer;
    void *authbanner_buffer;
    char *ssh2_authlist;
    bool tryed_ssh2_authlist;
    bool agentfwd_enable;
    bool use_subsystem;
    bool nosession;
    char *server_sig_algs;
    bool server_strict_kex;
} TInstVar;

typedef TInstVar *PTInstVar;

void buf_create(void **buf, size_t *len);