#include <stdbool.h>
#include <string.h>

typedef struct {
    int type();
} HTMLToken;

typedef struct {
    HTMLToken token;
} FilterTokenRequest;

typedef struct {
    bool filterInputToken(const FilterTokenRequest& request);
} XSSAuditor;

#define ASSERT(expr) ((void)0)
#define inputTag NULL
#define formactionAttr NULL
#define blankURL() ((URL){0})
#define SrcLikeAttribute NULL
#define eraseAttributeIfInjected(req, attr, str, type) false

typedef struct {
    char* string();
} URL;

bool hasName(HTMLToken token, const char* name);