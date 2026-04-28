#include <stdbool.h>

struct Frame;

struct KeyboardEvent {
    const char* keyIdentifier();
    void setDefaultHandled();
};

class RenderTheme {
public:
    static RenderTheme& theme();
    bool popsMenuByArrowKeys();
};

class Document {
public:
    Frame* frame();
};

class RenderObject {
public:
    bool isMenuList();
};

class RenderMenuList : public RenderObject {
public:
    void showPopup();
};

class HTMLSelectElement {
public:
    void focus();
    bool isDisabledFormControl();
    RenderObject* renderer();
    void saveLastSelection();
    Document& document();
    bool platformHandleKeydownEvent(KeyboardEvent* event);
};

bool isSpatialNavigationEnabled(Frame*);
RenderMenuList* toRenderMenuList(RenderObject*);