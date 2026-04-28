#include <stddef.h>

struct WebSize {
    int width;
    int height;
};

class FrameView {
public:
    void setLayoutSize(const WebSize&);
};

class Frame {
public:
    FrameView* view();
};

class Page {
public:
    Frame* mainFrame();
};

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr);
    operator bool() const;
    T* operator->() const;
};

class WebViewImpl {
public:
    Page* page();
    void updateMainFrameLayoutSize();
    void setFixedLayoutSize(const WebSize&);
    bool m_fixedLayoutSizeLock;
};