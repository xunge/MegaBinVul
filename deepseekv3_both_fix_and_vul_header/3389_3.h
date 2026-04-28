#include <stdbool.h>
#include <assert.h>

#define ASSERT assert

class HTMLToken {
public:
    enum Type {
        StartTag
    };
    Type type() const;
};

struct FilterTokenRequest {
    HTMLToken token;
};

enum {
    buttonTag,
    formactionAttr,
    SrcLikeAttribute
};

class String {
public:
    const char* string() const;
};

class XSSAuditor {
public:
    bool filterButtonToken(const FilterTokenRequest& request);
};

bool hasName(const HTMLToken& token, int tag);
bool eraseAttributeIfInjected(const FilterTokenRequest& request, int attr, const char* url, int attrType);
extern const char* kURLWithUniqueOrigin;
String blankURL();