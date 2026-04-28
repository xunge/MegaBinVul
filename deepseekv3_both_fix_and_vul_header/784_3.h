#include <stdint.h>
#include <netinet/in.h>

typedef struct netdissect_options {
    int ndo_Hflag;
    int ndo_eflag;
    int ndo_suppress_default_print;
    const u_char *ndo_snapend;
} netdissect_options;

struct lladdr_info {
    const char *(*addr_string)(netdissect_options *, const u_char *);
    const u_char *addr;
};

extern const char *etheraddr_string(netdissect_options *, const u_char *);
extern uint16_t EXTRACT_LE_16BITS(const void *);
extern u_int extract_header_length(netdissect_options *, uint16_t);
extern u_int extract_mesh_header_length(const u_char *);
extern void ieee_802_11_hdr_print(netdissect_options *, uint16_t, const u_char *, u_int, u_int);
extern void get_mgmt_src_dst_mac(const u_char *, const u_char **, const u_char **);
extern int mgmt_body_print(netdissect_options *, uint16_t, const u_char *, const u_char *, u_int);
extern int ctrl_body_print(netdissect_options *, uint16_t, const u_char *);
extern void get_data_src_dst_mac(uint16_t, const u_char *, const u_char **, const u_char **);
extern int llc_print(netdissect_options *, const u_char *, u_int, u_int, const struct lladdr_info *, const struct lladdr_info *);
extern int wep_print(netdissect_options *, const u_char *);

#define IEEE802_11_FC_LEN 2
#define T_MGMT 0
#define T_CTRL 1
#define T_DATA 2
#define FC_TYPE(fc) (((fc) >> 2) & 0x3)
#define FC_SUBTYPE(fc) (((fc) >> 4) & 0xf)
#define FC_PROTECTED(fc) ((fc) & 0x40)
#define DATA_FRAME_IS_QOS(subtype) ((subtype) & 0x8)
#define DATA_FRAME_IS_NULL(subtype) ((subtype) & 0x4)

#define ND_PRINT(args)
#define ND_DEFAULTPRINT(p, caplen)
#define roundup2(x, y) (((x) + ((y)-1)) & ~((y)-1))

extern const char *tstr;