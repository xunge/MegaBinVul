#include <cassert>

#define ASSERT(expr) assert(expr)

enum LoadEventProgress {
    LoadEventNotRun,
    LoadEventInProgress, 
    UnloadEventInProgress
};

enum DismissalType {
    NoDismissal
};

const bool ForceSynchronousParsing = true;

class Frame;
class ScriptableDocumentParser;
class DocumentLoader;

class Frame {
public:
    class Loader {
    public:
        DocumentLoader* provisionalDocumentLoader();
        void stopAllLoaders();
        void didExplicitOpen();
    };
    
    Loader& loader() { return m_loader; }
private:
    Loader m_loader;
};

class ScriptableDocumentParser {
public:
    bool isParsing();
    bool isExecutingScript();
    bool wasCreatedByScript();
    bool hasInsertionPoint();
    void setWasCreatedByScript(bool);
};

class Document {
public:
    Frame* m_frame;
    LoadEventProgress m_loadEventProgress;

    bool importLoader();
    ScriptableDocumentParser* scriptableDocumentParser();
    void removeAllEventListenersRecursively();
    void implicitOpen(bool);
    DismissalType pageDismissalEventBeingDispatched();
    void open();
};