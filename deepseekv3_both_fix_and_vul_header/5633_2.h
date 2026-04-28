#include <memory>

class ScriptForbiddenScope {
public:
    ScriptForbiddenScope() {}
    ~ScriptForbiddenScope() {}
};

class ContainerNode;

class Node {
public:
    virtual ~Node() {}
    virtual ContainerNode* parentNode() const { return nullptr; }
    virtual void parserInsertBefore(Node* newChild, Node& refChild) {}
    virtual void parserAppendChild(Node* newChild) {}
};

class ContainerNode : public Node {
public:
    void parserRemoveChild(Node& child) {}
};

class HTMLTemplateElement : public ContainerNode {
public:
    std::unique_ptr<Node> content() { return nullptr; }
};

struct HTMLConstructionSiteTask {
    std::unique_ptr<Node> parent;
    std::unique_ptr<Node> child;
    Node* nextChild;
};

inline bool isHTMLTemplateElement(const Node&) { return false; }
inline HTMLTemplateElement* toHTMLTemplateElement(Node* node) { return nullptr; }