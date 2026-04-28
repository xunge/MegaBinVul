#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint16_t guint16;
typedef unsigned int guint;
typedef bool gboolean;

typedef struct dissector_handle {
    void *protocol;
} *dissector_handle_t;

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;

struct packet_info {
    const char *current_proto;
    guint16 can_desegment;
    guint16 saved_can_desegment;
    void *layers;
    guint curr_layer_num;
    struct {
        gboolean in_error_pkt;
    } flags;
};

#define GINT_TO_POINTER(i) ((void*)(intptr_t)(i))
#define PINFO_LAYER_MAX_RECURSION_DEPTH 100

int proto_is_protocol_enabled(void *protocol);
int proto_is_pino(void *protocol);
const char *proto_get_protocol_short_name(void *protocol);
int proto_get_id(void *protocol);
unsigned int wmem_list_count(void *list);
void wmem_list_append(void *list, void *data);
void *wmem_list_tail(void *list);
void wmem_list_remove_frame(void *list, void *frame);
int call_dissector_work_error(dissector_handle_t handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data);
int call_dissector_through_handle(dissector_handle_t handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data);