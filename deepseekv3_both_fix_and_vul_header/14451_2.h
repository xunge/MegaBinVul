#include <stdint.h>
#include <string>
#include <stdexcept>
#include <cassert>

#define BYN_TRACE(x)

struct Name {
    std::string str;
    bool operator==(const Name& other) const { return str == other.str; }
    bool operator!=(const Name& other) const { return str != other.str; }
};

struct U32LEB {};

struct Rethrow {
    Name target;
    void finalize() {}
};

class WasmBinaryBuilder {
public:
    void visitRethrow(Rethrow* curr);
    Name getExceptionTargetName(U32LEB);
    U32LEB getU32LEB();
    void throwError(const std::string&);
};

static const Name DELEGATE_CALLER_TARGET;