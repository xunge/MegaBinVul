#include <cassert>
#include <string>
#include <initializer_list>

class Identifier {
public:
    bool isValid() const;
    std::string str() const;
};

class Variable;

namespace ESTree {
class FunctionLikeNode {
public:
    int strictness;
    void* getSemInfo() const;
    bool hasSimpleParams() const;
};
bool isStrict(int strictness);
}

class Function {
public:
    enum class DefinitionKind { ES5Function };
};

class Value;
class BasicBlock;

class BuilderType {
public:
    Function* createGeneratorFunction(Identifier, Function::DefinitionKind, bool, void*);
    Value* createCreateGeneratorInst(Function*);
    Value* createLoadPropertyInst(Value*, const char*);
    void createCallInst(Value*, Value*, std::initializer_list<Value*>);
    BasicBlock* createBasicBlock(Function*);
};
extern BuilderType Builder;

enum class InitES5CaptureState { Yes };
enum class DoEmitParameters { No };

class ESTreeIRGen {
public:
    Function* genGeneratorFunction(Identifier, Variable*, ESTree::FunctionLikeNode*);
    Function* genES5Function(std::string, Variable*, ESTree::FunctionLikeNode*, bool);
    std::string genAnonymousLabelName(const std::string&);
    void emitFunctionPrologue(ESTree::FunctionLikeNode*, BasicBlock*, InitES5CaptureState, DoEmitParameters);
    void emitFunctionEpilogue(Value*);
    bool hasSimpleParams(ESTree::FunctionLikeNode*);
};

struct FunctionContext {
    FunctionContext(ESTreeIRGen*, Function*, void*);
};