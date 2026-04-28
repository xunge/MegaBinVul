#include <memory>

class DocumentLoader;
class FrameNavigationDisabler;
class Frame;

template<typename T> class Member {
public:
    Member() = default;
    Member(std::nullptr_t) {}
    explicit Member(T* ptr) {}
    operator bool() const { return false; }
    T* operator->() const { return nullptr; }
    Member& operator=(std::nullptr_t) { return *this; }
};

class Frame {
};

class DocumentLoader {
public:
    void detachFromFrame();
};

class FrameNavigationDisabler {
public:
    FrameNavigationDisabler(Frame&);
};

class FrameLoader {
public:
    void detachDocumentLoader(Member<DocumentLoader>& loader);
    Frame* m_frame;
};