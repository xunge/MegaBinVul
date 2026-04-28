#include <stddef.h>

struct WebRect {
    int width;
    int height;
    WebRect(int x, int y, int w, int h) : width(w), height(h) {}
};

struct Size {
    int width;
    int height;
};

class PageOverlays {
public:
    void update();
};

class WebViewImpl {
public:
    struct Client {
        void didInvalidateRect(const WebRect&);
    };
    
    bool isAcceleratedCompositingActive();
    void updateLayerTreeViewport();
    Client* m_client;
    Size m_size;
    PageOverlays* m_pageOverlays;
    
    class MainFrameImpl {
    public:
        class Frame {
        public:
            class Document {
            public:
                void enqueueResizeEvent();
            };
            class EventHandler {
            public:
                void sendResizeEvent();
            };
            Document* document();
            EventHandler& eventHandler();
        };
        class FrameView {
        };
        Frame* frame();
        FrameView* frameView();
    };
    
    MainFrameImpl* mainFrameImpl();
    void sendResizeEventAndRepaint();
};