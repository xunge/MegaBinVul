#include <stdint.h>
#include <stdbool.h>

#define JS_OBJECT_MAX_ELEMENT_COUNT (1 << 29)

typedef enum {
    FAST_SMI_ELEMENTS,
    FAST_DOUBLE_ELEMENTS,
    FAST_ELEMENTS,
    FAST_HOLEY_SMI_ELEMENTS,
    FAST_HOLEY_DOUBLE_ELEMENTS,
    FAST_HOLEY_ELEMENTS,
    DICTIONARY_ELEMENTS,
    NO_ELEMENTS
} ElementsKind;

struct Object;
struct Arguments;
struct Isolate;
struct HandleScope;
struct JSArray;
struct FixedArrayBase;
struct FixedDoubleArray;
struct FixedArray;
struct Smi;
struct JSReceiver;
struct SeededNumberDictionary;
struct Map;
struct Factory;
struct Context;
struct Heap;
struct ArrayConcatVisitor;

template <typename T>
class Handle {
public:
    Handle() = default;
    Handle(T* obj, Isolate* isolate) {}
    T* operator->() { return nullptr; }
    T* operator*() { return nullptr; }
    template <typename U>
    static Handle<T> cast(Handle<U> obj) { return Handle<T>(); }
    operator Handle<Object>() const { return Handle<Object>(); }
};

template <typename T>
class Maybe {
public:
    Maybe() = default;
    Maybe(T value) {}
    bool IsNothing() { return false; }
    T FromJust() { return T(); }
};

template <typename T>
class MaybeHandle {
public:
    bool is_null() { return false; }
    Handle<T> ToHandleChecked() { return Handle<T>(); }
};

struct Arguments {
    int length() { return 0; }
    Object* operator[](int index) { return nullptr; }
};

struct Object {
    bool operator==(const Object& other) { return false; }
    bool IsJSArray() { return false; }
    bool IsHeapObject() { return false; }
    bool IsNumber() { return false; }
    bool IsSmi() { return false; }
    bool IsTheHole() { return false; }
    bool IsConstructor() { return false; }
    double Number() { return 0.0; }
    Object* length() { return nullptr; }
    static Object* cast(Object* obj) { return obj; }
};

struct FixedArrayBase : Object {};

struct JSArray : Object {
    ElementsKind GetElementsKind() { return FAST_SMI_ELEMENTS; }
    ElementsKind elements_kind() { return FAST_SMI_ELEMENTS; }
    Object* elements() { return nullptr; }
    Object* length() { return nullptr; }
    Map* map() { return nullptr; }
    void set_map(Map* map) {}
    void set_length(Object* length) {}
    void set_elements(Object* elements) {}
    static JSArray* cast(Object* obj) { return static_cast<JSArray*>(obj); }
};

struct FixedDoubleArray : FixedArrayBase {
    bool is_the_hole(uint32_t index) { return false; }
    double get_scalar(uint32_t index) { return 0.0; }
    void set(int index, double value) {}
    static FixedDoubleArray* cast(Object* obj) { return static_cast<FixedDoubleArray*>(obj); }
};

struct FixedArray : FixedArrayBase {
    Object* get(uint32_t index) { return nullptr; }
    static FixedArray* cast(Object* obj) { return static_cast<FixedArray*>(obj); }
};

struct Smi : Object {
    int32_t value() { return 0; }
    static Smi* FromInt(int value) { return nullptr; }
    static Smi* cast(Object* obj) { return static_cast<Smi*>(obj); }
};

struct Isolate {
    Context* context() { return nullptr; }
    Factory* factory() { return nullptr; }
    Heap* heap() { return nullptr; }
};

struct Factory {
    Handle<FixedArrayBase> NewFixedDoubleArray(uint32_t length) { return Handle<FixedArrayBase>(); }
    Handle<Object> NewFixedArrayWithHoles(uint32_t length) { return Handle<Object>(); }
    Handle<JSArray> NewJSArrayWithElements(Handle<FixedArrayBase> storage, ElementsKind kind, int length) { return Handle<JSArray>(); }
    Handle<JSArray> NewJSArray(int length) { return Handle<JSArray>(); }
};

struct Context {
    Object* array_function() { return nullptr; }
};

struct Heap {
    Object* exception() { return nullptr; }
};

struct Map {
    ElementsKind elements_kind() { return FAST_SMI_ELEMENTS; }
};

struct HandleScope {
    HandleScope(Isolate* isolate) {}
};

struct JSObject {
    static const uint32_t kMaxElementCount = JS_OBJECT_MAX_ELEMENT_COUNT;
    static Handle<Map> GetElementsTransitionMap(Handle<JSArray> array, ElementsKind kind) { return Handle<Map>(); }
};

ElementsKind GetPackedElementsKind(ElementsKind kind) { return kind; }
ElementsKind GetMoreGeneralElementsKind(ElementsKind a, ElementsKind b) { return a; }
uint32_t EstimateElementCount(Handle<JSArray> array) { return 0; }
Maybe<bool> IsConcatSpreadable(Isolate* isolate, Handle<Object> obj) { return Maybe<bool>(false); }
bool IterateElements(Isolate* isolate, Handle<JSReceiver> object, ArrayConcatVisitor* visitor) { return false; }

struct ArrayConcatVisitor {
    ArrayConcatVisitor(Isolate* isolate, Handle<Object> storage, bool fast_case) {}
    void visit(int index, Handle<Object> obj) {}
    void increase_index_offset(int amount) {}
    bool exceeds_array_limit() { return false; }
    Handle<Object> ToArray() { return Handle<Object>(); }
    Handle<Object> storage_jsreceiver() { return Handle<Object>(); }
};

struct SeededNumberDictionary {
    static Handle<Object> New(Isolate* isolate, uint32_t capacity) { return Handle<Object>(); }
};

struct Execution {
    static MaybeHandle<Object> New(Isolate* isolate, Handle<Object> constructor,
                                 Handle<Object> new_target, int argc,
                                 Handle<Object> argv[]) { return MaybeHandle<Object>(); }
};

struct MessageTemplate {
    static Object* kInvalidArrayLength;
};

struct NewRangeError {
    NewRangeError(Object* template_) {}
    operator Object*() { return nullptr; }
};

#define DCHECK(condition) ((void)0)
#define DCHECK_EQ(a, b) ((void)0)
#define UNREACHABLE() ((void)0)
#define MAYBE_RETURN(maybe, value) if ((maybe).IsNothing()) return (value)
#define ASSIGN_RETURN_FAILURE_ON_EXCEPTION(isolate, var, call) \
    do { \
        MaybeHandle<Object> maybe_result = (call); \
        if (maybe_result.is_null()) return (isolate)->heap()->exception(); \
        (var) = maybe_result.ToHandleChecked(); \
    } while (false)
#define THROW_NEW_ERROR_RETURN_FAILURE(isolate, call) return (call)