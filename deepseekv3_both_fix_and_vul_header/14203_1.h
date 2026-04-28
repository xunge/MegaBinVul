#include <string>
#include <cstring>

#define CLOG_PRINT
#define BYE

struct ServerArgs {
    std::string m_barrierAddress;
    std::string m_configFile;
    std::string m_screenChangeScript;
    std::string m_exename;
    bool check_client_certificates;
};

class ArgParser {
public:
    static bool parseServerArgs(ServerArgs& args, int argc, const char* const* argv);
    static void setArgsBase(ServerArgs& args);
    static void updateCommonArgs(const char* const* argv);
    static bool parsePlatformArg(ServerArgs& args, int argc, const char* const* argv, int i);
    static bool parseGenericArgs(int argc, const char* const* argv, int i);
    static bool parseDeprecatedArgs(int argc, const char* const* argv, int i);
    static bool isArg(int i, int argc, const char* const* argv, const char* shortOpt, const char* longOpt, int numArgs);
    static bool isArg(int i, int argc, const char* const* argv, const char* shortOpt, const char* longOpt);
    static bool checkUnexpectedArgs();
};

#define LOG(x)