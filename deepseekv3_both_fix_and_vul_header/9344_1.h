#include <stddef.h>

struct Document;

struct FrameLoader {
    void dispatchUnloadEvent();
};

struct SubframeLoadingDisabler {
    SubframeLoadingDisabler(Document*);
    ~SubframeLoadingDisabler();
};

struct Frame {
    Document* document();
    FrameLoader& loader();
};

class WebLocalFrameImpl {
public:
    Frame* frame();
    void dispatchUnloadEvent();
};