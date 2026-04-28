#include <stdint.h>
#include <stdbool.h>

namespace v8 {

class Object;
class Value;

class Isolate {
public:
    static Isolate* GetCurrent();
};

template<typename T> class Local {
public:
    T* operator->();
    bool IsEmpty() const;
    bool HasRealIndexedProperty(uint32_t index);
    Local<Object> FindInstanceInPrototypeChain(Local<Object> templateObj);
};

template<typename T> class Handle {
public:
    bool IsEmpty() const;
    bool HasRealIndexedProperty(uint32_t index);
    T* operator->();
    Handle(Local<T> local);
};

class Object {
public:
    bool HasRealIndexedProperty(uint32_t index);
    Local<Object> FindInstanceInPrototypeChain(Local<Object> templateObj);
};

enum AccessType {
    ACCESS_HAS,
    ACCESS_GET
};

}

class Frame;

class DOMWindow {
public:
    Frame* frame();
};

class Frame {
public:
    class Loader {
    public:
        class StateMachine {
        public:
            bool isDisplayingInitialEmptyDocument();
        };
        void didAccessInitialDocument();
        StateMachine* stateMachine();
    };
    class Tree {
    public:
        Frame* scopedChild(uint32_t index);
    };
    Loader* loader();
    Tree* tree();
};

class BindingSecurity {
public:
    static bool shouldAllowAccessToFrame(Frame*, bool);
};

enum WorldType {
    MainWorld
};

class V8Window {
public:
    static v8::Local<v8::Object> GetTemplate(v8::Isolate* isolate, WorldType worldType);
    static DOMWindow* toNative(v8::Handle<v8::Object> window);
    bool indexedSecurityCheckCustom(v8::Local<v8::Object> host, uint32_t index, v8::AccessType type, v8::Local<v8::Value>);
};

#define ASSERT(expr) ((void)0)
#define DoNotReportSecurityError false

WorldType worldTypeInMainThread(v8::Isolate* isolate);