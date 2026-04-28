#include <stdbool.h>
#include <stdint.h>
#include <string.h>

namespace rdr {
    typedef uint32_t U32;
    
    class InStream {
    public:
        bool checkNoWait(int);
        uint8_t readU8();
        U32 readU32();
        char* readString();
    };

    class OutStream {
    };

    class TLSInStream : public InStream {
    public:
        TLSInStream(InStream*, void*);
    };

    class TLSOutStream : public OutStream {
    public:
        TLSOutStream(OutStream*, void*);
    };
}

class CConnection {
public:
    rdr::InStream* getInStream();
    rdr::OutStream* getOutStream();
    void setStreams(rdr::TLSInStream*, rdr::TLSOutStream*);
};

class AuthFailureException {
public:
    AuthFailureException(const char*);
};

class CharArray {
public:
    char* buf;
};

class CSecurityTLS {
public:
    bool processMsg(CConnection* cc);
private:
    CConnection* client;
    void* session;
    rdr::TLSInStream* fis;
    rdr::TLSOutStream* fos;
    void initGlobal();
    void setParam();
    void checkSession();
    void shutdown(bool);
};

enum {
    secResultFailed,
    secResultTooMany,
    GNUTLS_CLIENT,
    GNUTLS_E_SUCCESS
};

char* strDup(const char*);

class Vlog {
public:
    void error(const char*, ...);
};

extern Vlog vlog;

int gnutls_init(void**, int);
int gnutls_set_default_priority(void*);
int gnutls_handshake(void*);
int gnutls_error_is_fatal(int);
const char* gnutls_strerror(int);