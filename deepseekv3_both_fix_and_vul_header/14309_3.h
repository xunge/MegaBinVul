#include <stdint.h>
#include <string>

struct RefAs;

enum BinaryConsts {
    RefAsNonNull,
    RefAsFunc,
    RefAsData,
    RefAsI31
};

struct Type {
    bool isRef() const;
    static const Type unreachable;
    std::string toString() const;
    bool operator!=(const Type& other) const;
};

struct Expression {
    Type type;
};

class WasmBinaryBuilder {
public:
    void visitRefAs(RefAs* curr, uint8_t code);
    Expression* popNonVoidExpression();
    void throwError(const std::string& msg);
};

struct RefAs {
    int op;
    Expression* value;
    void finalize();
};

#define BYN_TRACE(x)
#define WASM_UNREACHABLE(x) throwError(x)