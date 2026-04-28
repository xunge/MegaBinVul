#include <stdint.h>

typedef struct {
    uint8_t id[20];
    uint8_t len;
} lsquic_cid_t;

struct conn_cid_elem {
    lsquic_cid_t cce_cid;
    unsigned cce_flags;
};

struct lsquic_conn {
    struct conn_cid_elem *cn_cces;
    unsigned cn_n_cces;
    unsigned cn_cur_cce_idx;
    uint32_t cn_cces_mask;
};

struct ietf_full_conn {
    struct lsquic_conn ifc_conn;
};

#define LSQ_DEBUG(...)
#define LSQ_DEBUGC(...)
#define ABORT_WARN(...)
#define LOG_SCIDS(...)
#define CID_FMT "s"
#define CID_BITS(cid) ""
#define CN_SCID(conn) ((lsquic_cid_t){0})
#define CCE_USED (1u << 0)
#define END_OF_CCES(conn) ((conn)->cn_cces + (conn)->cn_n_cces)
#define LSQUIC_CIDS_EQ(a, b) (0)