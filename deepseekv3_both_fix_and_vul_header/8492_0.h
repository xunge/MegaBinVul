#include <utility>
#include <vector>

class VariableProxy;
class Variable;
class Scope;

struct Rewriter {
    Scope* old_scope_;
    Scope* new_scope_;
    std::vector<std::pair<Variable*, int>> temps_;
    
    void VisitVariableProxy(VariableProxy* proxy);
};

enum VariableMode { TEMPORARY };

class Variable {
public:
    VariableMode mode();
    Scope* scope();
};

class Scope {
public:
    Scope* ClosureScope();
    int RemoveTemporary(Variable* var);
    bool RemoveUnresolved(VariableProxy* proxy);
    void AddUnresolved(VariableProxy* proxy);
};

class VariableProxy {
public:
    bool is_resolved();
    Variable* var();
};