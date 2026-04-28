#include <stdbool.h>

struct AudioParam {
    float m_value;
    void calculateFinalValues(float*, int, bool);
    float finalValue();
};