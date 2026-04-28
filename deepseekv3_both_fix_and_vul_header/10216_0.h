#include <stdint.h>

#define RFBSTATE_UNINITIALISED 0

namespace rfb {
    class Server {
    public:
        static bool protocol3_3;
    };
}

class SecurityServer {};
class SConnection {
private:
    bool readyForSetColourMapEntries;
    int is;
    int os;
    int* reader_;
    int* writer_;
    SecurityServer* security;
    SecurityServer* ssecurity;
    int state_;
    int preferredEncoding;
    int defaultMajorVersion;
    int defaultMinorVersion;
    struct {
        void setVersion(int, int) {}
    } cp;
public:
    SConnection();
};

const int encodingRaw = 0;