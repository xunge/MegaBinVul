#include <string>
#include <cassert>

class AtomicString;

class CustomElementRegistrationContext;

class Document {
public:
    CustomElementRegistrationContext* registrationContext();
};

class Element {
public:
    bool isHTMLElement() const;
    bool isSVGElement() const;
    bool isCustomElement() const;
    const AtomicString& localName() const;
    Document& document();
    void setCustomElementState(int state);
    enum State { WaitingForUpgrade };
};

class CustomElement {
public:
    static bool isValidName(const AtomicString&);
};

class CustomElementRegistrationContext {
public:
    void setTypeExtension(Element* element, const AtomicString& type);
    void didGiveTypeExtension(Element* element, const AtomicString& type);
};

#define ASSERT(x) assert(x)