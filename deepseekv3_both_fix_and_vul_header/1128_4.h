#include <string>

namespace application_features {
class ApplicationServer;
class GreetingsFeaturePhase;

class ApplicationFeature {
public:
    ApplicationFeature(ApplicationServer& server, const std::string& name);
    void setOptional(bool optional);
    template<typename T> void startsAfter();
};

class ServerSecurityFeature : public ApplicationFeature {
public:
    ServerSecurityFeature(ApplicationServer& server);
    
private:
    bool _enableFoxxApi;
    bool _enableFoxxStore;
    bool _hardenedRestApi;
    bool _foxxAllowInstallFromRemote;
};
}

using application_features::ServerSecurityFeature;