#include <stdbool.h>

template<typename T>
struct TemporaryChange {
    T& m_value;
    T m_oldValue;
    TemporaryChange(T& value, T newValue) : m_value(value), m_oldValue(value) { m_value = newValue; }
    ~TemporaryChange() { m_value = m_oldValue; }
};

class RenderSVGHiddenContainer {
public:
    void layout();
};

class RenderSVGRoot {
public:
    static void addResourceForClientInvalidation(void*);
};

class RenderSVGResourceContainer : public RenderSVGHiddenContainer {
protected:
    bool m_isInLayout;
    bool needsLayout();
    bool everHadLayout();
    bool selfNeedsLayout();
    void removeAllClientsFromCache();
    void layout();
};

#define ASSERT(expr) ((void)0)