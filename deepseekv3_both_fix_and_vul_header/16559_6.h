#include <stdlib.h>
#include <string.h>

typedef enum {
    ErrorNone,
    ErrorInvalidAccount,
    ErrorConnection,
    ErrorTLSNotAvailable,
    ErrorCertificate
} ErrorCode;

typedef enum {
    STATE_DISCONNECTED,
    STATE_CONNECTED
} SessionState;

typedef enum {
    ConnectionTypeStartTLS,
    ConnectionTypeTLS
} ConnectionType;

struct mailimap {
    struct mailstream * imap_stream;
    char * imap_response;
};

struct mailstream {
    struct mailstream_low * low;
};

struct mailstream_low {
    void (*set_identifier)(struct mailstream_low *, char *);
};

struct String {
    const char * UTF8Characters();
    int locationOfString(const char *str);
    static String * stringWithUTF8Format(const char *format, ...);
    static String * stringWithUTF8Characters(const char *chars);
};

struct IndexSet {
};

int mailimap_socket_connect_voip(struct mailimap *, const char *, unsigned int, bool);
int mailimap_socket_starttls(struct mailimap *);
int mailimap_ssl_connect_voip(struct mailimap *, const char *, unsigned int, bool);
void mailimap_set_163_workaround_enabled(struct mailimap *, int);
struct mailstream_low * mailstream_get_low(struct mailstream *);
void mailstream_low_set_identifier(struct mailstream_low *, char *);

struct IMAPSession {
    SessionState mState;
    ConnectionType mConnectionType;
    String* mHostname;
    unsigned int mPort;
    struct mailimap* mImap;
    struct String* mWelcomeString;
    struct IndexSet* mCurrentCapabilities;
    bool mIsCertificateValid;
    bool mYahooServer;
    bool mRamblerRuServer;
    bool mHermesServer;
    bool mQipServer;
    bool mIdleEnabled;
    bool mNamespaceEnabled;
    String* mUsername;
    
    void setup();
    void unsetup();
    bool isVoIPEnabled();
    bool hasError(int r);
    bool checkCertificate();
    bool isCheckCertificateEnabled();
    bool isAutomaticConfigurationEnabled();
    struct IndexSet* capability(ErrorCode* pError);
    void applyCapabilities(struct IndexSet* capabilities);
    void connect(ErrorCode* pError);
};

#define MCUTF8(x) ((x) ? (x)->UTF8Characters() : NULL)
#define MCUTF8DESC(x) (x)
#define MCLog(...)
#define MCAssert(x)
#define MCSTR(x) (x)
#define MC_SAFE_REPLACE_RETAIN(type, var, val)
#define LIBETPAN_HAS_MAILIMAP_163_WORKAROUND

void LOCK();
void UNLOCK();