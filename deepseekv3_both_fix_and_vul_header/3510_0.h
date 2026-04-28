#include <cstdint>

class ContainerNode {
public:
    bool inDocument();
};

class Element {
public:
    virtual ~Element() = default;
};

class HTMLFrameElementBase : public Element {
public:
    int marginWidth();
    int marginHeight();
};

class HTMLElement : public Element {
public:
    void insertedInto(ContainerNode*);
};

class Document {
public:
    Element* ownerElement();
};

class Node {
public:
    struct InsertionNotificationRequest {
        enum Result { InsertionDone, InsertionShouldCallDidNotifySubtreeInsertions };
        Result result;
    };
};

#define InsertionDone { Node::InsertionNotificationRequest::InsertionDone }
#define InsertionShouldCallDidNotifySubtreeInsertions { Node::InsertionNotificationRequest::InsertionShouldCallDidNotifySubtreeInsertions }

class HTMLBodyElement : public HTMLElement {
public:
    Node::InsertionNotificationRequest insertedInto(ContainerNode*);
    void setIntegralAttribute(int attr, int value);
    int marginwidthAttr;
    int marginheightAttr;
    Document& document();
};

inline HTMLFrameElementBase& toHTMLFrameElementBase(Element& element) {
    return dynamic_cast<HTMLFrameElementBase&>(element);
}

inline bool isHTMLFrameElementBase(Element* element) {
    return dynamic_cast<HTMLFrameElementBase*>(element) != nullptr;
}