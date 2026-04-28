#include <assert.h>

#define ENABLE_OILPAN 0
#define ENABLE(x) ENABLE_##x
#define ASSERT(x) assert(x)

class SVGAnimatedPropertyBase {
public:
    ~SVGAnimatedPropertyBase();
    bool isAnimating() const;
};