#include <stdbool.h>
#include <string>

class String {
public:
    bool isEmpty() const;
    String lower() const;
};

class KURL {
public:
    bool isValid() const;
    String protocol() const;
    String host() const;
};

class SecurityOrigin {
public:
    static bool shouldUseInnerURL(const KURL&);
    static KURL extractInnerURL(const KURL&);
};

class SchemeRegistry {
public:
    static bool shouldTreatURLSchemeAsNoAccess(const String&);
};

bool schemeRequiresAuthority(const KURL&);