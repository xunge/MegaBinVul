#include <stdbool.h>
#include <string.h>

enum ResourceType {
    Script
};

enum ScriptIntegrityDisposition {
    NotChecked,
    Failed,
    Passed
};

class ResourceBuffer {
public:
    const char* data();
    size_t size();
};

class Resource {
public:
    ResourceType type();
    ResourceBuffer* resourceBuffer();
    const char* url();
};

class String {
public:
    bool isEmpty() const;
};

class IntegrityMetadata {
public:
    bool isEmpty() const;
};

class ScriptResource : public Resource {
public:
    void setIntegrityDisposition(ScriptIntegrityDisposition);
    ScriptIntegrityDisposition integrityDisposition();
    bool integrityAlreadyChecked();
    void setIntegrityAlreadyChecked(bool);
    IntegrityMetadata integrityMetadata();
};

class HTMLNames {
public:
    static const char* integrityAttr;
};

class Element {
public:
    String fastGetAttribute(const char*);
};

class SubresourceIntegrity {
public:
    static bool CheckSubresourceIntegrity(const IntegrityMetadata&, Element&, const char*, size_t, const char*, Resource&);
};

class Streamer {
public:
    void notifyFinished(Resource*);
};

class PendingScript {
private:
    Element* m_element;
    bool m_integrityFailure;
    Streamer* m_streamer;
public:
    void notifyFinished(Resource*);
};

inline ScriptResource* toScriptResource(Resource* resource) {
    return static_cast<ScriptResource*>(resource);
}

#define ASSERT(expr) ((void)0)