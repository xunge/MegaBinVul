#include <stddef.h>

class SVGNumber {};

template<typename T>
class SVGAnimatedProperty {
public:
    static void synchronizeAttribute();
};

struct SVGAnimatedNumber {
    SVGAnimatedProperty<SVGNumber>* m_parentNumberOptionalNumber;
    bool needsSynchronizeAttribute();
    void synchronizeAttribute();
};

#define ASSERT(expr) ((void)0)