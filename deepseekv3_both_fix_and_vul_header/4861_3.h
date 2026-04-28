#include <string>

enum State {
  STATE_DRAINING
};

struct HostPortPair {
  std::string host() const;
};

struct SSLInfo {
  bool client_cert_sent;
  bool channel_id_sent;
  struct {
    bool VerifyNameMatch(const std::string&, bool*);
  }* cert;
};

class ChannelIDService {
 public:
  static std::string GetDomainForHost(const std::string&);
};

enum NextProto {
  kProtoUnknown
};

class SpdySession {
 public:
  bool verify_domain_authentication_;
  State availability_state_;
  HostPortPair host_port_pair_;
  bool GetSSLInfo(SSLInfo*, bool*, NextProto*);
  bool VerifyDomainAuthentication(const std::string& domain);
  const HostPortPair& host_port_pair() const { return host_port_pair_; }
};