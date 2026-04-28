#include <stdbool.h>

struct GraphicsContext {
    bool paintingDisabled();
};

struct PaintInfo {
    GraphicsContext* context;
    int phase;
    void applyTransform(void* transform);
};

struct LayoutPoint {};
struct FloatRect {
    bool isEmpty() const;
};
struct IntRect {
    IntRect(const FloatRect&);
    bool isEmpty() const;
};
struct GraphicsContextStateSaver {
    GraphicsContextStateSaver(GraphicsContext& context);
};
struct SVGRenderingContext {
    SVGRenderingContext(void* renderer, PaintInfo& paintInfo);
    bool isRenderingPrepared();
    bool bufferForeground(bool& foreground);
};

enum PaintPhase {
    PaintPhaseOutline,
    PaintPhaseSelfOutline,
    PaintPhaseForeground
};

#define HIDDEN 0
#define BR_STATIC 0
#define ANNOTATE_GRAPHICS_CONTEXT(paintInfo, obj)

struct Style {
    int visibility();
    int outlineWidth();
    struct SVGStyle* svgStyle();
};

struct SVGStyle {
    int bufferedRendering();
};

struct ImageResource {
    bool hasImage();
};

struct SVGRenderSupport {
    static bool paintInfoIntersectsRepaintRect(const FloatRect&, void* transform, PaintInfo&);
};

struct RenderSVGImage {
    void paint(PaintInfo&, const LayoutPoint&);
    Style* style();
    FloatRect repaintRectInLocalCoordinates();
    void paintForeground(PaintInfo&);
    void paintOutline(PaintInfo&, IntRect);
    
    ImageResource* m_imageResource;
    void* m_localTransform;
    FloatRect m_objectBoundingBox;
    bool m_bufferedForeground;
};