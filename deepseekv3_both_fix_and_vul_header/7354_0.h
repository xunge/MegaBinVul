#include <algorithm>

struct TileDescription {
    int xSize;
    int ySize;
};

struct V2i {
    int x;
    int y;
    V2i(int x, int y) : x(x), y(y) {}
    int operator[](int index) const { return index == 0 ? x : y; }
};

struct Box2i {
    V2i min;
    V2i max;
    Box2i(const V2i& min, const V2i& max) : min(min), max(max) {}
};

typedef long long Int64;

Box2i dataWindowForLevel(const TileDescription& tileDesc,
                        int minX, int maxX,
                        int minY, int maxY,
                        int lx, int ly);