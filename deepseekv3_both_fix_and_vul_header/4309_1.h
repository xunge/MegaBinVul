#include <stdbool.h>

struct Document;
struct Frame;
struct Loader;

struct HTMLConstructionSite {
    Document* m_document;
    bool m_isParsingFragment;
    void dispatchDocumentElementAvailableIfNeeded();
};

struct Document {
    Frame* frame();
};

struct Frame {
    Loader& loader();
};

struct Loader {
    void dispatchDocumentElementAvailable();
    void runScriptsAtDocumentElementAvailable();
};

#define ASSERT(expr) ((void)0)