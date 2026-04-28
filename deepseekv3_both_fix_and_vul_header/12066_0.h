#include <stdint.h>

enum class RateLimitTarget {
    CONTROL_MSGS,
    DIRECT_ERROR_HANDLING,
    HEADERS
};

struct HttpSessionStats {
    void (*recordControlMsgsInInterval)(unsigned int);
    void (*recordHeadersInInterval)(unsigned int);
};

extern struct HttpSessionStats* httpSessionStats;
extern unsigned int counter;
extern RateLimitTarget rateLimitTarget;

#define noexcept
#define override