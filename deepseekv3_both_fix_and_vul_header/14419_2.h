#include <stddef.h>
#include <stdbool.h>

#define unlikely(x) __builtin_expect(!!(x), 0)

struct Item {
    void clear() {}
};

struct hb_iter {
    Item* items;
    size_t mask;
    hb_iter(Item* i, size_t m) : items(i), mask(m) {}
    Item* begin() { return items; }
    Item* end() { return items + mask + 1; }
};

extern bool successful;
extern Item* items;
extern size_t mask;
extern size_t population;
extern size_t occupancy;