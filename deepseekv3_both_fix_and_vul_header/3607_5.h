#include <stdbool.h>

class RenderSVGText;

struct LayoutRectRecorder {
    explicit LayoutRectRecorder(RenderSVGText&);
};

struct LayoutRepainter {
    explicit LayoutRepainter(RenderSVGText&, bool);
    void repaintAfterLayout();
};

struct SVGRenderSupport {
    static bool checkForSVGRepaintDuringLayout(RenderSVGText*);
    static RenderSVGText* findTreeRootObject(RenderSVGText*);
};

struct SVGTextElement {
    void* animatedLocalTransform();
};

struct SVGResourcesCache {
    static void clientLayoutChanged(RenderSVGText*);
};

struct RenderSVGBlock {
    static void setNeedsBoundariesUpdate();
};

struct LayoutUnit {
    int value;
    LayoutUnit(int v = 0) : value(v) {}
    LayoutUnit operator+(const LayoutUnit& other) const;
    bool operator!=(const LayoutUnit& other) const;
};

struct FloatRect {
    float x, y, width, height;
    bool operator!=(const FloatRect& other) const;
};

struct LayoutAttributes {
    bool isEmpty() const;
};

class RenderSVGText {
public:
    void layout();
    bool isLayoutSizeChanged();

    bool m_needsTransformUpdate;
    bool m_needsReordering;
    bool m_needsTextMetricsUpdate;
    bool m_needsPositioningValuesUpdate;
    void* m_localTransform;
    LayoutAttributes m_layoutAttributes;
    struct {
        void buildLayoutAttributesForForSubtree(RenderSVGText*);
    } m_layoutAttributesBuilder;
    void* m_overflow;

    bool needsLayout();
    bool everHadLayout();
    bool selfNeedsLayout();
    bool isInline();
    bool simplifiedLayout();
    bool scrollsOverflow();
    bool hasControlClip();
    bool hasColumns();
    bool positionedObjects();
    bool isAnonymousBlock();
    bool childrenInline();
    FloatRect objectBoundingBox();
    void* firstChild();
    void* node();
    void rebuildFloatsFromIntruding();
    LayoutUnit borderBefore();
    LayoutUnit paddingBefore();
    LayoutUnit borderAfter();
    LayoutUnit paddingAfter();
    LayoutUnit scrollbarLogicalHeight();
    void setLogicalHeight(LayoutUnit);
    void layoutInlineChildren(bool, LayoutUnit, LayoutUnit, LayoutUnit);
    void subtreeStyleDidChange();
    void clearNeedsLayout();
    void setChildrenInline(bool);
    void setNeedsBoundariesUpdate();
};

void ASSERT(bool);
void collectLayoutAttributes(RenderSVGText*, LayoutAttributes&);
void updateFontInAllDescendants(RenderSVGText*);
void updateFontInAllDescendants(RenderSVGText*, void*);
void checkLayoutAttributesConsistency(RenderSVGText*, LayoutAttributes&);
SVGTextElement* toSVGTextElement(void*);