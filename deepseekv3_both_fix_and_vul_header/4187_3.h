#include <stdint.h>

#define STATIC_ASSERT(condition) ((void)0)
#define USE(x) ((void)(x))
#define DCHECK(condition) ((void)0)
#define THROW_NEW_ERROR(isolate, error, type) MaybeHandle<type>()

const int kBitsPerInt = sizeof(int) * 8;
const int kHalfOfMaxInt = 1 << (kBitsPerInt - 2);

template<typename T>
class Handle {
public:
    Handle(T* obj, void* isolate) {}
    T* operator->() { return nullptr; }
    T* operator*() { return nullptr; }
};

template <typename T>
class MaybeHandle {
public:
    MaybeHandle() {}
    explicit MaybeHandle(T* obj) {}
};

class Object;
class JSArray;
class JSObject;
class Smi;

class Isolate {
public:
    bool IsFastArrayConstructorPrototypeChainIntact() { return false; }
    class ArrayFunction {
    public:
        Object* prototype() { return nullptr; }
    };
    ArrayFunction* array_function() { return nullptr; }
};

class Arguments {
public:
    int length() { return 0; }
    Object* operator[](int) { return nullptr; }
};

class Object {
public:
    bool IsJSArray() { return false; }
};

class JSArray : public Object {
public:
    static JSArray* cast(Object* obj) { return nullptr; }
    bool HasFastElements() { return false; }
    Object* length() { return nullptr; }
};

class JSObject : public Object {
public:
    static JSObject* cast(Object* obj) { return nullptr; }
    bool HasFastElements() { return false; }
};

class Smi {
public:
    static Smi* cast(Object* obj) { return nullptr; }
    int value() { return 0; }
};

class FixedArray {
public:
    static const int kMaxLength = 0;
};

class PrototypeIterator {
public:
    PrototypeIterator(Isolate* isolate, JSArray* array) {}
    Object* GetCurrent() { return nullptr; }
};

class ElementsAccessor {
public:
    static MaybeHandle<JSArray> Concat(Isolate* isolate, Arguments* args, int n) { return MaybeHandle<JSArray>(); }
};

enum MessageTemplate {
    kInvalidArrayLength
};

class DisallowHeapAllocation {
public:
    DisallowHeapAllocation() {}
};

MaybeHandle<JSArray> NewRangeError(MessageTemplate);
bool HasOnlySimpleReceiverElements(Isolate*, JSObject*);
bool HasConcatSpreadableModifier(Isolate*, Handle<JSArray>);