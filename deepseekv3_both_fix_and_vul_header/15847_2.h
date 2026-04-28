#include <stdint.h>

typedef uint32_t u32;

u32 hashrnd;

struct flow_keys;

void __flow_hash_secret_init(void);
u32 __flow_hash_from_keys(struct flow_keys *keys, u32 hashrnd);