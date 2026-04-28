#include <stdint.h>
#include <stdbool.h>

struct InputWindowInfo {
    int32_t frameLeft;
    int32_t frameRight;
    int32_t frameTop;
    int32_t frameBottom;
    bool frameContainsPoint(int32_t x, int32_t y) const;
};