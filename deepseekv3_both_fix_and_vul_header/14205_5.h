#include <memory>

enum class ConnectionSecurityLevel {
    PLAINTEXT,
    ENCRYPTED,
    ENCRYPTED_AUTHENTICATED
};

class NetworkAddress;
class SocketMultiplexer;

class IEventQueue {
public:
    class ClientListenerType {
    public:
        int connected();
    };
    ClientListenerType forClientListener();
    void adoptHandler(int, void*, void*);
};

template<typename T>
class TMethodEventJob {
public:
    TMethodEventJob(T*, void (T::*)(void*), void*);
};

class TCPSocketFactory {
public:
    TCPSocketFactory(IEventQueue*, SocketMultiplexer*);
};

class ClientListener {
public:
    ClientListener(const NetworkAddress&, TCPSocketFactory*, IEventQueue*, ConnectionSecurityLevel);
};

class ServerApp {
public:
    struct Args {
        bool m_enableCrypto;
        bool check_client_certificates;
    };
    
    Args& args();
    IEventQueue* m_events;
    SocketMultiplexer* getSocketMultiplexer();
    void handleClientConnected(void*);
    ClientListener* openClientListener(const NetworkAddress& address);
};