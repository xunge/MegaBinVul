#include <stdbool.h>

struct ContainerNode;
struct Document;
struct ShadowRoot;
struct ScopedStyleResolver;
struct DocumentFragment;

struct DocumentFragment {
    void removedFrom(ContainerNode* insertionPoint);
};

struct ContainerNode {
    bool inDocument();
    Document& document();
    ShadowRoot* containingShadowRoot();
};

struct ShadowRoot : public DocumentFragment {
    bool m_registeredWithParentShadowRoot;
    ScopedStyleResolver* scopedStyleResolver();
    ShadowRoot* host();
    ShadowRoot* containingShadowRoot();
    void removeChildShadowRoot();
    void removedFrom(ContainerNode* insertionPoint);
};

struct Document {
    struct StyleEngine {
        void removeScopedStyleResolver(ScopedStyleResolver* resolver);
    };
    StyleEngine* styleEngine();
};

struct ScopedStyleResolver {};