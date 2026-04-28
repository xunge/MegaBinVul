#include <iostream>
#include <mutex>
#include <map>
#include <string>
#include <stdexcept>
#include <errno.h>

struct IdKeyPair {
    std::string id;
    std::string key;
    IdKeyPair(const std::pair<std::string, std::string>& p) : id(p.first), key(p.second) {}
};

class UserTerminalRouter {
public:
    IdKeyPair acceptNewConnection();
};

enum class TerminalPacketType {
    TERMINAL_USER_INFO
};

class Packet {
public:
    TerminalPacketType getHeader() const;
    std::string getPayload() const;
};

class TerminalUserInfo {
public:
    void set_fd(int fd);
    std::string id() const;
    std::string passkey() const;
    void set_id(const std::string& id);
    void set_passkey(const std::string& passkey);
};

template<typename T>
T stringToProto(const std::string&);

class SocketHandler {
public:
    int accept(int fd);
    bool readPacket(int fd, Packet* packet);
};

extern SocketHandler* socketHandler;
extern int serverFd;
extern std::recursive_mutex routerMutex;
extern std::map<std::string, TerminalUserInfo> idInfoMap;

#define LOG(level) std::cout
#define STFATAL std::cerr
#define FATAL_FAIL(x) abort()
#define GetErrno() errno

using std::lock_guard;
using std::recursive_mutex;