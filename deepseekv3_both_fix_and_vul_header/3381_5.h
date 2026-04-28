#include <cassert>
#include <vector>
#include <memory>

class FrameView;

class Timer {
public:
    bool isActive() const { return false; }
    void stop() {}
};

class Scrollbar {
public:
    bool isCustomScrollbar() const { return false; }
};

class RenderPart {
public:
    void* widget() const { return nullptr; }
    void setWidget(void*) {}
};

class RenderWidget {};

class HostWindow {};

class AXObjectCache {
public:
    void remove(FrameView*) {}
};

struct OverflowEvent {};

class Frame {
public:
    FrameView* view() const { return nullptr; }
    RenderPart* ownerRenderer() const { return nullptr; }
    RenderPart* contentRenderer() const { return nullptr; }
};

#define ASSERT(expr) assert(expr)

class FrameView {
public:
    ~FrameView();

private:
    Timer m_postLayoutTasksTimer;
    std::vector<OverflowEvent> m_overflowEventQueue;
    Frame* m_frame;
    Scrollbar* m_horizontalScrollbar;
    Scrollbar* m_verticalScrollbar;
    RenderWidget* m_scrollCorner;
    HostWindow* m_hostWindow;
    AXObjectCache* m_axObjectCache;

    void removeFromAXObjectCache() { m_axObjectCache->remove(this); }
    void resetScrollbars() {}
    Scrollbar* horizontalScrollbar() const { return m_horizontalScrollbar; }
    Scrollbar* verticalScrollbar() const { return m_verticalScrollbar; }
    bool setHasHorizontalScrollbar(bool) { return false; }
    bool setHasVerticalScrollbar(bool) { return false; }
    bool m_hasHorizontalScrollbar;
    bool m_hasVerticalScrollbar;
};

// 修改 ASSERT 语句中的 isEmpty() 为 empty()
#define ASSERT(expr) assert(expr)
#define isEmpty() empty()