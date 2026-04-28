#include <string>
#include <atomic>

class AtomicString;

class ContextElement {
public:
    void setSynchronizedLazyAttribute(const std::string&, const AtomicString&);
};

class SVGAnimatedPropertyBase {
public:
    void synchronizeAttribute();
protected:
    class CurrentValueBase {
    public:
        std::string valueAsString();
    };
    CurrentValueBase* currentValueBase();
    ContextElement* m_contextElement;
    std::string m_attributeName;
    bool needsSynchronizeAttribute();
};

class AtomicString {
public:
    AtomicString(const std::string&);
};

#define ASSERT(expr) ((void)0)