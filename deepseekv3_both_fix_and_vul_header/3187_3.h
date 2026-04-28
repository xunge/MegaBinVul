#include <stdint.h>
#include <string.h>

typedef int PRBool;
typedef int32_t SECStatus;
#define SECSuccess 0
#define SECFailure -1
#define PR_FALSE 0
#define SSL_ERROR_WRONG_CERTIFICATE 0
#define ssl_app_layer_protocol_xtn 0
#define ssl_next_proto_nego_xtn 0
#define SSL_ENABLE_FALSE_START 0

struct PRFileDesc;
struct CERTCertificate {
    struct {
        unsigned char* data;
        unsigned int len;
    } derCert;
};

class SSLClientSocketNSS {
public:
    struct Core {
        bool handshake_callback_called_;
        struct {
            CERTCertificate** server_cert_chain;
        } nss_handshake_state_;
        
        SECStatus OwnAuthCertHandler(void* arg, PRFileDesc* socket, 
                                   PRBool checksig, PRBool is_server);
    };
};

SECStatus SSL_HandshakeNegotiatedExtension(PRFileDesc*, int, PRBool*);
SECStatus SSL_OptionSet(PRFileDesc*, int, PRBool);
CERTCertificate* SSL_PeerCertificate(PRFileDesc*);
void PORT_SetError(int);