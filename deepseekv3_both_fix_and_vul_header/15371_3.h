#include <stdbool.h>

struct Environment;
struct EnvironmentRecord;
struct DeclarativeEnvironmentRecord;
struct FunctionEnvironmentRecord;
struct ScriptGeneratorFunctionObject;
struct ScriptAsyncFunctionObject;
struct ScriptAsyncGeneratorFunctionObject;
struct RareData;

struct ExecutionState {
    bool isLocalEvalCode();
    ExecutionState* parent();
    bool hasRareData();
    RareData* rareData();
    Environment* lexicalEnvironment();
    bool inPauserScope();
};

struct Environment {
    EnvironmentRecord* record();
};

struct EnvironmentRecord {
    bool isGlobalEnvironmentRecord();
    bool isModuleEnvironmentRecord();
    bool isDeclarativeEnvironmentRecord();
    DeclarativeEnvironmentRecord* asDeclarativeEnvironmentRecord();
};

struct DeclarativeEnvironmentRecord {
    bool isFunctionEnvironmentRecord();
    FunctionEnvironmentRecord* asFunctionEnvironmentRecord();
};

struct FunctionEnvironmentRecord {
    ScriptGeneratorFunctionObject* functionObject();
};

struct ScriptGeneratorFunctionObject {
    bool isScriptGeneratorFunctionObject();
    bool isScriptAsyncFunctionObject();
    bool isScriptAsyncGeneratorFunctionObject();
};

struct RareData {
    bool m_pauseSource;
};