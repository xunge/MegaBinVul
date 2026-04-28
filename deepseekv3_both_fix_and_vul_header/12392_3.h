#include <stdbool.h>
#include <stdexcept>

namespace rdr {
    class InStream {
    public:
        virtual ~InStream() {}
    };
    
    class OutStream {
    public:
        virtual ~OutStream() {}
        virtual void writeU8(unsigned int) = 0;
        virtual void flush() = 0;
    };
    
    class TLSInStream : public InStream {
    public:
        TLSInStream(InStream*, void*);
        ~TLSInStream();
    };
    
    class TLSOutStream : public OutStream {
    public:
        TLSOutStream(OutStream*, void*);
        ~TLSOutStream();
        void writeU8(unsigned int) override;
        void flush() override;
    };
}

class SConnection {
public:
    virtual rdr::InStream* getInStream() = 0;
    virtual rdr::OutStream* getOutStream() = 0;
    virtual void setStreams(rdr::InStream*, rdr::OutStream*) = 0;
    virtual ~SConnection() {}
};

class AuthFailureException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class VLog {
public:
    void debug(const char*, ...);
    void error(const char*, ...);
};

extern VLog vlog;

typedef void* gnutls_session_t;
#define GNUTLS_SERVER 0
#define GNUTLS_E_SUCCESS 0

extern "C" {
    int gnutls_init(gnutls_session_t*, unsigned int);
    int gnutls_set_default_priority(gnutls_session_t);
    int gnutls_handshake(gnutls_session_t);
    const char* gnutls_strerror(int);
    int gnutls_error_is_fatal(int);
}

class SSecurityTLS {
public:
    gnutls_session_t session = nullptr;
    rdr::TLSInStream* fis = nullptr;
    rdr::TLSOutStream* fos = nullptr;
    void initGlobal();
    void setParams(gnutls_session_t session);
    void shutdown();
    bool processMsg(SConnection* sc);
};