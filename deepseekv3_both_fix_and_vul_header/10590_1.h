#include <stdint.h>

typedef uint16_t guint16;

extern int hf_btl2cap_min_interval;
extern int hf_btl2cap_max_interval;
extern int hf_btl2cap_slave_latency;
extern int hf_btl2cap_timeout_multiplier;
extern struct expert_field ei_btl2cap_parameter_mismatch;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

#define ENC_LITTLE_ENDIAN 0