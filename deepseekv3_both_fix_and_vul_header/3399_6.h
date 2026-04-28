#include <memory>

enum Visibility { VISIBLE, HIDDEN };

class RenderWidget;

class Widget {
public:
    void hide();
    void show();
};

class AXObjectCache {
public:
    void childrenChanged(RenderWidget*);
    AXObjectCache* existingAXObjectCache();
};

class FrameView {};

class RenderStyle {
public:
    Visibility visibility() const;
};

template<typename T>
class PassRefPtr {
public:
    PassRefPtr(T* ptr) : m_ptr(ptr) {}
    T* get() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
    operator T*() const { return m_ptr; }
private:
    T* m_ptr;
};

class RenderWidget {
public:
    PassRefPtr<Widget> m_widget;
    FrameView* m_frameView;
    
    bool needsLayout() const;
    void clearWidget();
    void repaint();
    void updateWidgetGeometry();
    RenderStyle* style() const;
    FrameView* frameView() const;
    AXObjectCache& document();
    void moveWidgetToParentSoon(Widget*, FrameView*);
    void setWidget(PassRefPtr<Widget> widget);
};