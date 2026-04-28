#include <vector>
#include <cstdint>

namespace IR {
    struct Module {};
}

namespace WAST {
    struct Error {};
    bool parseModule(const char* data, size_t size, IR::Module& outModule, std::vector<Error>& parseErrors);
}

namespace Log {
    enum Level { error };
    void printf(Level level, const char* format, ...);
}

bool loadFile(const char* filename, std::vector<uint8_t>& outBytes);
bool loadBinaryModule(const uint8_t* data, size_t size, IR::Module& outModule);
void reportParseErrors(const char* filename, const std::vector<WAST::Error>& parseErrors);

typedef uint8_t U8;
typedef uint32_t U32;