#include <stddef.h>
#include <assert.h>

typedef float SkScalar;

#define SkAssertResult(cond) assert(cond)

struct SkPoint {
    SkScalar fX;
    SkScalar fY;
};

struct SkVector {
    SkScalar fX;
    SkScalar fY;
};

template <typename T> class SkTDArray {
public:
    void push(const T&) {}
};

class SkCubicClipper {
public:
    static bool ChopMonoAtY(const SkPoint pts[], SkScalar y, SkScalar* t) { return false; }
};

static bool between(SkScalar a, SkScalar b, SkScalar c) { return false; }
static int SkChopCubicAtYExtrema(const SkPoint pts[], SkPoint dst[]) { return 0; }
static SkScalar eval_cubic_pts(SkScalar c0, SkScalar c1, SkScalar c2, SkScalar c3, SkScalar t) { return 0; }
static bool SkScalarNearlyEqual(SkScalar x, SkScalar y) { return false; }
static void SkEvalCubicAt(const SkPoint pts[], SkScalar t, SkPoint* pos, SkVector* tangent, SkVector* curvature) {}