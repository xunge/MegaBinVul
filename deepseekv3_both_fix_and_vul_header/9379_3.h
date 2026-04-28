#include <cstdint>
#include <memory>
#include <cassert>

#define ASSERT assert

class GraphicsLayer;
class ScrollingCoordinator;
class RenderView;

class RenderLayerCompositor {
public:
    enum RootLayerAttachment {
        RootLayerUnattached,
        RootLayerAttachedViaChromeClient,
        RootLayerAttachedViaEnclosingFrame
    };

    void ensureRootLayer();
    void* graphicsLayerFactory();
    ScrollingCoordinator* scrollingCoordinator();
    void detachRootLayer();
    void attachRootLayer(RootLayerAttachment);
    void frameViewDidChangeSize();

    RootLayerAttachment m_rootLayerAttachment;
    RenderView& m_renderView;
    std::unique_ptr<GraphicsLayer> m_rootContentLayer;
    std::unique_ptr<GraphicsLayer> m_overflowControlsHostLayer;
    std::unique_ptr<GraphicsLayer> m_scrollLayer;
    std::unique_ptr<GraphicsLayer> m_containerLayer;
};

class InspectorNodeIds {
public:
    static uintptr_t idForNode(void* node);
};

class FloatSize {
public:
    FloatSize(float, float);
};

class FloatPoint {
public:
    FloatPoint();
};

class IntRect {
public:
    int maxX() const;
    int maxY() const;
};

class GraphicsLayer {
public:
    static std::unique_ptr<GraphicsLayer> create(void* factory, void* owner);
    void setSize(const FloatSize&);
    void setPosition(const FloatPoint&);
    void setOwnerNodeId(uintptr_t);
    void setMasksToBounds(bool);
    void addChild(GraphicsLayer*);
};

class ScrollingCoordinator {
public:
    void setLayerIsContainerForFixedPositionLayers(GraphicsLayer*, bool);
};

class Settings {
public:
    bool mainFrameClipsContent() const;
};

class Document {
public:
    Settings* settings() const;
};

class Frame {
public:
    bool isLocalRoot() const;
};

class FrameView {
public:
    void frameViewDidChangeSize();
};

class RenderView {
public:
    Frame* frame() const;
    IntRect pixelSnappedLayoutOverflowRect() const;
    Document& document() const;
    void* generatingNode() const;
};