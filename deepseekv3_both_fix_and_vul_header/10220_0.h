#include <stdlib.h>

#define RFBSTATE_UNINITIALISED 0

class SecurityClient;
class CConnection {
private:
    int csecurity;
    int is;
    int os;
    int reader_;
    int writer_;
    bool shared;
    int state_;
    bool useProtocol3_3;
    void* framebuffer;
    class Decoder {
    public:
        Decoder(CConnection* conn) {}
    } decoder;
    SecurityClient* security;

public:
    CConnection();
};

class SecurityClient {
public:
    SecurityClient() {}
};