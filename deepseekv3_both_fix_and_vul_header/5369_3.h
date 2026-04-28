#include <cassert>
#define ASSERT(x) assert(x)

class HTMLFrameOwnerElement {
public:
    class UpdateSuspendScope {};
};

class AttachContext {
public:
    bool performingReattach;
};

class Document {
public:
    bool inStyleRecalc() const;
    void unscheduleSVGFilterLayerUpdateHack(class Element&);
};

class ActiveAnimations {
public:
    void cancelAnimationOnCompositor();
    void setAnimationStyleChange(bool);
    void clearBaseRenderStyle();
    class CSSAnimations {
    public:
        void cancel();
    };
    CSSAnimations& cssAnimations();
};

class ElementShadow {
public:
    void detach(const AttachContext&);
};

class ElementRareData {
public:
    void clearPseudoElements();
    void clearComputedStyle();
    ActiveAnimations* activeAnimations();
    ElementShadow* shadow();
};

class ContainerNode {
public:
    void detach(const AttachContext&);
};

class DisableCompositingQueryAsserts {};

class Element : public ContainerNode {
public:
    ElementRareData* elementRareData();
    bool hasRareData() const;
    bool svgFilterNeedsLayerUpdate() const;
    void cancelFocusAppearanceUpdate();
    void removeCallbackSelectors();
    Document& document();
    bool needsAttach() const;
    void detach(const AttachContext&);
};