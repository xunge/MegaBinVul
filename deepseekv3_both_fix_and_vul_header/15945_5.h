#include <cassert>

typedef void* xmlNodePtr;

class SimpleXMLElement {
public:
    xmlNodePtr nodep() const;
};

class Object {
public:
    bool instanceof(SimpleXMLElement*) const;
    void* get() const;
    Object* operator->();
    const Object* operator->() const;
};

extern SimpleXMLElement* SimpleXMLElement_classof();

struct Native {
    template<typename T>
    static T* data(void* ptr);
};

xmlNodePtr php_sxe_get_first_node(SimpleXMLElement* data, xmlNodePtr node);