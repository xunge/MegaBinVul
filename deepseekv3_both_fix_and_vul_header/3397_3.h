#include <stddef.h>

class RenderWidget;

class AXObjectCache {
public:
    void childrenChanged(void*);
    void remove(RenderWidget*);
};

class Document {
public:
    AXObjectCache* existingAXObjectCache();
};

class FrameView {
public:
    void removeWidget(RenderWidget*);
};

class RenderReplaced {
public:
    void willBeDestroyed();
};

class RenderView {
public:
    void removeWidget(RenderWidget*);
};

class RenderWidget : public RenderReplaced {
public:
    FrameView* frameView();
    Document& document();
    RenderView* view();
    void* parent();
    void setWidget(int);
    void willBeDestroyed();
};