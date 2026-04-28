#include <stddef.h>
#include <vector>

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr = nullptr);
    T* get() const;
    T* operator->() const;
    T* release();
    bool operator!=(const T* other) const;
    bool operator!=(const RefPtr<T>& other) const;
    bool operator==(const T* other) const;
    bool operator==(const RefPtr<T>& other) const;
    operator bool() const;
    bool operator!() const;
};

class Node {
public:
    bool isRootEditableElement() const;
    Node* parentNode() const;
    bool isElementNode() const;
    bool inDocument() const;
    bool isDescendantOf(const Node*) const;
    Node* cloneNode(bool deep) const;
};

class Element : public Node {
};

class Position {
public:
    Node* deprecatedNode() const;
};

class NodeTraversal {
public:
    static Node* nextSkippingChildren(const Node*, const Node*);
};

template<typename T> class Vector {
public:
    void append(T);
    size_t size() const;
    T operator[](size_t) const;
};

class CompositeEditCommand {
public:
    void cloneParagraphUnderNewElement(Position& start, Position& end, Node* passedOuterNode, Element* blockElement);
};

void appendNode(RefPtr<Node>, Element*);
void insertNodeAfter(RefPtr<Node>, RefPtr<Node>);
bool isTableElement(Node*);
Element* toElement(RefPtr<Node>);

template<typename T>
bool operator!=(const T* lhs, const RefPtr<T>& rhs) {
    return rhs != lhs;
}