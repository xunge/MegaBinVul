#include <stddef.h>
#include <assert.h>

#define ASSERT assert

class RenderBox {
public:
    bool hasRelativeLogicalHeight() const;
};

class SVGElement {
public:
    void invalidateRelativeLengthClients(void*);
};

class LayoutState {
public:
    bool isStopping() const;
};

class FrameView {
public:
    LayoutState partialLayout() const;
};

struct Configuration {
    bool paginated() const;
};

struct Style {
    struct Length {
        bool isPercent() const;
        bool isViewportPercentage() const;
    };
    Length logicalHeight() const;
    Length logicalMinHeight() const;
    Length logicalMaxHeight() const;
};

class Node {
public:
    bool isSVGElement() const;
};

class FlowThreadController {
public:
    void setCurrentRenderFlowThread(int);
};

class SubtreeLayoutScope {
public:
    SubtreeLayoutScope(void*);
    void setChildNeedsLayout(void*);
};

class RenderObject {
public:
    RenderObject* nextSibling();
    bool isBox() const;
    Style* style() const;
    bool isSVGRoot() const;
    Node* node() const;
};

class RenderView {
public:
    void layout();
    Configuration configuration() const;
    void setPageLogicalHeight(int);
    bool shouldUsePrintingLayout() const;
    int logicalWidth() const;
    FrameView* m_frameView;
    int width() const;
    int viewWidth() const;
    int height() const;
    int viewHeight() const;
    RenderObject* firstChild();
    LayoutState* m_layoutState;
    bool needsLayout() const;
    bool initializeLayoutState(LayoutState&);
    bool m_pageLogicalHeightChanged;
    bool checkTwoPassLayoutForAutoHeightRegions();
    void layoutContentInAutoLogicalHeightRegions(LayoutState&);
    void layoutContent(LayoutState&);
    void clearNeedsLayout();
    bool isSeamlessAncestorInFlowThread;
    FlowThreadController* flowThreadController();
    int m_minPreferredLogicalWidth;
    int m_maxPreferredLogicalWidth;
    void checkLayoutState(LayoutState&);
};

inline RenderBox* toRenderBox(RenderObject* object) {
    return reinterpret_cast<RenderBox*>(object);
}

inline SVGElement* toSVGElement(Node* node) {
    return reinterpret_cast<SVGElement*>(node);
}