#include <stddef.h>

#define TRESPASS() ((void)0)

struct FLACParser {
    static const size_t kMaxChannels;
};

const size_t FLACParser::kMaxChannels = 0;