#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <string>
#include <cstring>

class Capability {
public:
    bool ChangeUnixUser(uid_t uid);
    bool setInitialCapabilities();
    bool setMinimalCapabilities();
};

class Logger {
public:
    static void Error(const char* fmt, ...);
};

namespace folly {
    std::string errnoStr(int err) {
        return std::to_string(err) + ": " + strerror(err);
    }
}