#include <stdint.h>
#include <string.h>

typedef uint32_t guint;

typedef struct tvbuff {
    // dummy tvbuff structure
} tvbuff_t;

typedef struct column_info {
    // dummy column_info structure
} column_info;

typedef struct irda_pseudo_header {
    int pkttype;
} irda_pseudo_header;

typedef struct pseudo_header {
    struct irda_pseudo_header irda;
} pseudo_header;

typedef struct packet_info {
    struct column_info *cinfo;
    struct pseudo_header *pseudo_header;
} packet_info;

typedef struct proto_tree {
    // dummy proto_tree structure
} proto_tree;

typedef struct proto_item {
    // dummy proto_item structure
} proto_item;

#define COL_PROTOCOL 0
#define COL_INFO 1
#define IRDA_MISSED_MSG 0
#define ENC_NA 0
#define ENC_ASCII 1

extern int proto_log;
extern int ett_log;
extern int hf_log_missed;
extern int hf_log_msg;

// Function prototypes
void col_set_str(column_info *cinfo, int col, const char *str);
void col_add_str(column_info *cinfo, int col, const char *str);
guint tvb_length(tvbuff_t *tvb);
void tvb_memcpy(tvbuff_t *tvb, void *buf, int offset, int length);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, 
                              int start, int length, int encoding);
proto_tree *proto_item_add_subtree(proto_item *ti, int ett);