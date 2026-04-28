#include <stdlib.h>

#define OILPAN 1
#define ENABLE(x) x

class Visitor {
public:
    void trace(void* obj);
};

class SVGAnimationElement {
public:
    void trace(Visitor* visitor);
};

class SVGAnimateElement : public SVGAnimationElement {
private:
    void* m_animator;
#if ENABLE(OILPAN)
    void* m_animatedElements;
#endif
public:
    void trace(Visitor* visitor);
};