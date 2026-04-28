#include <stdint.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

typedef struct {
    void *call_data;
} dcerpc_info;

typedef struct {
    char *private_data;
} dcerpc_call_value;

typedef uint8_t guint8;
#define FALSE 0

extern int dissect_SYSTEM_TIME(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep, void *null, int false, char **str);