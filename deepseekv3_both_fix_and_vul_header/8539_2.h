#include <stdio.h>
#include <stdbool.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

enum {
    TRANSPORT_LAYER_TLS
};

typedef struct _Tls {
    int sockfd;
    void* settings;
} Tls;

typedef struct _Tcp {
    int sockfd;
} Tcp;

typedef struct _Credssp {
    int dummy;
} Credssp;

typedef struct rdpSettings {
    char* CertificateFile;
    char* PrivateKeyFile;
    BOOL Authentication;
    void* instance;
} rdpSettings;

typedef struct freerdp {
    int dummy;
} freerdp;

typedef struct rdpTransport {
    Tls* TlsIn;
    Tls* TlsOut;
    Tcp* TcpIn;
    int layer;
    rdpSettings* settings;
    Credssp* credssp;
} rdpTransport;

Tls* tls_new(rdpSettings* settings);
int tls_accept(Tls* tls, char* cert, char* key);
Credssp* credssp_new(freerdp* instance, rdpTransport* transport, rdpSettings* settings);
int credssp_authenticate(Credssp* credssp);
void credssp_free(Credssp* credssp);