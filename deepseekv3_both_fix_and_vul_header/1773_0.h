#include <stddef.h>

struct btf_dump;
struct hashmap;

size_t hashmap__find(struct hashmap *map, const char *key, void **value);
int hashmap__set(struct hashmap *map, const char *key, void *value, void *old_key, void *old_value);