#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SSH_TUNID_ANY (-1)
#define SSH_ESCAPECHAR_NONE (-2)
#define VIS_WHITE 0x04

enum {
    oUser,
    oHostname,
    oPort,
    oAddressFamily,
    oBatchMode,
    oCanonicalizeFallbackLocal,
    oCanonicalizeHostname,
    oChallengeResponseAuthentication,
    oCheckHostIP,
    oCompression,
    oControlMaster,
    oEnableSSHKeysign,
    oClearAllForwardings,
    oExitOnForwardFailure,
    oFingerprintHash,
    oForwardX11,
    oForwardX11Trusted,
    oGatewayPorts,
    oGssAuthentication,
    oGssDelegateCreds,
    oHashKnownHosts,
    oHostbasedAuthentication,
    oDisableTrivialAuth,
    oIdentitiesOnly,
    oKbdInteractiveAuthentication,
    oNoHostAuthenticationForLocalhost,
    oPasswordAuthentication,
    oPermitLocalCommand,
    oProxyUseFdpass,
    oPubkeyAuthentication,
    oRequestTTY,
    oStreamLocalBindUnlink,
    oStrictHostKeyChecking,
    oTCPKeepAlive,
    oTunnel,
    oVerifyHostKeyDNS,
    oVisualHostKey,
    oUpdateHostkeys,
    oCanonicalizeMaxDots,
    oConnectionAttempts,
    oForwardX11Timeout,
    oNumberOfPasswordPrompts,
    oServerAliveCountMax,
    oServerAliveInterval,
    oBindAddress,
    oBindInterface,
    oCiphers,
    oControlPath,
    oHostKeyAlgorithms,
    oHostKeyAlias,
    oHostbasedAcceptedAlgorithms,
    oIdentityAgent,
    oIgnoreUnknown,
    oKbdInteractiveDevices,
    oKexAlgorithms,
    oCASignatureAlgorithms,
    oLocalCommand,
    oRemoteCommand,
    oLogLevel,
    oMacs,
    oPKCS11Provider,
    oSecurityKeyProvider,
    oPreferredAuthentications,
    oPubkeyAcceptedAlgorithms,
    oRevokedHostKeys,
    oXAuthLocation,
    oKnownHostsCommand,
    oDynamicForward,
    oLocalForward,
    oRemoteForward,
    oIdentityFile,
    oCanonicalDomains,
    oCertificateFile,
    oGlobalKnownHostsFile,
    oUserKnownHostsFile,
    oSendEnv,
    oSetEnv,
    oLogVerbose,
    oPermitRemoteOpen,
    oAddKeysToAgent,
    oForwardAgent,
    oConnectTimeout,
    oTunnelDevice,
    oCanonicalizePermittedCNAMEs,
    oControlPersist,
    oEscapeChar,
    oIPQoS,
    oRekeyLimit,
    oStreamLocalBindMask,
    oLogFacility,
    oProxyCommand,
    oProxyJump
};

typedef struct {
    char *source_list;
    char *target_list;
} PermittedCNAME;

typedef struct {
    int gateway_ports;
    int streamlocal_bind_unlink;
    mode_t streamlocal_bind_mask;
} ForwardOptions;

typedef struct {
    char *hostkeyalgorithms;
    char *user;
    int port;
    int address_family;
    int batch_mode;
    int canonicalize_fallback_local;
    int canonicalize_hostname;
    int challenge_response_authentication;
    int check_host_ip;
    int compression;
    int control_master;
    int enable_ssh_keysign;
    int clear_forwardings;
    int exit_on_forward_failure;
    int fingerprint_hash;
    int forward_x11;
    int forward_x11_trusted;
    ForwardOptions fwd_opts;
    int gss_authentication;
    int gss_deleg_creds;
    int hash_known_hosts;
    int hostbased_authentication;
    int disable_trivial_auth;
    int identities_only;
    int kbd_interactive_authentication;
    int no_host_authentication_for_localhost;
    int password_authentication;
    int permit_local_command;
    int proxy_use_fdpass;
    int pubkey_authentication;
    int request_tty;
    int strict_host_key_checking;
    int tcp_keep_alive;
    int tun_open;
    int verify_host_key_dns;
    int visual_host_key;
    int update_hostkeys;
    int canonicalize_max_dots;
    int connection_attempts;
    int forward_x11_timeout;
    int number_of_password_prompts;
    int server_alive_count_max;
    int server_alive_interval;
    char *bind_address;
    char *bind_interface;
    char *ciphers;
    char *control_path;
    char *host_key_alias;
    char *hostbased_accepted_algos;
    char *identity_agent;
    char *ignored_unknown;
    char *kbd_interactive_devices;
    char *kex_algorithms;
    char *ca_sign_algorithms;
    char *local_command;
    char *remote_command;
    int log_level;
    char *macs;
    char *pkcs11_provider;
    char *sk_provider;
    char *preferred_authentications;
    char *pubkey_accepted_algos;
    char *revoked_host_keys;
    char *xauth_location;
    char *known_hosts_command;
    int num_local_forwards;
    void *local_forwards;
    int num_remote_forwards;
    void *remote_forwards;
    int num_identity_files;
    char **identity_files;
    int num_canonical_domains;
    char **canonical_domains;
    int num_certificate_files;
    char **certificate_files;
    int num_system_hostfiles;
    char **system_hostfiles;
    int num_user_hostfiles;
    char **user_hostfiles;
    int num_send_env;
    char **send_env;
    int num_setenv;
    char **setenv;
    int num_log_verbose;
    char **log_verbose;
    int num_permitted_remote_opens;
    char **permitted_remote_opens;
    int add_keys_to_agent;
    int add_keys_to_agent_lifespan;
    int forward_agent;
    char *forward_agent_sock_path;
    int connection_timeout;
    int tun_local;
    int tun_remote;
    int num_permitted_cnames;
    PermittedCNAME *permitted_cnames;
    int control_persist;
    int control_persist_timeout;
    int escape_char;
    int ip_qos_interactive;
    int ip_qos_bulk;
    unsigned long long rekey_limit;
    int rekey_interval;
    int log_facility;
    char *proxy_command;
    char *jump_host;
    int jump_port;
    char *jump_user;
    char *jump_extra;
} Options;

char *sshkey_alg_list(int a, int b, int c, char d);
int kex_assemble_names(char **algs, const char *def, const char *all);
const char *kex_default_pk_alg(void);
void fatal_fr(int r, const char *msg);
void dump_cfg_string(int opt, const char *val);
void dump_cfg_int(int opt, int val);
void dump_cfg_fmtint(int opt, int val);
void dump_cfg_forwards(int opt, int num, void *fwd);
void dump_cfg_strarray(int opt, int num, char **array);
void dump_cfg_strarray_oneline(int opt, int num, char **array);
const char *lookup_opcode_name(int opt);
const char *log_level_name(int level);
const char *log_facility_name(int facility);
const char *iptos2str(int iptos);
char *vis(char *dst, int c, int flag, int nextc);