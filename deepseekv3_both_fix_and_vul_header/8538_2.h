#include <stdio.h>
#include <stdbool.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0
#define AUTHENTICATIONERROR 1
#define TRANSPORT_LAYER_TSG 1

struct rdpSettings {
    BOOL Authentication;
    void* instance;
};

struct rdpTransport {
    int layer;
    struct rdpSettings* settings;
    void* credssp;
};

typedef struct freerdp freerdp;
typedef struct _CREDSSP CREDSSP;
typedef struct rdpTransport rdpTransport;
typedef struct rdpSettings rdpSettings;

extern int connectErrorCode;
extern CREDSSP* credssp_new(freerdp* instance, rdpTransport* transport, rdpSettings* settings);
extern int credssp_authenticate(CREDSSP* credssp);
extern void credssp_free(CREDSSP* credssp);
extern BOOL transport_connect_tls(rdpTransport* transport);