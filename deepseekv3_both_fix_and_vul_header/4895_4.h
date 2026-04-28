#include <vector>
#include <string>
#include <cassert>

enum ShouldApplyAnimation {
    DontApplyAnimation,
    ApplyXMLAnimation,
    ApplyCSSAnimation
};

class SVGElement;
class SVGAnimationElement {
public:
    static bool isTargetAttributeCSSProperty(SVGElement*, const class QualifiedName&);
};

class QualifiedName {
public:
    std::string localName() const;
};

class String {};

class SVGAnimateElement;

class Document {
public:
    class SVGExtensions {
    public:
        void addElementReferencingTarget(SVGAnimateElement*, SVGElement*);
    };
    SVGExtensions& accessSVGExtensions();
};

template<typename T> class RawPtrWillBeMember {
    T* m_ptr;
public:
    operator T*() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
    T& operator*() const { return *m_ptr; }
};

template<typename T> class WillBeHeapVector {
    std::vector<T> m_vector;
public:
    typedef typename std::vector<T>::const_iterator const_iterator;
    const_iterator begin() const { return m_vector.begin(); }
    const_iterator end() const { return m_vector.end(); }
    bool isEmpty() const { return m_vector.empty(); }
    void append(const T& value) { m_vector.push_back(value); }
};

class SVGAnimatedTypeAnimator {
public:
    int type() const;
    SVGAnimatedTypeAnimator* startAnimValAnimation(const WillBeHeapVector<RawPtrWillBeMember<SVGElement>>&);
    SVGAnimatedTypeAnimator* resetAnimValToBaseVal(const WillBeHeapVector<RawPtrWillBeMember<SVGElement>>&);
    SVGAnimatedTypeAnimator* constructFromString(const String&);
};

class SVGAnimateElement {
protected:
    SVGAnimatedTypeAnimator* m_animatedProperty;
    int m_animatedPropertyType;
    WillBeHeapVector<RawPtrWillBeMember<SVGElement>> m_animatedElements;

    SVGAnimatedTypeAnimator* ensureAnimator();
    SVGElement* targetElement();
    const QualifiedName& attributeName();
    ShouldApplyAnimation shouldApplyAnimation(SVGElement*, const QualifiedName&);
    WillBeHeapVector<RawPtrWillBeMember<SVGElement>> findElementInstances(SVGElement*);
    Document& document();
    void computeCSSPropertyValue(SVGElement*, int, String&);
    int cssPropertyID(const std::string&);
public:
    void resetAnimatedType();
};

#define ASSERT(expr) assert(expr)