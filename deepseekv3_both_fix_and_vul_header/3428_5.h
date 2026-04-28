#include <stdint.h>
#include <stdlib.h>

typedef int gboolean;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint8_t guint8;

struct GList {
    void *data;
    struct GList *next;
    struct GList *prev;
};
typedef struct GList GList;

typedef struct GHashTable GHashTable;

struct nstime_t {
    int secs;
    int nsecs;
};
typedef struct nstime_t nstime_t;

enum rlc_mode {
    RLC_UM,
    RLC_AM,
    RLC_TM
};

struct rlc_channel {
    guint32  ueid;
    guint8   rb_id;
    guint8   direction;
    enum rlc_mode mode;
};

struct rlc_seq {
    guint16 seq;
    guint32 frame_num;
    nstime_t arrival;
};

struct rlc_seqlist {
    struct rlc_channel ch;
    GList *list;
};

typedef struct packet_info {
    struct {
        int num;
        nstime_t abs_ts;
    } *fd;
} packet_info;

#define RLC_RETRANSMISSION_TIMEOUT 5
#define TRUE 1
#define FALSE 0

extern GHashTable *sequence_table;

void* g_malloc0(size_t size);
void* se_alloc0(size_t size);
void g_hash_table_insert(GHashTable *table, void *key, void *value);
void* g_hash_table_lookup(GHashTable *table, const void *key);
GList* g_list_insert_sorted(GList *list, void *data, int (*func)(const void*, const void*));
GList* g_list_find_custom(GList *list, const void *data, int (*func)(const void*, const void*));
void nstime_delta(nstime_t *delta, const nstime_t *t1, const nstime_t *t2);
int rlc_cmp_seq(const void *a, const void *b);
void rlc_channel_assign(struct rlc_channel *ch, enum rlc_mode mode, packet_info *pinfo);