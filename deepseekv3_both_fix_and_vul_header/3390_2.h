#include <stdbool.h>

enum HTMLTokenType {
    StartTag
};

struct HTMLToken {
    HTMLTokenType type() { return StartTag; }
};

struct FilterTokenRequest {
    HTMLToken token;
};

struct XSSAuditor {
    bool filterFormToken(const FilterTokenRequest& request);
    bool eraseAttributeIfInjected(const FilterTokenRequest& request, int attr, const char* url);
};

#define ASSERT(expr) ((void)0)
#define formTag 0
#define actionAttr 0
#define kURLWithUniqueOrigin ""
struct BlankURL {
    const char* string() { return ""; }
};
BlankURL blankURL() { return BlankURL(); }

bool hasName(HTMLToken token, int tag);