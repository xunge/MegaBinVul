#include <stddef.h>
#include <assert.h>

#define ASSERT(x) assert(x)

class RenderWidget;

class FrameView {
public:
    void addWidget(RenderWidget*);
};

class Document {
public:
    FrameView* view();
};

class Element {
public:
    Document& document();
};

class RenderReplaced {
public:
    RenderReplaced(Element*);
};

class RenderWidget : public RenderReplaced {
public:
    RenderWidget(Element* element);
    
private:
    void* m_widget;
    FrameView* m_frameView;
    int m_refCount;
    
    FrameView* frameView() const { return m_frameView; }
    FrameView* view() const { return m_frameView; }
};