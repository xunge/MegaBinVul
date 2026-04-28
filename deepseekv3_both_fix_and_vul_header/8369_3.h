#include <stdbool.h>
#include <string.h>

typedef int CSSPropertyID;
typedef struct String { bool isEmpty() const; } String;
typedef struct StyleSheetContents StyleSheetContents;
struct MutableStylePropertySet {
    bool setProperty(CSSPropertyID unresolvedProperty, const String& value, bool important, StyleSheetContents* contextStyleSheet);
};
typedef struct CSSParser {
    static bool parseValue(MutableStylePropertySet*, CSSPropertyID, const String&, bool, StyleSheetContents*);
} CSSParser;

#define firstCSSProperty 0
#define DCHECK_GE(a, b) ((void)0)

CSSPropertyID resolveCSSPropertyID(CSSPropertyID id);
bool removeProperty(CSSPropertyID id);