#include <stdbool.h>
#include <stdint.h>

typedef uint32_t u32;

struct fd {
    int dummy;
};
struct bpf_map;

struct fd fdget(u32 fd);
void fdput(struct fd f);
struct bpf_map *__bpf_map_get(struct fd f);
struct bpf_map *bpf_map_inc(struct bpf_map *map, bool uref);
bool IS_ERR(const void *ptr);