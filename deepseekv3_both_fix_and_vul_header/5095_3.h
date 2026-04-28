#include <vector>
#include <string>
#include <stdexcept>
#include <unordered_map>

using Index = size_t;
enum class ExternalKind { Function, Table, Memory, Global };

class Name {
public:
    static std::string fromInt(int);
};

class Export {
public:
    ExternalKind kind;
    std::string value;
};

class FunctionCall {
public:
    std::string target;
};

class Function {};

class Wasm {
public:
    std::vector<Function*> functions;
    std::string start;
    void addFunction(Function*);
    void addExport(Export*);
    void updateMaps();
    struct Table {
        struct Segment {
            std::vector<std::string> data;
        };
        std::vector<Segment> segments;
    } table;
};

class WasmBinaryBuilder {
public:
    void processFunctions();
private:
    std::vector<Function*> functions;
    Index startIndex;
    std::vector<Export*> exportOrder;
    std::unordered_map<Export*, Index> exportIndexes;
    std::unordered_map<size_t, std::vector<FunctionCall*>> functionCalls;
    std::unordered_map<size_t, std::vector<Index>> functionTable;
    Wasm wasm;

    std::string getFunctionIndexName(Index);
    std::string getGlobalName(Index);
    void throwError(const std::string&);
};