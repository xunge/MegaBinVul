#include <stddef.h>

struct TestingPlatformSupport {
    void cryptographicallyRandomValues(unsigned char* buffer, size_t length);
};

#define RELEASE_ASSERT_NOT_REACHED()