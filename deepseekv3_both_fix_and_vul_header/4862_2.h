#include <string>
#include <cassert>

#define DCHECK(condition) assert(condition)

struct SSLInfo {
    bool client_cert_sent;
    bool channel_id_sent;
    struct {
        bool VerifyNameMatch(const std::string&, bool*) const { return false; }
    } *cert;
};

class ChannelIDService {
public:
    static std::string GetDomainForHost(const std::string&);
};

class QuicClientSession {
public:
    bool CanPool(const std::string& hostname) const;
protected:
    class Connection {
    public:
        bool connected() const;
    };
    Connection* connection() const;
    bool GetSSLInfo(SSLInfo*) const;
    struct {
        std::string host() const;
    } server_host_port_;
};