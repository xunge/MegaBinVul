#include <vector>
#include <cstdbool>

template<typename T>
using Vector = std::vector<T>;

class FEColorMatrix {
private:
    Vector<float> m_values;
public:
    bool setValues(const Vector<float> &values);
};

#define ASSERT(expr) ((void)0)