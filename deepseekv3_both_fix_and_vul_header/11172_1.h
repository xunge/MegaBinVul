#include <stdbool.h>
#include <stdint.h>

typedef uint64_t ut64;
typedef uint32_t ut32;
typedef uint8_t ut8;

struct minidump_directory {
    uint32_t StreamType;
    uint32_t Location;
};

struct r_bin_mdmp_obj {
    void *kv;
    struct {
        ut64 stream_directory_rva;
        uint32_t number_of_streams;
    } *hdr;
    struct {
        ut8 *buf;
        int (*read_at)(void *b, ut64 addr, ut8 *buf, int len);
    } *b;
};

int sdb_num_set(void *kv, const char *key, ut64 value, int mode);
int sdb_set(void *kv, const char *key, const char *value, int mode);
bool r_bin_mdmp_init_directory_entry(struct r_bin_mdmp_obj *obj, struct minidump_directory *entry);