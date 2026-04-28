#include <cassert>
#include <cstdlib>

class RenderObject {
public:
    bool isSVGInlineText();
    RenderObject* nextInPreOrder(RenderObject*);
};

class RenderSVGInlineText : public RenderObject {
};

class FontCachePurgePreventer {
};

class LayoutAttributes {
};

class LayoutAttributesBuilder {
public:
    void rebuildMetricsForTextRenderer(RenderSVGInlineText*);
};

RenderSVGInlineText* toRenderSVGInlineText(RenderObject*);

class RenderSVGText : public RenderObject {
public:
    bool shouldHandleSubtreeMutations();
    bool documentBeingDestroyed();
    void checkLayoutAttributesConsistency(RenderSVGText*, LayoutAttributes&);
    RenderObject* firstChild();
    void subtreeStyleDidChange();
    void subtreeStyleDidChange(RenderSVGInlineText*);
    
    LayoutAttributes m_layoutAttributes;
    LayoutAttributesBuilder m_layoutAttributesBuilder;
};

#define ASSERT(expr) assert(expr)