#include <vector>
#include <memory>

class StyleRuleKeyframes;
class StyleRuleFontFace;

template<typename T>
class RawPtrWillBeMember {
public:
    operator T*() const { return nullptr; }
    T* operator->() const { return nullptr; }
    T& operator*() const { return *static_cast<T*>(nullptr); }
};

template<typename T>
class WillBeHeapVector {
public:
    size_t size() const { return 0; }
    T operator[](size_t) const { return T(); }
};

class RuleSet {
public:
    WillBeHeapVector<RawPtrWillBeMember<StyleRuleKeyframes>> keyframesRules() const;
    WillBeHeapVector<RawPtrWillBeMember<StyleRuleFontFace>> fontFaceRules() const;
};

class CSSStyleSheet;
class ContainerNode;
class ScopedStyleResolver;
class Document;
class TreeScope;
class FontSelector;

class StyleEngine {
public:
    void addScopedStyleResolver(ScopedStyleResolver*);
    FontSelector* fontSelector();
};

class StyleResolver {
protected:
    Document& m_document;
    class TreeBoundaryCrossingRules {
    public:
        void addTreeBoundaryCrossingRules(const RuleSet&, CSSStyleSheet*, unsigned, ContainerNode&);
    } m_treeBoundaryCrossingRules;

    Document& document();
    void addFontFaceRule(Document&, FontSelector*, StyleRuleFontFace*);
    void invalidateMatchedPropertiesCache();
    void processScopedRules(const RuleSet&, CSSStyleSheet*, unsigned, ContainerNode&);
};

class ScopedStyleResolver {
public:
    void addKeyframeStyle(StyleRuleKeyframes*);
};

class TreeScope {
public:
    ScopedStyleResolver& ensureScopedStyleResolver();
};

class ContainerNode {
public:
    TreeScope& treeScope();
    bool isDocumentNode() const;
};

class Document : public ContainerNode {
public:
    StyleEngine* styleEngine();
};