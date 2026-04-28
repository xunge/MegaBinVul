#include <string>

enum class ScriptIntegrityDisposition {
    NotChecked,
    Failed,
    Passed
};

class AtomicString {
public:
    AtomicString(const char*, int);
    static AtomicString ConstructFromLiteral;
};

class String {};

class ResourceRequest {};

class TextResource {
public:
    TextResource(const ResourceRequest&, int, const char*, const String&);
    void setAccept(const AtomicString&);
};

class ScriptResource : public TextResource {
public:
    ScriptResource(const ResourceRequest&, const String&);
    ScriptIntegrityDisposition m_integrityDisposition;
    bool m_integrityChecked;
    static const int Script;
};

#define DEFINE_STATIC_LOCAL(type, name, value) static type name = value