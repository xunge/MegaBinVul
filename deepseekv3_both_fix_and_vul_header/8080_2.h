#include <string>

enum ReferrerPolicy {
    ReferrerPolicyDefault
};

class String {
public:
    bool isEmpty() const { return false; }
    bool isNull() const { return false; }
};

class CachedDocumentParameters {
public:
    ReferrerPolicy referrerPolicy;
};

class CSSPreloadScanner {
public:
    void setReferrerPolicy(ReferrerPolicy) {}
};

class SecurityPolicy {
public:
    static bool referrerPolicyFromString(const String&, ReferrerPolicy*) { return false; }
};