#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <string>

struct String;
struct InterpretedCodeBlock;
struct Script;
struct ByteCodeBlock;
struct ASTClassInfo;
struct Error;
struct ByteCodeGenerator;
struct CodeCache;

struct CodeCacheEntry {
    // Add necessary members here
    int dummy;  // Placeholder member
};

struct CodeBlockCacheInfo {
    // Add necessary members here
    int dummy;  // Placeholder member
};

struct ProgramNode {
    void* moduleData();
    struct ScopeContext {
        bool m_hasEval;
        bool m_hasWith;
        bool m_isClassConstructor;
        bool m_isDerivedClassConstructor;
        bool m_isObjectMethod;
        bool m_isClassMethod;
        bool m_isClassStaticMethod;
        bool m_allowSuperCall;
        bool m_allowSuperProperty;
        bool m_allowArguments;
    };
    ScopeContext* scopeContext();
};

struct StringView {
    StringView(String* source, size_t start, size_t length);
};

struct Debugger {
    bool skipSourceCode(String* srcName);
};

struct ASTAllocator {
    bool isInitialized();
    void reset();
};

namespace esprima {
    struct Error {
        int errorCode;
        String* message;
    };
    ASTClassInfo* generateClassInfoFrom(void* context, InterpretedCodeBlock* parentCodeBlock);
    ProgramNode* parseProgram(void* context, StringView sourceView, ASTClassInfo* outerClassInfo, bool isModule, bool strictFromOutside, bool inWith, size_t stackSizeRemain, bool allowSC, bool allowSP, bool allowNewTarget, bool allowArguments);
}

#define ENABLE_CODE_CACHE
#define ESCARGOT_DEBUGGER
#define UNUSED_PARAMETER(x) (void)(x)
#define LIKELY(x) (x)
#define ASSERT(x)
#define NDEBUG

struct ScriptParser {
    struct InitializeScriptResult {
        Script* script;
        int parseErrorCode;
        String* parseErrorMessage;
    };

    struct Context {
        struct VMInstance {
            CodeCache* codeCache();
        };
        VMInstance* vmInstance();
        bool debuggerEnabled();
        Debugger* debugger();
        ASTAllocator& astAllocator();
    };

    Context* m_context;
    CodeBlockCacheInfo* m_codeBlockCacheInfo;

    InitializeScriptResult initializeScript(String* originSource, size_t originLineOffset, String* source, String* srcName, InterpretedCodeBlock* parentCodeBlock, bool isModule, bool isEvalMode, bool isEvalCodeInFunction, bool inWithOperation, bool strictFromOutside, bool allowSuperCall, bool allowSuperProperty, bool allowNewTarget, bool needByteCodeGeneration, size_t stackSizeRemain);
    void deleteCodeBlockCacheInfo();
    void setCodeBlockCacheInfo(CodeBlockCacheInfo* info);
    InterpretedCodeBlock* generateCodeBlockTreeFromASTWalker(Context* context, StringView sourceView, Script* script, ProgramNode::ScopeContext* scopeContext, InterpretedCodeBlock* parentCodeBlock, bool isEvalMode, bool isEvalCodeInFunction);
    InterpretedCodeBlock* generateCodeBlockTreeFromAST(Context* context, StringView sourceView, Script* script, ProgramNode* programNode, bool isEvalMode, bool isEvalCodeInFunction);
    void generateCodeBlockTreeFromASTWalkerPostProcess(InterpretedCodeBlock* topCodeBlock);
    InitializeScriptResult initializeScriptWithDebugger(String* originSource, size_t originLineOffset, String* source, String* srcName, InterpretedCodeBlock* parentCodeBlock, bool isModule, bool isEvalMode, bool isEvalCodeInFunction, bool inWithOperation, bool strictFromOutside, bool allowSuperCall, bool allowSuperProperty, bool allowNewTarget);
};

struct String {
    size_t length();
    size_t hashValue();
    std::string toUTF8StringData();
    static String* fromASCII(const char* str, size_t len);
};

struct InterpretedCodeBlock {
    bool inWith();
    bool allowSuperCall();
    bool allowSuperProperty();
    bool allowArguments();
    bool hasEval();
    bool hasWith();
    bool isClassConstructor();
    bool isDerivedClassConstructor();
    bool isObjectMethod();
    bool isClassMethod();
    bool isClassStaticMethod();
    bool isAsync();
    ByteCodeBlock* m_byteCodeBlock;
};

struct Script {
    Script(String* srcName, String* source, void* moduleData, bool hasParentCodeBlock, size_t originLineOffset);
    InterpretedCodeBlock* m_topCodeBlock;
};

struct CodeCache {
    bool enabled();
    std::pair<bool, CodeCacheEntry> searchCache(size_t srcHash);
    void prepareCacheLoading(ScriptParser::Context* context, size_t srcHash, CodeCacheEntry& entry);
    InterpretedCodeBlock* loadCodeBlockTree(ScriptParser::Context* context, Script* script);
    ByteCodeBlock* loadByteCodeBlock(ScriptParser::Context* context, InterpretedCodeBlock* topCodeBlock);
    bool postCacheLoading();
    void prepareCacheWriting(size_t srcHash);
    void storeCodeBlockTree(InterpretedCodeBlock* topCodeBlock, CodeBlockCacheInfo* cacheInfo);
    void postCacheWriting(size_t srcHash);
};

struct ByteCodeGenerator {
    static ByteCodeBlock* generateByteCode(ScriptParser::Context* context, InterpretedCodeBlock* topCodeBlock, ProgramNode* programNode, bool inWith, bool forCache);
};

#define CODE_CACHE_MIN_SOURCE_LENGTH 100

void GC_disable();
void GC_enable();

void ESCARGOT_LOG_INFO(const char* format, ...);

void dumpCodeBlockTree(InterpretedCodeBlock* topCodeBlock);

enum ErrorCode {
    SyntaxError
};