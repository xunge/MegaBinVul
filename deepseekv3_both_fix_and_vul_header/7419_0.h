#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

#define _PATH_XAUTH "/usr/bin/xauth"
#define _PATH_SSH_CLIENT_ID_RSA ".ssh/id_rsa"
#define _PATH_SSH_CLIENT_ID_DSA ".ssh/id_dsa"
#define _PATH_SSH_CLIENT_ID_ECDSA ".ssh/id_ecdsa"
#define _PATH_SSH_CLIENT_ID_ECDSA_SK ".ssh/id_ecdsa_sk"
#define _PATH_SSH_CLIENT_ID_ED25519 ".ssh/id_ed25519"
#define _PATH_SSH_CLIENT_ID_ED25519_SK ".ssh/id_ed25519_sk"
#define _PATH_SSH_CLIENT_ID_XMSS ".ssh/id_xmss"
#define _PATH_SSH_SYSTEM_HOSTFILE "/etc/ssh/ssh_known_hosts"
#define _PATH_SSH_SYSTEM_HOSTFILE2 "/etc/ssh/ssh_known_hosts2"
#define _PATH_SSH_USER_HOSTFILE ".ssh/known_hosts"
#define _PATH_SSH_USER_HOSTFILE2 ".ssh/known_hosts2"

#define SSH_STRICT_HOSTKEY_ASK 1
#define SSH_UPDATE_HOSTKEYS_YES 1
#define SSH_UPDATE_HOSTKEYS_NO 0
#define SSH_TUNMODE_NO 0
#define SSH_TUNID_ANY 0
#define SSH_CANONICALISE_NO 0
#define SSH_FP_HASH_DEFAULT 0

#define SYSLOG_LEVEL_NOT_SET -1
#define SYSLOG_LEVEL_INFO 6
#define SYSLOG_FACILITY_NOT_SET -1
#define SYSLOG_FACILITY_USER 1

#define IPTOS_DSCP_AF21 0x48
#define IPTOS_DSCP_CS1 0x08

#define REQUEST_TTY_AUTO 2

#define KEX_CLIENT_ENCRYPT ""
#define KEX_CLIENT_MAC ""
#define KEX_CLIENT_KEX ""
#define KEX_DEFAULT_PK_ALG ""
#define SSH_ALLOWED_CA_SIGALGS ""

typedef struct {
    int forward_agent;
    int forward_x11;
    int forward_x11_trusted;
    int forward_x11_timeout;
    int exit_on_forward_failure;
    int clear_forwardings;
    char *stdio_forward_host;
    char *xauth_location;
    struct {
        int gateway_ports;
        mode_t streamlocal_bind_mask;
        int streamlocal_bind_unlink;
    } fwd_opts;
    int pubkey_authentication;
    int challenge_response_authentication;
    int gss_authentication;
    int gss_deleg_creds;
    int password_authentication;
    int kbd_interactive_authentication;
    int hostbased_authentication;
    int disable_trivial_auth;
    int batch_mode;
    int check_host_ip;
    int strict_host_key_checking;
    int compression;
    int tcp_keep_alive;
    int port;
    int address_family;
    int connection_attempts;
    int number_of_password_prompts;
    int add_keys_to_agent;
    int add_keys_to_agent_lifespan;
    int num_identity_files;
    int escape_char;
    int num_system_hostfiles;
    char *system_hostfiles[2];
    int update_hostkeys;
    int verify_host_key_dns;
    int num_user_hostfiles;
    char *user_hostfiles[2];
    int log_level;
    int log_facility;
    int no_host_authentication_for_localhost;
    int identities_only;
    int enable_ssh_keysign;
    int rekey_limit;
    int rekey_interval;
    int server_alive_interval;
    int server_alive_count_max;
    int control_master;
    int control_persist;
    int control_persist_timeout;
    int hash_known_hosts;
    int tun_open;
    int tun_local;
    int tun_remote;
    int permit_local_command;
    int visual_host_key;
    int ip_qos_interactive;
    int ip_qos_bulk;
    int request_tty;
    int proxy_use_fdpass;
    int canonicalize_max_dots;
    int canonicalize_fallback_local;
    int canonicalize_hostname;
    int fingerprint_hash;
    char *sk_provider;
    char *ciphers;
    char *macs;
    char *kex_algorithms;
    char *hostbased_accepted_algos;
    char *pubkey_accepted_algos;
    char *ca_sign_algorithms;
    char *local_command;
    char *remote_command;
    char *proxy_command;
    char *control_path;
    char *revoked_host_keys;
    char *pkcs11_provider;
    char *known_hosts_command;
    char *jump_host;
    int jump_port;
    char *jump_user;
} Options;

char *xstrdup(const char *);
void clear_forwardings(Options *);
void add_identity_file(Options *, const char *, const char *, int);
char *cipher_alg_list(char, int);
char *mac_alg_list(char);
char *kex_alg_list(char);
char *sshkey_alg_list(int, int, int, char);
char *match_filter_allowlist(const char *, const char *);
int kex_assemble_names(char **, const char *, const char *);
int option_clear_or_none(const char *);