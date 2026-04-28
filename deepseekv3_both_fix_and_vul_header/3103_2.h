#include <stdbool.h>
#include <stdint.h>

#define ASSERT(expr) ((void)0)

typedef struct Parser {
    bool isParsing();
} Parser;

typedef struct DocumentTiming {
    double domContentLoadedEventStart;
    double domContentLoadedEventEnd;
} DocumentTiming;

typedef struct EventNames {
    const char* DOMContentLoadedEvent;
    EventNames();
} EventNames;

typedef struct Event {
    static Event* create(const char*, bool, bool);
} Event;

typedef struct FrameLoader {
    void finishedParsing();
} FrameLoader;

typedef struct Frame {
    FrameLoader* loader();
} Frame;

template<typename T>
struct RefPtr {
    T* operator->();
    T* get();
    operator bool();
    RefPtr(T*);
};

typedef struct InspectorInstrumentation {
    static void domContentLoadedEventFired(Frame*);
} InspectorInstrumentation;

typedef struct Timer {
    void startOneShot(int);
} Timer;

typedef struct CachedResourceLoader {
    void clearPreloads();
} CachedResourceLoader;

enum ReadyState { Loading };

class Document {
public:
    void finishedParsing();
    bool scriptableDocumentParser();
    void setParsing(bool);
    void dispatchEvent(Event*);
    RefPtr<Frame> frame();
    void updateStyleIfNeeded();

    Parser* m_parser;
    ReadyState m_readyState;
    DocumentTiming m_documentTiming;
    Timer m_sharedObjectPoolClearTimer;
    CachedResourceLoader* m_cachedResourceLoader;
    EventNames eventNames();
};

double monotonicallyIncreasingTime();