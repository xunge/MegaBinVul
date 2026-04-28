#include <stdint.h>
#include <time.h>

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct {
    int32_t secs;
    int32_t nsecs;
} nstime_t;

typedef struct {
    nstime_t start_time;
} call_data_t;

typedef struct {
    call_data_t *call_data;
    nstime_t abstime;
} iax_packet_data;

typedef struct {
    nstime_t abs_ts;
} packet_info;

typedef struct {
    uint32_t timestamp;
} iax2_info_t;

extern iax2_info_t *iax2_info;
extern int hf_iax2_absts;
extern int hf_iax2_lateness;

typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int32_t gint32;

proto_item* proto_tree_add_time(proto_tree *tree, int hfindex, void *data, int start, int end, nstime_t *time);
void nstime_delta(nstime_t *result, nstime_t *a, nstime_t *b);
void PROTO_ITEM_SET_GENERATED(proto_item *item);