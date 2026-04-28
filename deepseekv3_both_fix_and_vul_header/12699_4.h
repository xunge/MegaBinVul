#include <string>
#include <vector>

#define CXX11_OVERRIDE

enum CmdResult {
    CMD_SUCCESS,
    CMD_FAILURE
};

#define ERR_NOORIGIN 0

class LocalUser {
public:
    void WriteNumeric(int numeric, const std::string& message);
    template<typename T>
    void Send(int event, const T& message);
};

class Params : public std::vector<std::string> {
};

class RFCEvents {
public:
    int pong;
};

class ServerInstance {
public:
    class Config {
    public:
        std::string GetServerName();
    };
    Config* Config;
    RFCEvents GetRFCEvents();
};

extern ServerInstance* ServerInstance;

namespace ClientProtocol {
    namespace Messages {
        class Pong {
        public:
            Pong(const std::string& param1, const std::string& param2);
        };
    }
}