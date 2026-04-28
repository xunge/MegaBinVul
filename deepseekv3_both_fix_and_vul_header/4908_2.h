#include <stdbool.h>

typedef int AnimatedPropertyType;
struct QualifiedName {
    int value;
    bool operator!=(const QualifiedName& other) const { return value != other.value; }
};
struct SVGElement {
    void setContextElement();
};

struct SVGAnimatedPropertyBase {
    SVGAnimatedPropertyBase(AnimatedPropertyType, SVGElement*, const QualifiedName&);
    AnimatedPropertyType m_type;
    bool m_isReadOnly;
    bool m_isAnimating;
    SVGElement* m_contextElement;
    QualifiedName m_attributeName;
};

const QualifiedName nullQName();
#define ASSERT(expr) ((void)0)