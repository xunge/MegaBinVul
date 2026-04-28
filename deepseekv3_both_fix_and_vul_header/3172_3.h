#include <stdbool.h>

template<typename T>
class TemporaryChange {
public:
    TemporaryChange(T& ref, T value) : m_ref(ref), m_oldValue(ref) { ref = value; }
    ~TemporaryChange() { m_ref = m_oldValue; }
private:
    T& m_ref;
    T m_oldValue;
};

class RenderSVGContainer {
public:
    void layout();
};

class RenderSVGRoot {
public:
    static void addResourceForClientInvalidation(void*);
};

class RenderSVGResourceMarker : public RenderSVGContainer {
public:
    void layout();
    bool m_isInLayout;
    bool needsLayout();
    bool everHadLayout();
    bool selfNeedsLayout();
    void removeAllClientsFromCache();
};

#define ASSERT(expr) ((void)0)