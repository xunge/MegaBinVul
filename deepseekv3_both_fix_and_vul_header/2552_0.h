#include <stddef.h>
#include <sys/types.h>

typedef struct netdissect_options netdissect_options;

struct pkt_hdr {
    u_int ph_flags;
    u_int ph_type;
};

#define ND_TTEST(ptr) 1
#define ND_PRINT(args) 

extern char *tstr;

enum {
    PT_KILL,
    PT_ID,
    PT_RREQ,
    PT_RREP,
    PT_DRAWOP,
    PT_PREQ,
    PT_PREP
};

struct pkt_id;
struct pkt_rreq;
struct pkt_rrep;
struct pkt_dop;
struct pkt_preq;
struct pkt_prep;

int wb_id(netdissect_options *, const struct pkt_id *, u_int);
int wb_rreq(netdissect_options *, const struct pkt_rreq *, u_int);
int wb_rrep(netdissect_options *, const struct pkt_rrep *, u_int);
int wb_drawop(netdissect_options *, const struct pkt_dop *, u_int);
int wb_preq(netdissect_options *, const struct pkt_preq *, u_int);
int wb_prep(netdissect_options *, const struct pkt_prep *, u_int);