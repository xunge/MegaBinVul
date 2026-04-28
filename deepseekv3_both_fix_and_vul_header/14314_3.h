#include <vector>
#include <string>
#include <map>
#include <iostream>

#define BYN_TRACE(x) std::cout << x

class Block;
class WasmBinaryBuilder;

class Block {
public:
    std::string type;
    std::string name;
    std::map<Block*, Block*> debugLocations;
    enum BreakType { HasBreak, NoBreak };
    void finalize(std::string type, BreakType breakType);
};

class Allocator {
public:
    template<typename T> T* alloc() { return new T(); }
};

class WasmBinaryBuilder {
public:
    void visitBlock(Block* curr);
private:
    Allocator allocator;
    std::vector<std::pair<std::string, std::string>> breakStack;
    std::map<std::string, bool> breakTargetNames;
    std::vector<Block*> expressionStack;
    std::vector<Block*> debugLocation;
    Block* currFunction;
    size_t pos;
    const char* input;
    
    std::string getType();
    std::string getNextLabel();
    bool more();
    void readNextDebugLocation();
    void requireFunctionContext(const char* msg);
    void startControlFlow(Block* curr);
    void pushExpression(Block* block);
    void processExpressions();
    void pushBlockElements(Block* curr, std::string type, size_t start);
    void throwError(const char* msg);
};

namespace BinaryConsts {
    const char Block = 0;
}