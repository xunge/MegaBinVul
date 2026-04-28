#include <stdbool.h>
#include <vector>
#include <cassert>

class FilterEffect {
public:
    virtual ~FilterEffect() = default;
};

class FEColorMatrix : public FilterEffect {
public:
    bool setType(int);
    bool setValues(const std::vector<float>&);
};

class QualifiedName {
public:
    bool operator==(const char*) const;
};

class SVGNames {
public:
    static const char* typeAttr;
    static const char* valuesAttr;
};

struct CurrentValueType {
    int enumValue();
    std::vector<float> toFloatVector();
};

struct ValueHolder {
    CurrentValueType* currentValue();
};

struct SVGFEColorMatrixElement {
    ValueHolder* m_type;
    ValueHolder* m_values;
    bool setFilterEffectAttribute(FilterEffect*, const QualifiedName&);
};

#define ASSERT_NOT_REACHED() assert(false)
#define Vector std::vector