#include <stdbool.h>
#include <vector>

class FilterEffect {
public:
    virtual ~FilterEffect() {}
};

class FEColorMatrix : public FilterEffect {
public:
    bool setType(int);
    bool setValues(const std::vector<float>&);
};

class QualifiedName {
public:
    bool operator==(const QualifiedName&) const;
};

class SVGNames {
public:
    static const QualifiedName typeAttr;
    static const QualifiedName valuesAttr;
};

struct CurrentValue {
    int enumValue();
    std::vector<float> toFloatVector();
};

struct ValueWrapper {
    CurrentValue* currentValue();
};

struct SVGFEColorMatrixElement {
    ValueWrapper* m_type;
    ValueWrapper* m_values;
    bool setFilterEffectAttribute(FilterEffect*, const QualifiedName&);
};

#define ASSERT_NOT_REACHED() ((void)0)

template<typename T>
using Vector = std::vector<T>;