#include <stdint.h>

enum class ExecutionStatus {
    EXCEPTION
};

template<typename T>
class Handle;

template<typename T>
class CallResult {
public:
    CallResult() = default;
    CallResult(const T& value) : value_(value) {}
    CallResult(ExecutionStatus status) : status_(status) {}
    operator bool() const { return status_ == ExecutionStatus::EXCEPTION; }
    T operator*() const { return value_; }
    T get() const { return value_; }
    bool operator==(ExecutionStatus status) const { return status_ == status; }
private:
    T value_;
    ExecutionStatus status_ = ExecutionStatus::EXCEPTION;
};

class HermesValue {
public:
    HermesValue() = default;
    operator bool() const { return false; }
};

class Runtime {
public:
    enum class StackOverflowKind {
        NativeStack
    };
    CallResult<HermesValue> raiseStackOverflow(StackOverflowKind kind);
    CallResult<HermesValue> raiseTypeError(const char* msg);
    CallResult<HermesValue> raiseTypeErrorForValue(HermesValue value, const char* msg);
};

template<typename T>
class Handle {
public:
    Handle() = default;
    explicit Handle(T* ptr) : ptr_(ptr) {}
    explicit Handle(const T* ptr) : ptr_(const_cast<T*>(ptr)) {}
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }
    explicit operator bool() const { return ptr_ != nullptr; }
    bool operator!() const { return ptr_ == nullptr; }
private:
    T* ptr_ = nullptr;
};

class NativeArgs {
public:
    template<typename T>
    Handle<T> dyncastArg(int index) { return Handle<T>(static_cast<T*>(nullptr)); }
    HermesValue getArg(int index);
    int getArgCount() const;
    HermesValue getArgHandle(int index);
};

class GCScopeMarkerRAII {
public:
    GCScopeMarkerRAII(Runtime* runtime);
};

class Callable {
public:
    static CallResult<HermesValue> createThisForConstruct(Handle<Callable> fn, Runtime* runtime);
    static CallResult<HermesValue> construct(Handle<Callable> fn, Runtime* runtime, Handle<HermesValue> thisVal);
    static CallResult<HermesValue> call(Handle<Callable> fn, Runtime* runtime);
};

class JSArray {
public:
    static uint32_t getLength(const JSArray& array);
    HermesValue at(Runtime* runtime, uint32_t index) const;
};

template<typename T = HermesValue>
class MutableHandle {
public:
    MutableHandle(Runtime* runtime);
    void operator=(const T& value);
    T getHermesValue() const;
    operator Handle<T>() const { return Handle<T>(&value_); }
private:
    mutable T value_;
};

class ScopedNativeCallFrame {
public:
    ScopedNativeCallFrame(Runtime* runtime, uint32_t len, Callable& fn, bool isConstructor, HermesValue thisVal);
    bool overflowed() const;
    class Frame {
    public:
        HermesValue& getArgRef(uint32_t index);
    };
    Frame* operator->();
};

#define LLVM_UNLIKELY(x) (x)