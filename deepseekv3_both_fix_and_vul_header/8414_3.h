#include <stdint.h>
#include <vector>
#include <climits>
#include <cstdio>

enum status_t {
    NO_ERROR,
    NO_MEMORY,
    BAD_VALUE
};

#define ALOGE(...) fprintf(stderr, __VA_ARGS__)
#define android_errorWriteWithInfoLog(...) ((void)0)

class FlattenableUtils {
public:
    static void read(void const*& buffer, size_t& size, uint32_t& value);
    static void advance(void const*& buffer, size_t& size, size_t offset);
};

class Rect {
public:
    static const Rect EMPTY_RECT;
    status_t unflatten(void const* buffer, size_t size);
};

class Region {
public:
    std::vector<Rect> mStorage;
    bool validate(Region const& region, const char* name, bool silent = false);
    void validate(Region const& region, const char* name);
    status_t unflatten(void const* buffer, size_t size);
};