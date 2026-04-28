#include <vector>
#include <unordered_set>

class XRef;
class Dict {
public:
    const class Object &lookupNF(const char *key) const;
    class Object lookup(const char *key) const;
    class Object lookup(const char *key, class Ref *ref) const;
    int dictGetLength() const;
    const class Object &dictGetValNF(int i) const;
};
class Object {
public:
    bool isRef() const;
    bool isDict() const;
    bool isStream() const;
    class Object fetch(class XRef *xrefA) const;
    class Ref getRef() const;
    class Dict* getDict() const;
    class Dict* streamGetDict() const;
    int dictGetLength() const;
    const class Object &dictGetValNF(int i) const;
};
class Ref {
public:
    int num;
    static const Ref INVALID();
    bool operator!=(const Ref &other) const;
};
class GfxFontDict {
public:
    GfxFontDict(class XRef *xrefA, const class Ref *ref, class Dict *dict);
    ~GfxFontDict();
    int getNumFonts() const;
    class GfxFont *getFont(int i) const;
};
class GfxFont {
public:
    const class Ref *getID() const;
};
class FontInfo {
public:
    FontInfo(class GfxFont *font, class XRef *xrefA);
};

class FontInfoScanner {
public:
    void scanFonts(class XRef *xrefA, class Dict *resDict, std::vector<class FontInfo*> *fontsList);
};

static std::unordered_set<int> fonts;
static std::unordered_set<int> visitedObjects;