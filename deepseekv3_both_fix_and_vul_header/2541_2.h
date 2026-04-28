#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>

typedef struct netdissect_options {
    int ndo_eflag;
    int ndo_vflag;
} netdissect_options;

struct pcap_pkthdr {
    unsigned int len;
    unsigned int caplen;
};

struct juniper_l2info_t {
    unsigned int header_len;
    unsigned int cookie_len;
    unsigned int proto;
    unsigned int length;
    unsigned int caplen;
    unsigned int flags;
    unsigned int direction;
    unsigned int pictype;
    unsigned int cookie_type;
    unsigned int bundle;
    uint8_t cookie[8];
};

struct juniper_cookie_table_t {
    const char *s;
    unsigned int pictype;
    unsigned int cookie_len;
};

extern const struct juniper_cookie_table_t *juniper_cookie_table;
extern int juniper_read_tlv_value(const u_char *, uint8_t, uint8_t);
extern int ip_heuristic_guess(netdissect_options *, const u_char *, u_int);

#define ND_TCHECK(a) ND_TCHECK2(a, 1)
#define ND_TCHECK2(a, b)
#define ND_PRINT(args)
#define EXTRACT_24BITS(p) ((uint32_t)((p)[0]) << 16 | (p)[1] << 8 | (p)[2])
#define EXTRACT_16BITS(p) ((uint16_t)((p)[0] << 8 | (p)[1]))
#define EXTRACT_32BITS(p) ((uint32_t)((p)[0] << 24 | (p)[1] << 16 | (p)[2] << 8 | (p)[3]))

#define JUNIPER_BPF_PKT_IN 0x01
#define JUNIPER_BPF_EXT 0x02
#define JUNIPER_BPF_NO_L2 0x04
#define JUNIPER_MGC_NUMBER 0x4d4743
#define JUNIPER_EXT_TLV_OVERHEAD 2
#define JUNIPER_EXT_TLV_IFD_NAME 1
#define JUNIPER_EXT_TLV_IFD_MEDIATYPE 2
#define JUNIPER_EXT_TLV_TTP_IFD_MEDIATYPE 3
#define JUNIPER_EXT_TLV_IFL_ENCAPS 4
#define JUNIPER_EXT_TLV_TTP_IFL_ENCAPS 5
#define JUNIPER_EXT_TLV_IFL_IDX 6
#define JUNIPER_EXT_TLV_IFL_UNIT 7
#define JUNIPER_EXT_TLV_IFD_IDX 8

#define LS_COOKIE_ID 0x01
#define AS_COOKIE_ID 0x02
#define MFR_BE_MASK 0x80
#define ATM2_PKT_TYPE_MASK 0x01
#define JUNIPER_LSQ_L3_PROTO_MASK 0x0F

extern const char *tok2str(const char **, const char *, int);
extern const char *bittok2str(const char **, const char *, int);
extern const char *juniper_direction_values[];
extern const char *jnx_flag_values[];
extern const char *jnx_ext_tlv_values[];
extern const char *juniper_ifmt_values[];
extern const char *juniper_ifle_values[];