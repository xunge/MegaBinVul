#include <stdint.h>

typedef uint16_t sal_uInt16;

struct Point {
    int x;
    int y;
};

class Polygon {
    struct ImplPolygon* mpImplPolygon;
    void ImplMakeUnique();
public:
    void Insert(sal_uInt16 nPos, const Point& rPt);
};

struct ImplPolygon {
    sal_uInt16 mnPoints;
    Point* mpPointAry;
    bool ImplSplit(sal_uInt16 nPos, int nCount);
};