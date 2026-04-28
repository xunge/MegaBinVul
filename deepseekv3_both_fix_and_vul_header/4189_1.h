#include <stdbool.h>

struct DisallowHeapAllocation {};
struct Map {
    struct Object* prototype();
};
struct Object {
    bool IsJSArray();
};
struct JSArray {
    static JSArray* cast(Object* obj);
    Map* map();
};
struct Isolate {
    bool is_initial_array_prototype(JSArray* proto);
    bool IsFastArrayConstructorPrototypeChainIntact();
};
struct PrototypeIterator {
    PrototypeIterator(Isolate* isolate, JSArray* receiver);
};
bool PrototypeHasNoElements(PrototypeIterator* iter);