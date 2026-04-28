#include <stdint.h>
#include <stddef.h>

#define RTI_SERVICE_REQUEST_ID_TOPIC_QUERY 1
#define RTI_SERVICE_REQUEST_ID_LOCATOR_REACHABILITY 2
#define RTI_SERVICE_REQUEST_ID_UNKNOWN 0
#define ENC_NA 0

typedef int32_t gint;
typedef uint32_t guint32;
typedef unsigned int guint;

typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct tvbuff_t tvbuff_t;

extern int hf_rtps_srm_request_body;

gint rtps_util_add_rti_topic_query_service_request(proto_tree *tree, tvbuff_t *tvb, gint offset, guint encoding);
gint rtps_util_add_rti_locator_reachability_service_request(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, gint offset, guint encoding);
guint32 tvb_get_guint32(tvbuff_t *tvb, gint offset, guint encoding);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
gint check_offset_addition(gint offset, gint length, proto_tree *tree, void* unused, tvbuff_t *tvb);