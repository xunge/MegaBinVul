#include <stdbool.h>
#include <assert.h>

#define ASSERT(x) assert(x)

struct SVGAnimatedPropertyBase {
    bool m_isAnimating;
    bool isAnimating();
    void animationStarted();
};

bool SVGAnimatedPropertyBase::isAnimating() {
    return m_isAnimating;
}