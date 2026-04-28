#include <stdint.h>

class SVGInteger;

template<typename T>
class SVGAnimatedProperty {
public:
    void synchronizeAttribute();
};

class SVGAnimatedInteger : public SVGAnimatedProperty<SVGInteger> {
public:
    SVGAnimatedInteger* m_parentIntegerOptionalInteger;
    void synchronizeAttribute();
    bool needsSynchronizeAttribute();
};

#define ASSERT(expr) ((void)0)