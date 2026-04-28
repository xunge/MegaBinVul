#include <cassert>
#include <string>
#include <memory>

class Identifier {};
class Variable {};
class SourceRange {};

class Function {
public:
    enum class DefinitionKind { ES5Function };
    void setLazyClosureAlias(Variable*);
    void setLazyScope(void*);
    struct LazySource {
        int bufferId;
        int nodeKind;
        bool isGeneratorInnerFunction;
        SourceRange functionRange;
    };
    LazySource& getLazySource();
    void setExpectedParamCountIncludingThis(int);
};

class BasicBlock {};
class AllocStackInst {};
class Literal {};

class BuilderType {
public:
    Function* createGeneratorInnerFunction(Identifier, Function::DefinitionKind, bool, SourceRange, void*);
    Function* createFunction(Identifier, Function::DefinitionKind, bool, SourceRange, bool, void*);
    BasicBlock* createBasicBlock(Function*);
    void setInsertionBlock(BasicBlock*);
    void createStartGeneratorInst();
    AllocStackInst* createAllocStackInst(std::string);
    void createSaveAndYieldInst(Literal*, BasicBlock*);
    Literal* getLiteralUndefined();
};

namespace llvh {
    template<typename T, typename U>
    T* dyn_cast(U*);
}

namespace ESTree {
    class FunctionLikeNode {
    public:
        bool strictness;
        SourceRange getSourceRange();
        void* getSemInfo();
    };
    class BlockStatementNode {
    public:
        bool isLazyFunctionBody;
        int bufferId;
    };
    BlockStatementNode* getBlockStatement(FunctionLikeNode*);
    bool isStrict(bool);
};

class FunctionContext {
public:
    FunctionContext(class ESTreeIRGen*, Function*, void*);
};

enum class InitES5CaptureState { Yes };
enum class DoEmitParameters { Yes };

class ESTreeIRGen {
public:
    BuilderType Builder;
    void* saveCurrentScope();
    int getLazyFunctionKind(ESTree::FunctionLikeNode*);
    int countExpectedArgumentsIncludingThis(ESTree::FunctionLikeNode*);
    bool hasSimpleParams(ESTree::FunctionLikeNode*);
    void genResumeGenerator(void*, AllocStackInst*, BasicBlock*);
    void emitFunctionPrologue(ESTree::FunctionLikeNode*, BasicBlock*, InitES5CaptureState, DoEmitParameters);
    void genStatement(ESTree::BlockStatementNode*);
    void emitFunctionEpilogue(Literal*);
    std::string genAnonymousLabelName(const char*);
    struct CurrentFunction {
        Function* function;
    };
    CurrentFunction* curFunction();
    
    Function* genES5Function(
        Identifier originalName,
        Variable* lazyClosureAlias,
        ESTree::FunctionLikeNode* functionNode,
        bool isGeneratorInnerFunction);
};