#include <stdint.h>

typedef int32_t gint;
typedef uint32_t guint;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

extern int hf_mp4_full_box_ver;
extern int hf_mp4_full_box_flags;
extern int hf_mp4_mfhd_seq_num;

#define ENC_BIG_ENDIAN 0
#define _U_