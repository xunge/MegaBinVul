#include <string>
#include <algorithm>

using namespace std;

enum Wildcard { HasWildcard, NoWildcard };
const bool TextCaseInsensitive = true;

class String {
public:
    bool endsWith(const String&, bool) const;
    String operator+(const char*) const;
    friend String operator+(const char*, const String&);
};

class KURL {
public:
    String host() const;
};

class Document;
class UseCounter {
public:
    enum CounterType { CSPSourceWildcardWouldMatchExactHost };
    static void count(const Document&, CounterType);
};

class CSPPolicy {
public:
    Document* document() const;
};

class CSPSource {
private:
    String m_host;
    Wildcard m_hostWildcard;
    CSPPolicy* m_policy;
public:
    bool hostMatches(const KURL&) const;
};

bool equalIgnoringCase(const String&, const String&);

String operator+(const char*, const String&);