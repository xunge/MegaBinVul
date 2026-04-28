#include <cstdint>
#include <stdexcept>
#include <string>

namespace BinaryConsts {
namespace EncodedType {
const int Empty = 0;
const int i32 = 1;
const int i64 = 2;
const int f32 = 3;
const int f64 = 4;
const int v128 = 5;
const int AnyFunc = 6;
const int Func = 7;
}
}

enum Type {
    none,
    i32,
    i64,
    f32,
    f64,
    v128
};

class WasmBinaryBuilder {
public:
    int getS32LEB();
    void throwError(const std::string& msg);
    Type getType();
};

#define WASM_UNREACHABLE() abort()