#include <cstdint>
#include <limits>
#include <optional>
#include <cassert>

class VariableScope {
public:
    const char* getLocation();
};

class HBCResolveEnvironment {
public:
    VariableScope* getScope();
    const char* getLocation();
};

class BasicBlock;

template <typename T>
class Optional {
public:
    explicit operator bool() const { return hasValue(); }
    bool hasValue() const { return false; }
    const T& getValue() const { return value_; }
private:
    T value_;
};

class HBCISel {
public:
    void generateHBCResolveEnvironment(HBCResolveEnvironment *Inst, BasicBlock *next);

protected:
    class ScopeAnalysis {
    public:
        Optional<int32_t> getScopeDepth(VariableScope *scope);
    } scopeAnalysis_;

    class Function {
    public:
        VariableScope *getFunctionScope();
        class Context {
        public:
            class SourceErrorManager {
            public:
                void error(const char *location, const char *message);
            };
            SourceErrorManager &getSourceErrorManager();
        };
        Context &getContext();
    } *F_;

    class BCFGen {
    public:
        void emitGetEnvironment(uint32_t encodedValue, int32_t delta);
    } *BCFGen_;

    uint32_t encodeValue(HBCResolveEnvironment *Inst);
    void emitUnreachableIfDebug();
};