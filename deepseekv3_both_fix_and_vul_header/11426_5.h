#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

typedef long long ink_hrtime;

enum {
    SSL_HOOKS_INIT,
    SSL_HOOKS_INVOKE,
    SSL_HOOKS_ACTIVE,
    SSL_HOOKS_DONE
};

enum {
    HANDSHAKE_HOOKS_PRE,
    HANDSHAKE_HOOKS_DONE
};

enum {
    SSL_HOOK_OP_TUNNEL,
    SSL_HOOK_OP_TERMINATE
};

enum {
    SSL_WAIT_FOR_HOOK,
    SSL_HANDSHAKE_WANT_READ,
    SSL_HANDSHAKE_WANT_WRITE,
    SSL_HANDSHAKE_WANT_CONNECT,
    SSL_ERROR_WANT_ACCEPT,
    EVENT_DONE,
    EVENT_ERROR,
    EVENT_CONT,
    SSL_ERROR_NONE,
    SSL_ERROR_WANT_CONNECT,
    SSL_ERROR_WANT_WRITE,
    SSL_ERROR_WANT_READ,
    SSL_ERROR_SSL,
    SSL_ERROR_ZERO_RETURN,
    SSL_ERROR_SYSCALL
};

typedef int ssl_error_t;

struct BIO;
struct SSL;
struct X509;
struct X509_NAME;

struct ContWrapper {
    static void wrap(void*, void*, int, void*);
};

struct HttpProxyPort {
    enum TransportType {
        TRANSPORT_BLIND_TUNNEL
    };
};

struct Hook {
    Hook* next();
    void* m_cont;
    Hook* get(int);
};

struct NetHandler {
    struct Mutex {
        void* get();
    };
    Mutex mutex;
};

struct IOBufferReader {
    bool is_read_avail_more_than(int);
    void consume(int);
    char* start();
    char* end();
    char* buf();
};

struct NPNSet {
    void* findEndpoint(const unsigned char*, unsigned);
};

class SSLNetVConnection {
public:
    int sslServerHandShakeEvent(int &err);
    
private:
    int sslPreAcceptHookState;
    int sslHandshakeHookState;
    int hookOpRequested;
    bool sslHandShakeComplete;
    SSL* ssl;
    IOBufferReader* handShakeReader;
    IOBufferReader* handShakeBuffer;
    NPNSet* npnSet;
    void* npnEndpoint;
    int handShakeBioStored;
    int attributes;
    ink_hrtime sslHandshakeBeginTime;
    NetHandler* nh;
    Hook* curHook;
    Hook* ssl_hooks;

    bool getTransparentPassThrough();
    bool getSSLTrace();
    int read_raw_data();
    void update_rbio(bool);
    void debug_certificate_name(const char*, X509_NAME*);
    void TraceIn(bool, void*, int, const char*, ...);
    void SSLDebugVC(const char*, ...);
};

struct Thread {
    static ink_hrtime get_hrtime();
};

#define SSL_free(x)
#define BIO_eof(x) 0
#define SSL_get_rbio(x) nullptr
#define SSLAccept(x) 0
#define SSL_get_peer_certificate(x) nullptr
#define X509_get_subject_name(x) nullptr
#define X509_get_issuer_name(x) nullptr
#define X509_free(x)
#define SSL_INCREMENT_DYN_STAT(x)
#define SSL_INCREMENT_DYN_STAT_EX(x, y)
#define SSL_CLR_ERR_INCR_DYN_STAT(x, y, ...)
#define Debug(tag, ...)
#define Error(...)
#define SSLDebugVC(...)
#define TraceIn(...)
#define is_debug_tag_set(x) false
#define ink_assert(x)
#define PRId64 "lld"
#define BIO_new_mem_buf(x, y) nullptr
#define BIO_set_mem_eof_return(x, y)
#define SSL_set0_rbio(x, y)
#define TS_VCONN_PRE_ACCEPT_INTERNAL_HOOK 0
#define TS_EVENT_VCONN_PRE_ACCEPT 0
#define SSL_OP_HANDSHAKE 0
#define ERR_peek_last_error() 0
#define ERR_error_string_n(e, buf, len)