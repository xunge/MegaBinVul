#include <string>
#include <stdint.h>

class QString {
public:
    QString(const char *str);
    QString &arg(const std::string &s);
    QString &arg(uint32_t n);
};

class ServerUser {
public:
    uint32_t uiVersion;
    std::string qsRelease;
    std::string qsOS;
    std::string qsOSVersion;
};

namespace MumbleProto {
    class Version {
    public:
        bool has_version() const;
        uint32_t version() const;
        bool has_release() const;
        std::string release() const;
        bool has_os() const;
        std::string os() const;
        bool has_os_version() const;
        std::string os_version() const;
    };
}

namespace MumbleVersion {
    std::string toString(uint32_t version);
}

std::string u8(const std::string &str);

class Server {
public:
    void msgVersion(ServerUser *uSource, MumbleProto::Version &msg);
    void log(ServerUser *user, const QString &message);
    void RATELIMIT(ServerUser *user);
};