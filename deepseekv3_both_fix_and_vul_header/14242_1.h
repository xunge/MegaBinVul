#include <stdint.h>

typedef uint32_t guint;
typedef struct _tvbuff tvbuff_t;
typedef struct _packet_info packet_info;
typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _proto_tree proto_tree;
typedef struct _expert_field expert_field;

extern int hf_bencoded_list;
extern int ett_bencoded_list;
extern int hf_bencoded_list_terminator;
extern expert_field ei_int_string;

extern int dissect_bencoded_int(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const char **result, const char *label);
extern int dissect_bencoded_dict(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const char *label);
extern int dissect_bencoded_string(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const char **result, int is_key, const char *label);

#define ENC_ASCII 0
#define ENC_NA 0
#define FALSE 0