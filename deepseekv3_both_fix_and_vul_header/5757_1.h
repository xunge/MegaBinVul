#include <string>

class DomainState {
public:
    bool ShouldUpgradeToSSL() const;
};

class TransportSecurityState {
public:
    bool ShouldUpgradeToSSL(const std::string& host);
private:
    bool GetDynamicDomainState(const std::string& host, DomainState* state);
    bool GetStaticDomainState(const std::string& host, DomainState* state);
};