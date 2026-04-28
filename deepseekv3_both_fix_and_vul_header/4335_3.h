#include <stdint.h>
#include <stdlib.h>

typedef struct _fragment_head {
    uint32_t datalen;
    uint32_t offset;
    uint32_t flags;
    struct _fragment_head *next;
} fragment_head;

typedef struct _reassembly_table {
    void *reassembled_table;
} reassembly_table;

typedef struct _packet_info {
    struct _frame_data *fd;
    uint32_t num;
} packet_info;

typedef struct _frame_data {
    struct {
        int visited;
    } flags;
} frame_data;

typedef struct {
    uint32_t frame;
    uint32_t id;
} reassembled_key;

typedef void* gpointer;
typedef uint32_t guint32;

#define FD_DATALEN_SET (1 << 0)
#define FD_DATA_NOT_PRESENT (1 << 1)

void *g_hash_table_lookup(void *hash_table, const void *key);
void g_hash_table_insert(void *hash_table, void *key, void *value);
void *g_slice_new(size_t size);

#define g_slice_new(type) ((type *)malloc(sizeof(type)))

fragment_head *lookup_fd_head(reassembly_table *table, const packet_info *pinfo, const guint32 id, const void *data, gpointer *orig_key);
void fragment_defragment_and_free(fragment_head *fd_head, const packet_info *pinfo);
void fragment_unhash(reassembly_table *table, gpointer orig_key);
void fragment_reassembled(reassembly_table *table, fragment_head *fd_head, const packet_info *pinfo, const guint32 id);