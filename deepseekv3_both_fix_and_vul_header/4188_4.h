#include <stdbool.h>
#include <assert.h>

template<typename T> class Maybe;

class Symbol;

struct Isolate {
    struct Factory {
        Symbol* is_concat_spreadable_symbol();
    };
    Factory* factory();
    bool IsFastArrayConstructorPrototypeChainIntact();
};

template<typename T>
class Handle {
public:
    Handle(T* ptr);
};

class JSArray {};

class JSReceiver {
public:
    static Maybe<bool> HasProperty(Handle<JSArray> obj, Handle<Symbol> key);
};

template<typename T>
class Maybe {
public:
    Maybe(T value);
    T FromMaybe(T default_value);
};

#define DCHECK(condition) assert(condition)