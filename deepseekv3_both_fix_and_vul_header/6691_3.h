#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct tr_session tr_session;
typedef struct tr_variant tr_variant;
typedef int tr_quark;

typedef struct tr_address {
    int type;
} tr_address;

typedef struct tr_rpc_server {
    tr_session* session;
    bool isEnabled;
    int64_t port;
    char* url;
    bool isWhitelistEnabled;
    bool isPasswordEnabled;
    tr_address bindAddress;
} tr_rpc_server;

enum {
    TR_KEY_rpc_enabled,
    TR_KEY_rpc_port,
    TR_KEY_rpc_url,
    TR_KEY_rpc_whitelist_enabled,
    TR_KEY_rpc_host_whitelist_enabled,
    TR_KEY_rpc_host_whitelist,
    TR_KEY_rpc_authentication_required,
    TR_KEY_rpc_whitelist,
    TR_KEY_rpc_username,
    TR_KEY_rpc_password,
    TR_KEY_rpc_bind_address
};

enum {
    TR_AF_INET,
    TR_AF_INET6
};

extern const tr_address tr_inaddr_any;
extern const char* MY_NAME;
extern void (*startServer)(void*);

#define tr_new0(type, count) ((type*)calloc((count), sizeof(type)))

char* tr_strdup(const char* str);
bool tr_variantDictFindBool(const tr_variant* dict, tr_quark key, bool* setme);
bool tr_variantDictFindInt(const tr_variant* dict, tr_quark key, int64_t* setme);
bool tr_variantDictFindStr(const tr_variant* dict, tr_quark key, const char** setme, size_t* len);
void missing_settings_key(tr_quark key);
void tr_rpcSetWhitelistEnabled(tr_rpc_server* server, bool enabled);
void tr_rpcSetHostWhitelistEnabled(tr_rpc_server* server, bool enabled);
void tr_rpcSetHostWhitelist(tr_rpc_server* server, const char* whitelist);
void tr_rpcSetPasswordEnabled(tr_rpc_server* server, bool enabled);
void tr_rpcSetWhitelist(tr_rpc_server* server, const char* whitelist);
void tr_rpcSetUsername(tr_rpc_server* server, const char* username);
void tr_rpcSetPassword(tr_rpc_server* server, const char* password);
bool tr_address_from_string(tr_address* addr, const char* str);
void tr_logAddNamedError(const char* name, const char* fmt, ...);
void tr_logAddNamedInfo(const char* name, const char* fmt, ...);
const char* tr_rpcGetBindAddress(const tr_rpc_server* server);
void tr_runInEventThread(tr_session* session, void (*func)(void*), void* arg);
const char* _(const char* msg);