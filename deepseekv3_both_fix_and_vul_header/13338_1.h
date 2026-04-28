#include <stdio.h>

enum class Result {
    Ok,
    Error
};

struct Location {
    enum Type {
        Binary
    };
};

struct Errors {};

void InitStdio();
void ParseOptions(int argc, char** argv);
Result Wasm2cMain(Errors& errors);
Result wasm2c(Errors& errors);
void FormatErrorsToFile(Errors& errors, Location::Type type);