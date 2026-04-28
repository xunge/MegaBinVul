#include <stdint.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;
typedef unsigned int guint;

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define ENC_ASCII 2
#define COL_INFO 0

extern int hf_bt_dht_peers;
extern int hf_bt_dht_peer;
extern int hf_ip;
extern int hf_ip6;
extern int hf_port;
extern int hf_truncated_data;
extern int hf_bencoded_list_terminator;
extern int ett_bt_dht_peers;
extern expert_field ei_invalid_len;

struct packet_info {
    void *pool;
    void *cinfo;
};