#include <stdbool.h>

typedef enum {
    AnimatedTransformList,
    AnimatedUnknown
} AnimatedPropertyType;

struct Animator {
    bool isAnimatingCSSProperty();
};

struct AnimatedProperty {
    char* valueAsString();
};

struct SVGAnimateElement {
    AnimatedPropertyType m_animatedPropertyType;
    AnimatedProperty* m_animatedProperty;
    Animator* m_animator;
    struct {
        bool isEmpty() { return true; }
    } m_animatedElements;
    
    void applyResultsToTarget();
    Animator* ensureAnimator();
};

void ASSERT(bool condition);
bool isSVGAnimateTransformElement(SVGAnimateElement element);
void* targetElement();
char* attributeName();
void applyCSSPropertyToTargetAndInstances(void* target, char* attribute, char* value);
void notifyTargetAndInstancesAboutAnimValChange(void* target, char* attribute);