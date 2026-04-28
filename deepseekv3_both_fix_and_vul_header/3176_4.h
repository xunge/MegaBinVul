#include <cassert>
#include <unordered_set>

#define ASSERT(expr) assert(expr)

class RenderSVGRoot;

class LayoutStateDisabler {
public:
    LayoutStateDisabler(void* view) {}
};

class LayoutRepainter {
public:
    LayoutRepainter(RenderSVGRoot& root, bool needsRepaint) {}
    void repaintAfterLayout() {}
};

class SVGRenderSupport {
public:
    static void layoutResourcesIfNeeded(RenderSVGRoot* root) {}
    static void layoutChildren(RenderSVGRoot* root, bool needsLayout) {}
    static bool filtersForceContainerLayout(RenderSVGRoot* root) { return false; }
};

class RenderSVGResourceContainer {
public:
    void removeAllClientsFromCache() {}
};

class SVGSVGElement {
public:
    bool hasRelativeLengths() const { return false; }
};

struct LayoutSize {
    bool operator!=(const LayoutSize& other) const { return false; }
};

template<typename T>
class HashSet {
public:
    using iterator = typename std::unordered_set<T>::iterator;
    
    std::unordered_set<T> m_data;
    bool isEmpty() const { return m_data.empty(); }
    void clear() { m_data.clear(); }
    iterator begin() { return m_data.begin(); }
    iterator end() { return m_data.end(); }
};

class RenderSVGRoot {
public:
    void layout();
    bool needsLayout() const;
    void* view();
    bool selfNeedsLayout();
    bool checkForRepaintDuringLayout();
    LayoutSize size() const;
    void updateLogicalWidth();
    void updateLogicalHeight();
    void buildLocalToBorderBoxTransform();
    void* node();
    void updateCachedBoundaries();
    void updateLayerTransform();
    void clearNeedsLayout();
    
    bool m_isLayoutSizeChanged;
    bool m_needsBoundariesOrTransformUpdate;
    HashSet<RenderSVGResourceContainer*> m_resourcesNeedingToInvalidateClients;
};

inline SVGSVGElement* toSVGSVGElement(void* node) { return static_cast<SVGSVGElement*>(node); }