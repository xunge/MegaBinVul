#include <stdbool.h>

typedef struct KURL {
    int port() const;
    const char* protocol() const;
} KURL;

enum Wildcard { NoWildcard, HasWildcard };

struct CSPSource {
    enum Wildcard m_portWildcard;
    int m_port;
    bool portMatches(const KURL& url) const;
};

int defaultPortForProtocol(const char* protocol);
bool isDefaultPortForProtocol(int port, const char* protocol);