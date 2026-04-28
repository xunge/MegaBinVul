#include <string>

namespace v8 {
class Object;
class Isolate;
template <class T> class Handle {
public:
    bool IsEmpty() const;
};
}

class Event {
public:
    std::string interfaceName();
};

class EventNames {
public:
    static const std::string Event;
};

class V8Event {
public:
    static v8::Handle<v8::Object> createWrapper(Event* event, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate);
};

class ModuleProxy {
public:
    static ModuleProxy& moduleProxy();
    v8::Handle<v8::Object> wrapForEvent(Event* event, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate);
};

typedef std::string String;

#define ASSERT(condition) ((void)0)
#define EVENT_INTERFACES_FOR_EACH(macro)
#define TRY_TO_WRAP_WITH_INTERFACE(interfaceName)