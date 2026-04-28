#include <stdint.h>
#include <stdlib.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;

enum rlc_mode {
    RLC_UM,
    RLC_AM,
    RLC_TM
};

struct rlc_frag {
    enum rlc_mode mode;
    packet_info *pinfo;
    uint16_t seq; 
    uint16_t li;
    tvbuff_t *tvb;
    uint16_t offset;
    uint16_t length;
};

typedef uint16_t guint16;

void *se_alloc0(size_t size);
void rlc_frag_assign(struct rlc_frag *frag, enum rlc_mode mode, packet_info *pinfo, guint16 seq, guint16 li);
void rlc_frag_assign_data(struct rlc_frag *frag, tvbuff_t *tvb, guint16 offset, guint16 length);