#include <stdbool.h>
#include <assert.h>

#define DCHECK(condition) assert(condition)
#define UNREACHABLE() assert(false && "Unreachable code")

template<typename T>
class Handle {
public:
    explicit Handle(T* object) : object_(object) {}
    T* operator->() const { return object_; }
    T* operator*() const { return object_; }
private:
    T* object_;
};

template<typename T>
Handle<T> handle(T* object, void* isolate) {
    return Handle<T>(object);
}

class Object;
class Map;

enum LanguageMode { SLOPPY, STRICT };
enum StoreFromKeyed { NORMAL, KEYED };
enum ShouldThrow { DONT_THROW, THROW_ON_ERROR };
enum PropertyAttributes { ABSENT, READ_ONLY };

template <typename T>
struct Maybe {
    bool IsJust() const { return true; }
    bool IsNothing() const { return !IsJust(); }
    T FromJust() const { return T(); }
    static Maybe<T> Nothing() { return Maybe<T>(); }
    static Maybe<T> Just(T value) { return Maybe<T>(value); }
private:
    Maybe() {}
    Maybe(T value) {}
};

template <typename T>
Maybe<T> Nothing() { return Maybe<T>::Nothing(); }

template <typename T>
Maybe<T> Just(T value) { return Maybe<T>::Just(value); }

class LookupIterator {
public:
    enum State {
        NOT_FOUND,
        ACCESS_CHECK,
        JSPROXY,
        INTERCEPTOR,
        ACCESSOR,
        INTEGER_INDEXED_EXOTIC,
        DATA,
        TRANSITION
    };
    
    void UpdateProtector() {}
    bool IsFound() const { return true; }
    State state() const { return NOT_FOUND; }
    bool HasAccess() const { return true; }
    void Next() {}
    bool IsReadOnly() const { return false; }
    bool HolderIsReceiverOrHiddenPrototype() const { return true; }
    bool IsElement() const { return false; }
    void* isolate() const { return nullptr; }
    void* GetHolder() const { return nullptr; }
    void* GetName() const { return nullptr; }
    void* GetReceiver() const { return nullptr; }
    Object* GetStoreTarget() const { return nullptr; }
    Handle<Object> GetAccessors() const { return Handle<Object>(nullptr); }
    template <typename T> T* GetHolder() const { return nullptr; }
};

class Object {
public:
    Map* map() const { return nullptr; }
    bool IsAccessorInfo() const { return false; }
    static Maybe<bool> SetPropertyInternal(LookupIterator* it,
                                         Handle<Object> value,
                                         LanguageMode language_mode,
                                         StoreFromKeyed store_mode,
                                         bool* found);
};

class Map {};

class JSObject {
public:
    static Maybe<bool> SetPropertyWithInterceptor(LookupIterator* it, ShouldThrow should_throw, Handle<Object> value) { return Just(true); }
    static Maybe<PropertyAttributes> GetPropertyAttributesWithInterceptor(LookupIterator* it) { return Just(ABSENT); }
    static Maybe<bool> SetPropertyWithFailedAccessCheck(LookupIterator* it, Handle<Object> value, ShouldThrow should_throw) { return Just(true); }
};

class JSProxy {
public:
    static Maybe<bool> SetProperty(void* holder, void* name, Handle<Object> value, void* receiver, LanguageMode language_mode) { return Just(true); }
};

class AccessorInfo {
public:
    bool is_special_data_property() const { return false; }
    static AccessorInfo* cast(Object* object) { return nullptr; }
};

class Utils {
public:
    static void ApiCheck(bool condition, const char* api, const char* message) {}
};

class AssertNoContextChange {
public:
    AssertNoContextChange(void* isolate) {}
};

bool is_sloppy(LanguageMode mode) { return mode == SLOPPY; }
Maybe<bool> WriteToReadOnlyProperty(LookupIterator* it, Handle<Object> value, ShouldThrow should_throw) { return Just(true); }
Maybe<bool> SetPropertyWithAccessor(LookupIterator* it, Handle<Object> value, ShouldThrow should_throw) { return Just(true); }
Maybe<bool> SetDataProperty(LookupIterator* it, Handle<Object> value) { return Just(true); }