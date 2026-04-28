#include <stdbool.h>
#include <stddef.h>

class KURL {
public:
    bool protocolIs(const char*) const;
};

class SecurityOrigin {
public:
    static bool shouldUseInnerURL(const KURL&);
    static KURL extractInnerURL(const KURL&);
};

namespace ContentSecurityPolicy {
    enum RedirectStatus {
        NoRedirect,
        DidRedirect
    };
}

class Policy {
public:
    bool selfMatchesInnerURL() const;
    bool urlMatchesSelf(const KURL&) const;
};

template<typename T>
class Vector {
public:
    size_t size() const;
    T& operator[](size_t);
    const T& operator[](size_t) const;
};

struct Source {
    bool matches(const KURL&, ContentSecurityPolicy::RedirectStatus) const;
};

class CSPSourceList {
private:
    bool m_allowStar;
    bool m_allowSelf;
    Policy* m_policy;
    Vector<Source> m_list;

    bool hasSourceMatchInList(const KURL&, ContentSecurityPolicy::RedirectStatus) const;
public:
    bool matches(const KURL&, ContentSecurityPolicy::RedirectStatus) const;
};