#include <stddef.h>

struct work_struct {
    // minimal definition
};

struct btf_record {
    // minimal definition  
};

struct btf {
    // minimal definition
};

struct bpf_map_ops {
    void (*map_free)(struct bpf_map *map);
    // other ops...
};

struct bpf_map {
    struct work_struct work;
    struct btf_record *record;
    struct btf *btf;
    struct bpf_map_ops *ops;
    // other members...
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

void security_bpf_map_free(struct bpf_map *map);
void bpf_map_release_memcg(struct bpf_map *map);
void btf_record_free(struct btf_record *rec);
void btf_put(struct btf *btf);