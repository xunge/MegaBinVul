#include <string>
#include <exception>
#include <memory>

enum ConnectionSecurityLevel {
    PLAINTEXT,
    ENCRYPTED,
    ENCRYPTED_AUTHENTICATED
};

class XBase : public std::exception {
public:
    virtual const char* what() const throw() = 0;
};

class IDataSocket {
public:
    virtual ~IDataSocket() = default;
    virtual void connect(const class ServerAddress&) = 0;
};

class TCPSocket : public IDataSocket {
};

class PacketStreamFilter : public IDataSocket {
public:
    PacketStreamFilter(class Events*, IDataSocket*, bool);
    void connect(const class ServerAddress&) override;
};

class ServerAddress {
public:
    void resolve();
    void* getAddress();
    std::string getHostname();
    int getPort();
};

class SocketFactory {
public:
    IDataSocket* create(int family, ConnectionSecurityLevel level);
};

class Arch {
public:
    std::string addrToString(void* addr);
    int getAddrFamily(void* addr);
};

class Events {
};

class Client {
private:
    IDataSocket* m_stream = nullptr;
    bool m_suspended = false;
    bool m_connectOnResume = false;
    bool m_useSecureNetwork = false;
    ServerAddress m_serverAddress;
    SocketFactory* m_socketFactory = nullptr;
    Arch* ARCH = nullptr;
    Events* m_events = nullptr;
    TCPSocket* m_socket = nullptr;

public:
    void connect();
    void setupConnecting();
    void setupTimer();
    void cleanupTimer();
    void cleanupConnecting();
    void cleanupStream();
    void sendConnectionFailedEvent(const std::string& reason);
};

#define CLOG_NOTE 0
#define CLOG_DEBUG1 0
#define LOG(x)