#include <stdlib.h>
#include <memory>

class ContainerNode;
class Document;

class SVGElement {
public:
    void removedFrom(ContainerNode*);
};

class FontFaceRule {
public:
    class Properties {
    public:
        void clear();
    };
    Properties* mutableProperties();
    FontFaceRule* get();
};

class SVGFontFaceElement : public SVGElement {
public:
    void removedFrom(ContainerNode*);
    Document& document();
    void* m_fontElement;
    std::shared_ptr<FontFaceRule> m_fontFaceRule;
};

class ContainerNode {
public:
    bool inDocument();
};

class Document {
public:
    class StyleEngine {
    public:
        class FontSelector {
        public:
            class FontFaceCache {
            public:
                void remove(FontFaceRule*);
            };
            FontFaceCache* fontFaceCache();
        };
        FontSelector* fontSelector();
    };
    class AccessSVGExtensions {
    public:
        void unregisterSVGFontFaceElement(SVGFontFaceElement*);
    };
    
    StyleEngine* styleEngine();
    AccessSVGExtensions& accessSVGExtensions();
    void styleResolverChanged(int);
    bool inDocument();
};

#define ASSERT(expr) ((void)0)
enum { RecalcStyleDeferred };