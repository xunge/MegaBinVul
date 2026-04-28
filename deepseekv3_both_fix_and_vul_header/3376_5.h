#include <algorithm>
#include <vector>
#include <memory>

#define ASSERT(expr) ((void)0)
#define IGNORE_EXCEPTION 0

class SMILTime {
public:
    static SMILTime unresolved();
    bool isFinite();
    bool operator<(const SMILTime&) const;
};

class SVGElement {
public:
    bool inDocument();
    void remove(int);
};

class SMILTimeContainer;

class SVGSMILElement {
public:
    bool hasValidAttributeType();
    bool hasValidAttributeName();
    bool progress(SMILTime, SVGSMILElement*, bool);
    SMILTime nextProgressTime();
    void applyResultsToTarget();
    bool inDocument();
    bool isSVGDiscardElement();
    void remove(int);
    SVGElement* targetElement();
    SMILTimeContainer* timeContainer();
};

template<typename T> class Vector {
public:
    unsigned size();
    void append(const T&);
    T& operator[](unsigned);
};

template<typename T> class RefPtr {
public:
    RefPtr();
    RefPtr(T*);
    T* operator->();
    T* get();
    operator bool() const;
};

struct AnimationsVector {
    unsigned size();
    SVGSMILElement* at(unsigned);
};

class SMILTimeContainer {
public:
    void updateAnimations(SMILTime, bool);
    void startTimer(SMILTime, double);
    
#ifndef NDEBUG
    bool m_preventScheduledAnimationsChanges;
#endif

    struct GroupedAnimationsMap {
        struct iterator {
            struct value_type {
                std::unique_ptr<AnimationsVector> value;
                AnimationsVector* get();
            };
            value_type* operator->();
            iterator& operator++();
            bool operator!=(const iterator&);
        };
        iterator begin();
        iterator end();
    };
    GroupedAnimationsMap m_scheduledAnimations;

    static const double animationFrameDelay;
};

void sortByPriority(AnimationsVector&, SMILTime);

using std::min;