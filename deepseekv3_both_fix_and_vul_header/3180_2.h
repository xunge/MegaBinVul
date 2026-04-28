#include <stdbool.h>

struct QualifiedName {
    bool operator==(const QualifiedName&) const { return false; }
};

struct SVGNames {
    static const QualifiedName widthAttr;
    static const QualifiedName heightAttr;
    static const QualifiedName xAttr;
    static const QualifiedName yAttr;
};

class RenderObject {
public:
    bool isSVGRoot() const { return false; }
    void setNeedsTransformUpdate() {}
    RenderObject* renderer() { return nullptr; }
};

class RenderSVGRoot : public RenderObject {
public:
    void setNeedsLayoutAndPrefWidthsRecalc() {}
};

RenderSVGRoot* toRenderSVGRoot(RenderObject* obj) { return nullptr; }

class SVGFitToViewBox {
public:
    static bool isKnownAttribute(const QualifiedName&) { return false; }
};

class SVGLangSpace {
public:
    static bool isKnownAttribute(const QualifiedName&) { return false; }
};

class SVGExternalResourcesRequired {
public:
    static bool isKnownAttribute(const QualifiedName&) { return false; }
};

class SVGZoomAndPan {
public:
    static bool isKnownAttribute(const QualifiedName&) { return false; }
};

class SVGElementInstance {
public:
    class InvalidationGuard {
    public:
        InvalidationGuard(void*) {}
    };
};

class SVGGraphicsElement {
public:
    void svgAttributeChanged(const QualifiedName&) {}
};

class RenderSVGResource {
public:
    static void markForLayoutAndParentResourceInvalidation(RenderObject*) {}
};

class SVGSVGElement : public SVGGraphicsElement {
public:
    void svgAttributeChanged(const QualifiedName&);
    void updateRelativeLengthsInformation() {}
    void invalidateRelativeLengthClients() {}
    RenderObject* renderer() { return nullptr; }
};