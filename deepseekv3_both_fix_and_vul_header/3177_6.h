#include <unordered_set>
#include <cassert>

class RenderObject;
class SVGElement;
class RenderSVGText;
class RenderSVGShape;
class SubtreeLayoutScope;

template<typename T> using HashSet = std::unordered_set<T>;

class SVGRenderSupport {
public:
    static void layoutChildren(RenderObject* start, bool selfNeedsLayout);
};

struct RenderObject {
    virtual RenderObject* firstChild();
    virtual RenderObject* nextSibling();
    virtual bool everHadLayout();
    virtual bool isSVGText();
    virtual bool isSVGShape();
    virtual bool isSVGResourceContainer();
    virtual SVGElement* node();
    virtual bool needsLayout();
    virtual void layout();
    virtual void repaint();
};

struct SVGElement {
    virtual bool hasRelativeLengths();
    virtual bool isSVGElement();
};

struct RenderSVGText {
    virtual void setNeedsTextMetricsUpdate();
    virtual void setNeedsPositioningValuesUpdate();
};

struct RenderSVGShape {
    virtual void setNeedsShapeUpdate();
};

struct SubtreeLayoutScope {
    explicit SubtreeLayoutScope(RenderObject*);
    void setNeedsLayout(RenderObject*);
};

#define ASSERT(expr) assert(expr)
#define isEmpty() empty()
#define add insert

bool layoutSizeOfNearestViewportChanged(RenderObject*);
bool transformToRootChanged(RenderObject*);
void layoutResourcesIfNeeded(RenderObject*);
void invalidateResourcesOfChildren(RenderObject*);
RenderSVGText* toRenderSVGText(RenderObject*);
RenderSVGShape* toRenderSVGShape(RenderObject*);
SVGElement* toSVGElement(SVGElement*);