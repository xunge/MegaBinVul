#include <stdlib.h>
#include <stdbool.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

#define _U_ __attribute__((unused))
#define FALSE false
#define TRUE true

void dissect_q931_IEs(tvbuff_t *tvb, packet_info *pinfo, void *null_val, proto_tree *tree, bool flag, int val1, int val2, ...);
int tvb_captured_length(tvbuff_t *tvb);