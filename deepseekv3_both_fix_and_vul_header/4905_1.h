#include <stdbool.h>
#include <assert.h>

struct SVGAnimatedPropertyBase {
    bool m_isAnimating;
    void animationEnded();
    void synchronizeAttribute();
    bool isAnimating();
};

#define ASSERT(x) assert(x)