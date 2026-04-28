#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define _U_
#define COL_PROTOCOL 0
#define COL_INFO 1
#define ENC_NA 0
#define FALSE false

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    struct {
        int srcport;
        int match_uint;
    };
    void* cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field {
    int dummy;
} expert_field;

typedef int8_t gint8;
typedef int32_t gint32;
typedef bool gboolean;

extern int proto_pktc;
extern int ett_pktc_mtafqdn;
extern expert_field ei_pktc_unknown_kerberos_application;
extern void* cb;

static int dissect_kerberos_main(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean flag, void* handle);