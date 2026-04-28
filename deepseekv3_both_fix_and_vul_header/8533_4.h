#include <stdio.h>
#include <stdbool.h>

typedef struct rdpTransport rdpTransport;
typedef struct wStream wStream;
typedef struct rdpSettings {
    bool DisableEncryption;
} rdpSettings;
typedef struct rdpNego rdpNego;
typedef struct rdpCredssp rdpCredssp;
typedef struct rdpTransportCreds rdpTransportCreds;

typedef struct rdpIdentity {
    char* Username;
    char* Domain;
    char* Password;
} rdpIdentity;

typedef struct freerdp_peer {
    struct {
        struct rdpRdp* rdp;
    }* context;
    rdpIdentity identity;
    bool authenticated;
    int (*Logon)(struct freerdp_peer*, struct rdpIdentity*, bool);
    void (*Capabilities)(struct freerdp_peer*);
} freerdp_peer;

typedef struct rdpRdp {
    int state;
    rdpSettings* settings;
    struct {
        unsigned int selected_protocol;
        rdpTransport* transport;
    }* nego;
} rdpRdp;

typedef struct rdpTransport {
    rdpCredssp* credssp;
} rdpTransport;

typedef struct rdpCredssp {
    rdpIdentity identity;
} rdpCredssp;

enum {
    CONNECTION_STATE_INITIAL,
    CONNECTION_STATE_NEGO,
    CONNECTION_STATE_MCS_CONNECT,
    CONNECTION_STATE_MCS_ERECT_DOMAIN,
    CONNECTION_STATE_MCS_ATTACH_USER,
    CONNECTION_STATE_MCS_CHANNEL_JOIN,
    CONNECTION_STATE_ESTABLISH_KEYS,
    CONNECTION_STATE_LICENSE,
    CONNECTION_STATE_ACTIVE
};

#define PROTOCOL_NLA 0x00000001
#define TRUE true
#define FALSE false

#define IFCALLRET(_callback, _ret, ...) \
    do { \
        if (_callback) { \
            _ret = _callback(__VA_ARGS__); \
        } \
    } while (0)

#define IFCALL(_callback, ...) \
    do { \
        if (_callback) \
            _callback(__VA_ARGS__); \
    } while (0)