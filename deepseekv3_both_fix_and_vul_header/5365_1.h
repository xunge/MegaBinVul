#include <stddef.h>

#define ENABLE(OILPAN) 1

struct Visitor {
    void trace(void*);
};

struct TreeScope;
struct Node;
struct EventTarget;
struct EventPath;
struct TouchEventContext;

class TreeScopeEventContext {
public:
    void trace(Visitor* visitor);

    TreeScope* m_treeScope;
    Node* m_rootNode;
    EventTarget* m_target;
    EventTarget* m_relatedTarget;
    EventPath* m_eventPath;
    TouchEventContext* m_touchEventContext;
    void* m_children;
};