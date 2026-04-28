#include <memory>
#include <string>

class String {
public:
    String();
    String(const char*);
    String operator+(const String&) const;
};

class SharedBuffer {
public:
    const char* data();
    unsigned size();
};

class TextResourceDecoder {
public:
    String decode(const char* data, unsigned size);
    String flush();
};

template<typename T> class OwnPtr {
public:
    T* operator->();
    operator bool() const;
};

class Resource {
public:
    enum Type {
        CSSStyleSheet,
        Script,
        ImportResource,
        Raw
    };
    Type type();
    SharedBuffer* resourceBuffer();
    class Response {
    public:
        String mimeType();
        String textEncodingName();
    };
    Response& response();
};

class CSSStyleSheetResource : public Resource {
public:
    String sheetText(bool includeComments = true);
};

class ScriptResource : public Resource {
public:
    String decodedText();
    String script();
};

class InspectorPageAgent {
public:
    bool cachedResourceContent(Resource* cachedResource, String* result, bool* base64Encoded);
    static OwnPtr<TextResourceDecoder> createResourceTextDecoder(const String& mimeType, const String& textEncodingName);
    bool prepareResourceBuffer(Resource*, bool* hasZeroSize);
    bool hasTextContent(Resource*);
    bool encodeCachedResourceContent(Resource*, bool hasZeroSize, String* result, bool* base64Encoded);
    bool decodeBuffer(const char* data, unsigned size, const String& textEncodingName, String* result);
};

CSSStyleSheetResource* toCSSStyleSheetResource(Resource*);
ScriptResource* toScriptResource(Resource*);