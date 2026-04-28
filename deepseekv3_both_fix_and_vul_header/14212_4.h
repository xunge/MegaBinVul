#include <memory>
#include <string>

namespace arangodb {
namespace options {
    class Flags {
    public:
        static Flags DefaultNoComponents;
        static Flags OnCoordinator;
        static Flags OnSingle;
        static Flags DefaultNoOs;
        static Flags OsLinux;
        static Flags OsMac;
        static Flags Enterprise;
    };
    Flags makeFlags(Flags...);
    Flags makeDefaultFlags(Flags);
}  // namespace options
}  // namespace arangodb

class BooleanParameter;
class DoubleParameter;
class StringParameter;

class ProgramOptions {
public:
    void addOldOption(const std::string&, const std::string&);
    ProgramOptions& addOption(const std::string&, const std::string&, BooleanParameter*);
    ProgramOptions& addOption(const std::string&, const std::string&, DoubleParameter*);
    ProgramOptions& addOption(const std::string&, const std::string&, StringParameter*);
    ProgramOptions& addOption(const std::string&, const std::string&, BooleanParameter*, arangodb::options::Flags);
    ProgramOptions& addOption(const std::string&, const std::string&, DoubleParameter*, arangodb::options::Flags);
    ProgramOptions& addOption(const std::string&, const std::string&, StringParameter*, arangodb::options::Flags);
    ProgramOptions& setDeprecatedIn(int);
    ProgramOptions& setIntroducedIn(int);
};

class BooleanParameter {
public:
    explicit BooleanParameter(bool*);
};

class DoubleParameter {
public:
    explicit DoubleParameter(double*);
};

class StringParameter {
public:
    explicit StringParameter(std::string*);
};

class AuthenticationFeature {
public:
    void collectOptions(std::shared_ptr<ProgramOptions> options);
private:
    bool _active;
    double _authenticationTimeout;
    double _sessionTimeout;
    bool _localAuthentication;
    bool _authenticationSystemOnly;
    bool _authenticationUnixSockets;
    std::string _jwtSecretProgramOption;
    std::string _jwtSecretKeyfileProgramOption;
    std::string _jwtSecretFolderProgramOption;
};