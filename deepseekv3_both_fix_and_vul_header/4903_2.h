#include <string>

enum SVGMarkerOrient {
    SVGMarkerOrientAuto
};

class AtomicString {
public:
    AtomicString();
    AtomicString(const char*);
    AtomicString(const std::string&);
};

class SVGPropertyTearOff {
public:
    int enumValue();
    std::string valueAsString();
};

class SVGElement {
public:
    void setSynchronizedLazyAttribute(const char*, const AtomicString&);
};

class SVGAnimatedAngle {
protected:
    struct OrientType {
        SVGPropertyTearOff* currentValue();
    };
    OrientType* m_orientType;

    SVGPropertyTearOff* currentValue();
    SVGElement* contextElement();
    bool needsSynchronizeAttribute();
    const char* attributeName();
    void setSynchronizedLazyAttribute(const char*, const AtomicString&);
public:
    void synchronizeAttribute();
};

void ASSERT(bool);