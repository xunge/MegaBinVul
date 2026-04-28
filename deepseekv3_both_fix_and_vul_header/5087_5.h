#include <vector>
#include <string>
#include <map>
#include <stdexcept>

using Index = size_t;

namespace wasm {
class Module {
public:
    std::vector<void*> functions;
    std::string start;
    struct Table {
        struct Segment {
            std::vector<std::string> data;
        };
        std::vector<Segment> segments;
    } table;
    
    void addFunction(void* func);
    void addExport(void* exp);
    void updateMaps();
};
extern Module wasm;
}

enum class ExternalKind {
    Function,
    Table,
    Memory,
    Global
};

struct Export {
    ExternalKind kind;
    std::string value;
};

struct Call {
    std::string target;
};

struct Name {
    static std::string fromInt(int);
};

class WasmBinaryBuilder {
public:
    void processFunctions();
    wasm::Module wasm;
};

std::string getFunctionIndexName(Index index);
std::string getGlobalName(Index index);
void throwError(const std::string&);

extern std::vector<void*> functions;
extern Index startIndex;
extern std::vector<Export*> exportOrder;
extern std::map<Export*, Index> exportIndexes;
extern std::map<size_t, std::vector<Call*>> functionCalls;
extern std::map<size_t, std::vector<Index>> functionTable;