#include <chrono>

namespace application_features {
class ApplicationServer;
class BasicFeaturePhaseServer;
}

class ApplicationFeature {
public:
    ApplicationFeature(application_features::ApplicationServer&, const char*);
    void setOptional(bool);
    template<typename T> void startsAfter();
};

class AuthenticationFeature : public ApplicationFeature {
public:
    AuthenticationFeature(application_features::ApplicationServer&);
private:
    void* _userManager;
    void* _authCache;
    bool _authenticationUnixSockets;
    bool _authenticationSystemOnly;
    bool _localAuthentication;
    bool _active;
    double _authenticationTimeout;
    double _sessionTimeout;
};

#ifdef USE_ENTERPRISE
class LdapFeature;
#endif