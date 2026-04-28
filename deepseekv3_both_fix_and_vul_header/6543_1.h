#include <algorithm>
#include <cassert>
#include <cstdint>

#define ceph_assert assert

struct MaskedIP {
    uint64_t addr;
    bool v6;
    unsigned int prefix;
};