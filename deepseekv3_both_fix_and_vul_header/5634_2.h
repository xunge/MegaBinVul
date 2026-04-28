#include <assert.h>
#include <stddef.h>

struct ContainerNode;
struct Node {
    ContainerNode* parentNode();
};

struct ContainerNode {
    Node* parentNode();
    void parserRemoveChild(Node&);
    void parserAppendChild(Node*);
};

struct ScriptForbiddenScope {
    ScriptForbiddenScope() {}
    ~ScriptForbiddenScope() {}
};

struct HTMLConstructionSiteTask {
    enum Operation { Reparent };
    Operation operation;
    ContainerNode* parent;
    Node* child;
};

#define ASSERT assert