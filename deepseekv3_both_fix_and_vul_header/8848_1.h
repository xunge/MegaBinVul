#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define PROPOSAL_MAX 10
#define PROPOSAL_KEX_ALGS 0
#define PROPOSAL_ENC_ALGS_CTOS 1
#define PROPOSAL_ENC_ALGS_STOC 2
#define PROPOSAL_COMP_ALGS_CTOS 3
#define PROPOSAL_COMP_ALGS_STOC 4
#define PROPOSAL_MAC_ALGS_CTOS 5
#define PROPOSAL_MAC_ALGS_STOC 6
#define PROPOSAL_SERVER_HOST_KEY_ALGS 7
#define KEX_DEFAULT_PK_ALG ""
#define KEX_CLIENT ""
#define KEX_DH_GRP1_SHA1 0
#define KEX_DH_GRP14_SHA1 1
#define KEX_DH_GRP14_SHA256 2
#define KEX_DH_GRP16_SHA512 3
#define KEX_DH_GRP18_SHA512 4
#define KEX_DH_GEX_SHA1 5
#define KEX_DH_GEX_SHA256 6
#define KEX_ECDH_SHA2 7
#define KEX_C25519_SHA256 8
#define DISPATCH_BLOCK 0
#define SSH2_MSG_IGNORE 2

struct kex {
    int (*kex[10])(void);
    char *client_version_string;
    char *server_version_string;
    int (*verify_host_key)(void);
    void *my;
    unsigned char *session_id;
    size_t session_id_len;
    int done;
};

struct {
    char *kex_algorithms;
    char *ciphers;
    int compression;
    char *macs;
    char *hostkeyalgorithms;
    u_int32_t rekey_limit;
    time_t rekey_interval;
} options;

extern char *xxx_host;
extern struct sockaddr *xxx_hostaddr;
extern char *client_version_string;
extern char *server_version_string;
extern unsigned char *session_id2;
extern size_t session_id2_len;
extern struct {
    struct kex *kex;
} *active_state;

int kexdh_client(void);
int kexgex_client(void);
int kexecdh_client(void);
int kexc25519_client(void);
char *kex_names_cat(const char *, const char *);
char *compat_kex_proposal(const char *);
char *compat_cipher_proposal(const char *);
char *compat_pkalg_proposal(const char *);
char *order_hostkeyalgs(char *, struct sockaddr *, u_short);
char *xstrdup(const char *);
void packet_set_rekey_limits(u_int32_t, time_t);
int kex_setup(void *, char **);
int kex_assemble_names(const char *, char **);
int kex_prop2buf(void *, char **);
void dispatch_run(int, int *, void *);
void packet_start(int);
void packet_put_cstring(const char *);
void packet_send(void);
void packet_write_wait(void);
void fatal(const char *, ...);
char *ssh_err(int);
int verify_host_key_callback(void);