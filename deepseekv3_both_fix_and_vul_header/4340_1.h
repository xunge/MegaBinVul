#include <stdlib.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

extern int beacon_padding;
extern int add_tagged_field(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, int ftype, ...);