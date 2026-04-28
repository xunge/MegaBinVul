#include <memory>

class FrameLoadRequest;
class LocalFrame {
public:
    void navigate(const FrameLoadRequest& request);
    bool isNavigationAllowed();
    class Loader {
    public:
        void load(const FrameLoadRequest& request);
    };
    Loader m_loader;
};