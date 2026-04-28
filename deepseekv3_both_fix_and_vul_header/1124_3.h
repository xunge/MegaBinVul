#include <memory>

class BooleanParameter {
public:
    explicit BooleanParameter(bool* ptr);
};

namespace arangodb {
namespace options {
enum class Flags {
    DefaultNoComponents,
    OnCoordinator,
    OnSingle
};
Flags makeFlags(Flags f1, Flags f2, Flags f3);
}  // namespace options
}  // namespace arangodb

class ProgramOptions {
public:
    ProgramOptions& addOption(const char* name, const char* description, BooleanParameter* param);
    ProgramOptions& addOption(const char* name, const char* description, BooleanParameter* param, arangodb::options::Flags flags);
    ProgramOptions& setIntroducedIn(int version);
};

class ServerSecurityFeature {
protected:
    bool _hardenedRestApi;
    bool _enableFoxxApi;
    bool _enableFoxxStore;
    bool _foxxAllowInstallFromRemote;
public:
    void collectOptions(std::shared_ptr<ProgramOptions> options);
};