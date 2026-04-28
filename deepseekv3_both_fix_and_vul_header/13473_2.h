#include <stddef.h>
#include <stdint.h>

typedef size_t Index;

enum Result {
    Ok,
    Error
};

enum Opcode {
    Invalid,
    End
};

struct State {
    size_t offset;
};

struct BinaryReader {
    State state_;
    size_t read_end_;
    Result ReadInstructions(bool, size_t, Opcode*);
    Result ReadInitExpr(Index index);
};

#define CHECK_RESULT(expr) (expr)
#define ERROR_UNLESS(cond, msg) if (!(cond)) return Error;