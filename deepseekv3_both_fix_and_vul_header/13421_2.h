#include <string>
#include <cstdint>

class Runtime;
class CodeBlock;
class RuntimeModule;
class Bytecode;
class DebugInfo;
class StringPrimitive;
class HermesValue;

namespace llvh {
    class StringRef {
    public:
        bool empty() const;
    };
}

namespace hbc {
    struct DebugSourceLocation {
        uint32_t filenameId;
    };
}

template<typename T>
class OptValue {
    T value_;
    bool hasValue_;
public:
    OptValue() : hasValue_(false) {}
    OptValue(T value) : value_(value), hasValue_(true) {}
    explicit operator bool() const { return hasValue_; }
    const T& operator*() const { return value_; }
    const T* operator->() const { return &value_; }
};

template<typename T>
class CallResult {
public:
    CallResult(T value);
    operator T() const;
};

class StringPrimitive {
public:
    static CallResult<HermesValue> createEfficient(Runtime& runtime, const char* str);
    static CallResult<HermesValue> createEfficient(Runtime& runtime, llvh::StringRef str);
};

class HermesValue {
public:
    static HermesValue encodeUndefinedValue();
};

class CodeBlock {
public:
    RuntimeModule* getRuntimeModule() const;
};

class RuntimeModule {
public:
    Bytecode* getBytecode() const;
    llvh::StringRef getSourceURL() const;
};

class Bytecode {
public:
    bool isLazy() const;
    DebugInfo* getDebugInfo() const;
};

class DebugInfo {
public:
    const char* getFilenameByID(uint32_t id) const;
};