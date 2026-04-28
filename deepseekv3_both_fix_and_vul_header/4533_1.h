#include <stddef.h>

#define ASSERT(expr) ((void)0)
#define ASSERT_WITH_SECURITY_IMPLICATION(expr) ((void)0)
#define ENABLE(OILPAN) 0

class TreeScope;

class Node {
public:
    bool isDocumentNode();
    bool m_deletionHasBegun;
};

class TreeScopeAdopter {
public:
    TreeScopeAdopter(Node&, TreeScope&);
    bool needsScopeChange();
    void execute();
};

class ScriptForbiddenScope {
public:
    ScriptForbiddenScope();
    ~ScriptForbiddenScope();
};

class TreeScope {
public:
    void adoptIfNeeded(Node& node);
};