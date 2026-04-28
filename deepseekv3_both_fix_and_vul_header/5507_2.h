#include <cassert>
#include <cstddef>

class Platform {
public:
    static Platform* current();
    bool currentThread();
};

class TaskRunner {
public:
    virtual ~TaskRunner() {}
};

class Interruptor {
public:
    virtual ~Interruptor() {}
};

extern TaskRunner* s_endOfTaskRunner;
extern Interruptor* s_isolateInterruptor;
extern TaskRunner* s_pendingGCRunner;
extern Interruptor* s_messageLoopInterruptor;

namespace v8 {
    class Isolate;
}

class V8PerIsolateData {
public:
    static v8::Isolate* mainThreadIsolate();
    static void willBeDestroyed(v8::Isolate*);
    static void destroy(v8::Isolate*);
};

class ThreadState {
public:
    static ThreadState* current();
    void removeInterruptor(Interruptor*);
    static void detachMainThread();
};

class ScriptStreamerThread {
public:
    static void shutdown();
};

class WorkerThread {
public:
    static void terminateAndWaitForAllWorkers();
};

class ModulesInitializer {
public:
    static void terminateThreads();
};

void shutdownWithoutV8();

#define ASSERT(x) assert(x)