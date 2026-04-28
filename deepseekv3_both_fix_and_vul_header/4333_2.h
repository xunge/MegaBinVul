#include <stdint.h>
#include <stddef.h>

typedef uint32_t guint32;
typedef void* gpointer;
typedef int gboolean;

typedef struct reassembly_table {
    void* reassembled_table;
} reassembly_table;

typedef struct tvbuff_t {
    // dummy structure
} tvbuff_t;

typedef struct frame_data {
    struct {
        unsigned visited:1;
    } flags;
} frame_data;

typedef struct packet_info {
    frame_data* fd;
    guint32 num;
} packet_info;

typedef struct fragment_head {
    guint32 flags;
} fragment_head;

typedef struct {
    guint32 frame;
    guint32 id;
} reassembled_key;

#define REASSEMBLE_FLAGS_CHECK_DATA_PRESENT (1 << 0)
#define FD_DATA_NOT_PRESENT (1 << 1)

void* g_hash_table_lookup(void* hash_table, const void* key);
fragment_head* fragment_add_seq_common(reassembly_table* table, tvbuff_t* tvb, 
                                     int offset, packet_info* pinfo, guint32 id,
                                     const void* data, guint32 frag_number,
                                     guint32 frag_data_len, gboolean more_frags,
                                     guint32 flags, gpointer* orig_key);
void fragment_unhash(reassembly_table* table, gpointer orig_key);
void fragment_reassembled(reassembly_table* table, fragment_head* fd_head,
                         packet_info* pinfo, guint32 id);