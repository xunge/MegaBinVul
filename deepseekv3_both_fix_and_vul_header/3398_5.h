#include <stdint.h>

enum PaintPhase {
    PaintPhaseForeground,
    PaintPhaseSelection,
    PaintPhaseMask,
    PaintPhaseOutline,
    PaintPhaseSelfOutline
};

struct IntRect {
    IntRect() {}
};

struct IntPoint {
    IntPoint() {}
};

struct Color {
    Color() {}
};

struct LayoutSize {
    LayoutSize() {}
};

struct LayoutPoint {
    LayoutPoint() {}
    LayoutPoint operator+(const LayoutPoint&) const { return LayoutPoint(); }
};

struct LayoutRect {
    LayoutRect() {}
    LayoutRect(const LayoutPoint&, const LayoutSize&) {}
    bool isEmpty() const { return false; }
    operator IntRect() const { return IntRect(); }
};

struct RoundedRect {
    RoundedRect() {}
};

struct GraphicsContext {
    void save() {}
    void restore() {}
    void fillRect(const IntRect&, const Color&) {}
};

struct PaintInfo {
    PaintPhase phase;
    GraphicsContext* context;
    LayoutRect rect;
};

struct FrameView {
    FrameView() {}
};

struct Style {
    bool hasBorderRadius() const { return false; }
    RoundedRect getRoundedInnerBorderFor(const LayoutRect&, int, int, int, int, bool, bool) const { return RoundedRect(); }
};

struct Document {
    bool printing() const { return false; }
};

struct ScrollableArea {
    void paintResizer(GraphicsContext*, const IntPoint&, const LayoutRect&) {}
};

struct Layer {
    ScrollableArea* scrollableArea() { return nullptr; }
};

class RenderWidget {
public:
    void paint(PaintInfo&, const LayoutPoint&);
    bool shouldPaint(const PaintInfo&, const LayoutPoint&) const { return true; }
    LayoutPoint location() const { return LayoutPoint(); }
    bool hasBoxDecorations() const { return false; }
    void paintBoxDecorations(const PaintInfo&, const LayoutPoint&) {}
    void paintMask(const PaintInfo&, const LayoutPoint&) {}
    bool hasOutline() const { return false; }
    void paintOutline(const PaintInfo&, const LayoutRect&) {}
    FrameView* m_frameView = nullptr;
    Style* style() { return nullptr; }
    LayoutSize size() const { return LayoutSize(); }
    int paddingTop() const { return 0; }
    int paddingBottom() const { return 0; }
    int paddingLeft() const { return 0; }
    int paddingRight() const { return 0; }
    int borderTop() const { return 0; }
    int borderBottom() const { return 0; }
    int borderLeft() const { return 0; }
    int borderRight() const { return 0; }
    void clipRoundedInnerRect(GraphicsContext*, const LayoutRect&, const RoundedRect&) {}
    void* m_widget = nullptr;
    void paintContents(const PaintInfo&, const LayoutPoint&) {}
    bool isSelected() const { return false; }
    Document& document() { static Document d; return d; }
    LayoutRect selectionRect() const { return LayoutRect(); }
    Color selectionBackgroundColor() const { return Color(); }
    bool canResize() const { return false; }
    Layer* layer() { return nullptr; }
    IntRect pixelSnappedIntRect(const IntRect&) const { return IntRect(); }
    IntPoint roundedIntPoint(const LayoutPoint&) const { return IntPoint(); }
};

#define ANNOTATE_GRAPHICS_CONTEXT(paintInfo, widget)