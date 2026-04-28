#include <stdbool.h>
#include <stdarg.h>
#include <stddef.h>

typedef struct _tvbuff_t tvbuff_t;
typedef struct _packet_info packet_info;
typedef struct _proto_tree proto_tree;

#define FALSE false
#define _U_ __attribute__((unused))

void dissect_q931_IEs(tvbuff_t *tvb, packet_info *pinfo, void *null_val, proto_tree *tree, bool flag, int num1, int num2, ...);
int tvb_captured_length(tvbuff_t *tvb);