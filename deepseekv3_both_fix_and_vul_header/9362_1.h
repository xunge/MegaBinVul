#include <string>

class v8 {
public:
    template<typename T>
    class Handle {
    };

    class Object {
    };

    class Isolate {
    };
};

class Event {
public:
    std::string interfaceName();
};

class String {
public:
    String(const std::string&);
};

#define ASSERT(expr)
#define ASSERT_NOT_REACHED()
#define EVENT_MODULES_INTERFACES_FOR_EACH(macro)
#define TRY_TO_WRAP_WITH_INTERFACE(interfaceName)