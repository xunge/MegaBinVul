#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <utility>

struct Block;
struct BinaryConsts {
    static const char Block;
};
const char BinaryConsts::Block = 0;

struct DebugLocation;
struct Function;

enum Type {
    none = 0
};

class WasmBinaryBuilder {
public:
    void visitBlock(Block* curr);
    
    bool debug;
    std::vector<char> input;
    size_t pos;
    std::vector<std::pair<std::string, bool>> breakStack;
    std::map<std::string, bool> breakTargetNames;
    std::vector<Block*> expressionStack;
    std::set<DebugLocation> debugLocation;
    Function* currFunction;
    
    struct Allocator {
        template<typename T>
        T* alloc();
    } allocator;
    
    Type getType();
    std::string getNextLabel();
    bool more();
    void readNextDebugLocation();
    void processExpressions();
    void pushBlockElements(Block* curr, size_t start, size_t end);
    void throwError(const char* msg);
};

struct Block {
    Type type;
    std::string name;
    void finalize(Type type, bool condition);
};

struct Function {
    std::map<Block*, DebugLocation> debugLocations;
};

struct DebugLocation {};