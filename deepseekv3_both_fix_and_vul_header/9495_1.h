#include <assert.h>

#define ASSERT(x) assert(x)

struct ScreenOrientationClient {
    void unlockOrientation();
};

class ScreenOrientationController {
public:
    ScreenOrientationClient* m_client;
    void unlock();
};