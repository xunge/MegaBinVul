#include <stdint.h>

typedef int32_t gint;
typedef uint32_t guint;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

#define _U_ __attribute__((unused))

extern int hf_mp4_ftyp_brand;
extern int hf_mp4_ftyp_ver;
extern int hf_mp4_ftyp_add_brand;

enum {
    ENC_ASCII,
    ENC_NA,
    ENC_BIG_ENDIAN
};