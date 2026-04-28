#include <time.h>
#include <stdint.h>

typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint32_t guint;

typedef struct {
    time_t secs;
    int32_t nsecs;
} nstime_t;

typedef struct {
    nstime_t abs_ts;
} frame_data;

typedef struct {
    frame_data *fd;
    nstime_t abs_ts;
} packet_info;

typedef struct {
    nstime_t start_time;
} call_data;

typedef struct {
    call_data *call_data;
    nstime_t abstime;
} iax_packet_data;

typedef struct {
    guint32 timestamp;
} iax2_info_t;

extern iax2_info_t *iax2_info;
extern int hf_iax2_absts;
extern int hf_iax2_lateness;
extern int ei_iax_invalid_ts;

#define MAX_SECS_DIFF 60
#define PROTO_ITEM_SET_GENERATED(x)

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct tvbuff_t tvbuff_t;

void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, int *ei, tvbuff_t *tvb, int offset, int length);
proto_item *proto_tree_add_time(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const nstime_t *timeptr);
void nstime_delta(nstime_t *dest, const nstime_t *t1, const nstime_t *t2);