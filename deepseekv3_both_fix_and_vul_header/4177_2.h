#include <memory>

class ShadowRoot {
public:
    void removeChildren();
    ShadowRoot* userAgentShadowRoot();
};

class ImageInputType {
public:
    void ensurePrimaryContent();
    ShadowRoot& element();
    bool m_useFallbackContent;
    void createShadowSubtree();
    void reattachFallbackContent();
};