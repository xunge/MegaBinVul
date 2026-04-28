#include <assert.h>
#include <stdlib.h>

#define ASSERT assert

class Element {
public:
    virtual ~Element() {}
    virtual Element* cloneElementWithoutChildren() = 0;
    virtual Element* firstChild() = 0;
};

class ShadowRoot : public Element {
public:
    void appendChild(Element*);
    Element* firstChild() override;
};

template<typename T> class RefPtrWillBeRawPtr {
public:
    RefPtrWillBeRawPtr(T* ptr = nullptr) : m_ptr(ptr) {}
    operator bool() const { return m_ptr != nullptr; }
    T* get() { return m_ptr; }
    T* operator->() { return m_ptr; }
    T* release() { T* ptr = m_ptr; m_ptr = nullptr; return ptr; }
private:
    T* m_ptr;
};

class SVGElement : public Element {
public:
    SVGElement* correspondingUseElement();
    SVGElement* correspondingElement();
    Element* parentNode();
};

class SVGUseElement : public SVGElement {
public:
    RefPtrWillBeRawPtr<SVGElement> m_targetElementInstance;
    
    bool inUseShadowTree();
    bool isDisallowedElement(SVGElement*);
    ShadowRoot* userAgentShadowRoot();
    bool buildShadowTree(SVGElement*, SVGElement*, bool);
    void clearResourceReferences();
    bool instanceTreeIsLoading(SVGElement*);
    bool expandUseElementsInShadowTree(SVGElement*);
    void expandSymbolElementsInShadowTree(SVGElement*);
    void transferUseWidthAndHeightIfNeeded(SVGUseElement&, SVGElement*, SVGElement&);
    void updateRelativeLengthsInformation();
    
    void buildShadowAndInstanceTree(SVGElement* target);
};

SVGElement* toSVGElement(Element*);