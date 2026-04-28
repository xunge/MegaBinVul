#include <algorithm>

struct V2i {
    int x, y;
    V2i(int x = 0, int y = 0) : x(x), y(y) {}
    int operator[](int i) const { return i == 0 ? x : y; }
    V2i operator+(const V2i& other) const { return V2i(x + other.x, y + other.y); }
};

struct Box2i {
    V2i min, max;
    Box2i(const V2i& min, const V2i& max) : min(min), max(max) {}
};

struct TileDescription {
    int xSize, ySize;
};

Box2i dataWindowForLevel(const TileDescription& tileDesc,
                        int minX, int maxX,
                        int minY, int maxY,
                        int lx, int ly);

typedef long long Int64;