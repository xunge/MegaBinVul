#include <algorithm>

struct SkPoint {
    float fX;
    float fY;
};

typedef float SkScalar;

template <size_t N>
void find_minmax(const SkPoint pts[], SkScalar* min, SkScalar* max);

bool checkOnCurve(SkScalar x, SkScalar y, const SkPoint& p0, const SkPoint& p1);

namespace SkCubicClipper {
    bool ChopMonoAtY(const SkPoint pts[4], SkScalar y, SkScalar* t);
}

SkScalar eval_cubic_pts(SkScalar c0, SkScalar c1, SkScalar c2, SkScalar c3, SkScalar t);

#define SkTSwap(a, b) std::swap(a, b)
#define SkAssertResult(cond) (void)((cond) || (abort(), 0))
#define SkScalarNearlyEqual(a, b) (std::abs((a) - (b)) < 1e-6f)