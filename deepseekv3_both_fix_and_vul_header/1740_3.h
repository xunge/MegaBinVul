#include <string.h>

typedef enum signature_type {
    SIG_RSA,
    SIG_DSS,
    SIG_ECDSA,
    SIG_ED25519
} signature_type;

typedef enum signkey_type {
    KEY_RSA,
    KEY_DSS,
    KEY_ECDSA,
    KEY_ED25519
} signkey_type;

typedef struct buffer {
    unsigned char *data;
    size_t len;
} buffer;

typedef struct Session {
    buffer *writepayload;
    buffer *session_id;
} Session;

typedef struct CliOpts {
    char *username;
} CliOpts;

typedef struct CliSes {
    int is_trivial_auth;
} CliSes;

extern Session ses;
extern CliOpts cli_opts;
extern CliSes cli_ses;

typedef struct sign_key sign_key;

#define SSH_MSG_USERAUTH_REQUEST 50
#define SSH_SERVICE_CONNECTION "ssh-connection"
#define SSH_SERVICE_CONNECTION_LEN (sizeof("ssh-connection")-1)
#define AUTH_METHOD_PUBKEY "publickey"
#define AUTH_METHOD_PUBKEY_LEN (sizeof("publickey")-1)

#define TRACE(x)
#define CHECKCLEARTOWRITE()

signkey_type signkey_type_from_signature(signature_type sigtype);
const char* signature_name_from_type(signature_type sigtype, unsigned int *algolen);
void buf_putbyte(buffer *buf, unsigned char byte);
void buf_putstring(buffer *buf, const char *str, size_t len);
void buf_put_pub_key(buffer *buf, sign_key *key, signkey_type keytype);
buffer* buf_new(size_t size);
void buf_putbufstring(buffer *buf, buffer *src);
void buf_putbytes(buffer *buf, const unsigned char *data, size_t len);
void cli_buf_put_sign(buffer *buf, sign_key *key, signature_type sigtype, buffer *sigbuf);
void buf_free(buffer *buf);
void encrypt_packet(void);