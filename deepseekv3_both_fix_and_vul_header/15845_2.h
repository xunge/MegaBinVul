#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

struct flow_keys {
    // 假设的结构体成员
};

typedef struct {
    // 假设的结构体成员
} siphash_key_t;

static inline void __flow_hash_consistentify(struct flow_keys *keys) {}
static inline const void *flow_keys_hash_start(const struct flow_keys *keys) { return NULL; }
static inline size_t flow_keys_hash_length(const struct flow_keys *keys) { return 0; }
static inline u32 siphash(const void *data, size_t len, const siphash_key_t *key) { return 0; }
static inline u32 __flow_hash_words(const void *data, size_t len, u32 key) { return 0; }