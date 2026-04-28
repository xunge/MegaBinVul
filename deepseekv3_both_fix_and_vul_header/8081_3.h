#include <stdbool.h>

enum ReferrerPolicy {
    ReferrerPolicyDefault
};

class Document;

struct Settings {
    bool doHtmlPreloadScanning() const;
    bool viewportMetaZeroValuesQuirk() const;
    bool viewportMetaEnabled() const;
};

class Frame {
public:
    bool isMainFrame() const;
};

class Document {
public:
    Settings* settings() const;
    Frame* frame() const;
    int viewportDefaultMinWidth() const;
    ReferrerPolicy getReferrerPolicy() const;
};

class CachedDocumentParameters {
public:
    bool doHtmlPreloadScanning;
    bool doDocumentWritePreloadScanning;
    int defaultViewportMinWidth;
    bool viewportMetaZeroValuesQuirk;
    bool viewportMetaEnabled;
    ReferrerPolicy referrerPolicy;
    CachedDocumentParameters(Document* document);
};

bool isMainThread();
void ASSERT(bool condition);