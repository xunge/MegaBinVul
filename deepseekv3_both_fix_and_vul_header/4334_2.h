#include <stdint.h>
#include <stddef.h>

typedef uint32_t guint32;
typedef int gboolean;
typedef void* gpointer;

typedef struct fragment_head {
    unsigned int flags;
    uint32_t reassembled_in;
    uint32_t reas_in_layer_num;
    struct fragment_item *next;
} fragment_head;

typedef struct fragment_item {
    uint32_t offset;
    struct fragment_item *next;
} fragment_item;

typedef struct reassembly_table reassembly_table;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    struct {
        struct {
            unsigned int visited;
        } flags;
    } *fd;
    uint32_t num;
    uint32_t curr_layer_num;
} packet_info;

#define FD_DEFRAGMENTED 0x01
#define FD_DATA_NOT_PRESENT 0x02
#define FD_BLOCKSEQUENCE 0x04
#define REASSEMBLE_FLAGS_NO_FRAG_NUMBER 0x08
#define REASSEMBLE_FLAGS_802_11_HACK 0x10
#define REASSEMBLE_FLAGS_CHECK_DATA_PRESENT 0x20

fragment_head* lookup_fd_head(reassembly_table*, const packet_info*, guint32, const void*, gpointer*);
fragment_head* new_head(unsigned int);
gpointer insert_fd_head(reassembly_table*, fragment_head*, const packet_info*, guint32, const void*);
int tvb_bytes_exist(const tvbuff_t*, int, guint32);
void fragment_unhash(reassembly_table*, gpointer);
void free_all_fragments(void*, fragment_head*, void*);
int fragment_add_seq_work(fragment_head*, tvbuff_t*, int, const packet_info*, guint32, guint32, gboolean);