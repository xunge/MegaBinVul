#include <memory>
#include <cassert>

class Navigator;
class Frame;

class LocalDOMWindow {
public:
    Navigator* navigator() const;
    bool isCurrentlyDisplayedInFrame() const;
    Frame* frame() const;
    mutable std::unique_ptr<Navigator> m_navigator;
};

class Navigator {
public:
    static std::unique_ptr<Navigator> create(Frame*);
    Frame* frame() const;
};

#define ASSERT assert