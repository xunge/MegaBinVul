#include <stdbool.h>
#include <string.h>

typedef struct KURL {
    const char* protocol() const;
    bool isEmpty() const;
} KURL;

typedef struct String {
    const char* data;
    bool isEmpty() const { return !data || !*data; }
    operator const char*() const { return data; }
} String;

typedef struct CSPPolicy {
    bool protocolMatchesSelf(const KURL&) const;
} CSPPolicy;

typedef struct CSPSource {
    String m_scheme;
    const CSPPolicy* m_policy;
    bool schemeMatches(const KURL&) const;
} CSPSource;

bool equalIgnoringCase(const char* str1, const char* str2);