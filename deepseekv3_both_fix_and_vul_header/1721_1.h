#include <stdint.h>
#include <stddef.h>

enum class ExecutionStatus {
    EXCEPTION,
    RETURNED
};

template<typename T>
class CallResult {
public:
    CallResult(T value) : value_(value) {}
    CallResult(ExecutionStatus status) : status_(status) {}
private:
    union {
        T value_;
        ExecutionStatus status_;
    };
};

class Runtime {};
class Callable {
public:
    virtual ~Callable() = default;
};

class BoundFunction : public Callable {
public:
    Callable* getTarget(Runtime&);
};

class JSFunction : public Callable {
public:
    class CodeBlock {
    public:
        ExecutionStatus lazyCompile(Runtime&);
        struct HeaderFlags {
            bool isCallProhibited(bool);
        };
        HeaderFlags getHeaderFlags();
    };
    CodeBlock* getCodeBlock(Runtime&);
};

class NativeFunction : public Callable {};
class NativeConstructor : public Callable {};
class JSCallableProxy : public Callable {
public:
    CallResult<bool> isConstructor(Runtime&);
};

template<typename T>
T* dyn_vmcast(Callable* ptr) {
    return dynamic_cast<T*>(ptr);
}

template<typename T>
bool vmisa(Callable* ptr) {
    return dynamic_cast<T*>(ptr) != nullptr;
}

#define LLVM_UNLIKELY(x) (x)