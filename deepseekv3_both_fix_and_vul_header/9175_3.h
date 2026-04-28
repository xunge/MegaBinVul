#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>

typedef uint8_t guint8;
typedef void* gpointer;
typedef const void* gconstpointer;

typedef struct {
    uint32_t req_frame;
    struct timeval ns;
    uint32_t cookie_len;
    const guint8 *cookie;
} nlm_msg_res_unmatched_data;

typedef struct packet_info {
    struct {
        uint32_t num;
        struct timeval abs_ts;
    } *fd;
} packet_info;

typedef struct tvbuff_t {
    // 定义tvbuff_t结构体所需的基本字段
} tvbuff_t;

extern void *nlm_msg_res_unmatched;
extern void *g_malloc(size_t size);
extern uint32_t tvb_get_ntohl(tvbuff_t *tvb, int offset);
extern void *tvb_memdup(void *ptr, tvbuff_t *tvb, int offset, int length);
extern void *g_hash_table_lookup(void *hash_table, gconstpointer key);
extern void g_hash_table_remove(void *hash_table, gconstpointer key);
extern void g_free(gpointer ptr);
extern void g_hash_table_insert(void *hash_table, gpointer key, gpointer value);