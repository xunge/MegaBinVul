#include <vector>
#include <cstddef>

#define unlikely(x) __builtin_expect(!!(x), 0)

struct SplashCoord {
    int x0;
    int x1;
    int count;
};

class SplashBitmap {
public:
    int getWidth();
    unsigned char* getDataPtr();
    int getRowSize();
};

class SplashXPathScanner {
private:
    std::vector<std::vector<SplashCoord>> allIntersections;
    int yMin;
    int yMax;
    bool eo;
    static const int splashAASize;
public:
    void clipAALine(SplashBitmap *aaBuf, int *x0, int *x1, int y);
};

typedef unsigned char* SplashColorPtr;