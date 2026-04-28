#include <string>
#include <cstdlib>
#include <cxxabi.h>
#include <cstdint>

class Backtrace {
public:
    std::string GetFunctionName(uintptr_t pc, uintptr_t* offset);
    std::string GetFunctionNameRaw(uintptr_t pc, uintptr_t* offset);
};

using namespace __cxxabiv1;