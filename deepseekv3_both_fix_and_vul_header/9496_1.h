#include <stddef.h>

typedef int WebScreenOrientationLockType;
typedef void* WebLockOrientationCallback;

struct Client {
    void lockOrientation(WebScreenOrientationLockType, WebLockOrientationCallback*);
};

struct ScreenOrientationController {
    Client* m_client;
    void lock(WebScreenOrientationLockType, WebLockOrientationCallback*);
};

#define ASSERT(expr) ((void)0)