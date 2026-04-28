#include <stdint.h>

typedef int32_t gint;
typedef uint32_t guint;

extern int hf_mp4_full_box_ver;
extern int hf_mp4_full_box_flags;
extern int hf_mp4_full_box_flags_media_data_location;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

#define ENC_BIG_ENDIAN 0
#define _U_