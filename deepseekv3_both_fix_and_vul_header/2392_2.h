#include <stddef.h>

#define big_key_path 0
#define big_key_len 1
#define BIG_KEY_FILE_THRESHOLD 0

struct path;
struct key {
    union {
        void *data[2];
    } payload;
};

int key_is_instantiated(struct key *key);
void key_payload_reserve(struct key *key, unsigned datalen);
int vfs_truncate(struct path *path, long length);