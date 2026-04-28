#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PROPOSAL_MAX 10
#define PROPOSAL_KEX_ALGS 0
#define PROPOSAL_ENC_ALGS_CTOS 1
#define PROPOSAL_ENC_ALGS_STOC 2
#define PROPOSAL_MAC_ALGS_CTOS 3
#define PROPOSAL_MAC_ALGS_STOC 4
#define PROPOSAL_COMP_ALGS_CTOS 5
#define PROPOSAL_COMP_ALGS_STOC 6
#define PROPOSAL_SERVER_HOST_KEY_ALGS 7

#define COMP_NONE 0
#define COMP_DELAYED 1

#define KEX_SERVER NULL
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
    int server;
    char *client_version_string;
    char *server_version_string;
    unsigned char *session_id;
    size_t session_id_len;
    void (*kex[10])(void);
    void *(*load_host_public_key)(int);
    void *(*load_host_private_key)(int);
    int (*host_key_index)(int);
    int (*sign)(void *, void *, void *, size_t, void *, size_t *);
    int done;
};

struct ssh {
    struct kex *kex;
};

extern struct ssh *active_state;
extern char *client_version_string;
extern char *server_version_string;
extern unsigned char *session_id2;
extern size_t session_id2_len;
extern struct {
    char *kex_algorithms;
    char *ciphers;
    char *macs;
    int compression;
    unsigned long rekey_limit;
    unsigned int rekey_interval;
} options;

void fatal(const char *, ...);
int packet_set_rekey_limits(unsigned long, time_t);
int kex_setup(struct ssh *, char **);
char *ssh_err(int);
char *compat_kex_proposal(char *);
char *compat_cipher_proposal(char *);
char *compat_pkalg_proposal(char *);
char *list_hostkey_types(void);
void *get_hostkey_public_by_type(int);
void *get_hostkey_private_by_type(int);
int get_hostkey_index(int);
int sshd_hostkey_sign(void *, void *, void *, size_t, void *, size_t *);
void dispatch_run(int, int *, struct ssh *);
void packet_start(int);
void packet_put_cstring(const char *);
void packet_send(void);
void packet_write_wait(void);
void debug(const char *, ...);

void kexc25519_server(void);
void kexdh_server(void);
void kexgex_server(void);
void kexecdh_server(void);