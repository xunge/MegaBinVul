#include <string>

namespace application_features {

class ApplicationServer;
class GreetingsFeaturePhase;

class ApplicationFeature {
public:
    ApplicationFeature(ApplicationServer& server, const std::string& name);
    void setOptional(bool value);
    template<typename T> void startsAfter();
};

} // namespace application_features

class ServerSecurityFeature : public application_features::ApplicationFeature {
public:
    ServerSecurityFeature(application_features::ApplicationServer& server);
    
protected:
    bool _enableFoxxApi;
    bool _enableFoxxStore;
    bool _hardenedRestApi;
    bool _foxxAllowInstallFromRemote;
};