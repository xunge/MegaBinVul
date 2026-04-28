#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>

typedef struct ThreadVars ThreadVars;
typedef struct DecodeThreadVars DecodeThreadVars;
typedef struct PacketQueue PacketQueue;

typedef struct {
    uint8_t rh_type;
    uint16_t fh_offset;
    uint8_t fh_more_frags_set;
} IPV6ExtHdrs;

typedef struct {
    IPV6ExtHdrs ip6eh;
    uint8_t flags;
} Packet;

typedef struct {
    uint8_t ip6hao_type;
    uint8_t ip6hao_len;
    uint8_t ip6hao_hoa[16];
} IPV6OptHAO;

typedef struct {
    uint8_t ip6ra_type;
    uint8_t ip6ra_len;
    uint16_t ip6ra_value;
} IPV6OptRA;

typedef struct {
    uint8_t ip6j_type;
    uint8_t ip6j_len;
    uint32_t ip6j_payload_len;
} IPV6OptJumbo;

typedef struct {
    uint8_t ip6f_nxt;
    uint8_t ip6f_reserved;
    uint16_t ip6f_offlg;
    uint32_t ip6f_ident;
} IPV6FragHdr;

typedef struct {
    uint32_t ip6e_spi;
    uint32_t ip6e_seq;
} IPV6EspHdr;

typedef struct {
    uint8_t ip6ah_nxt;
    uint8_t ip6ah_len;
    uint16_t ip6ah_reserved;
    uint32_t ip6ah_spi;
    uint32_t ip6ah_seq;
} IPV6AuthHdr;

#define SCEnter()
#define SCReturn
#define SCLogDebug(...)
#define ENGINE_SET_EVENT(p, e)
#define ENGINE_SET_INVALID_EVENT(p, e)
#define IPV6_GET_NH(p) 0
#define IPV6_SET_L4PROTO(p, nh)
#define IPV6_EXTHDR_SET_RH(p)
#define IPV6_EXTHDR_SET_FH(p)
#define IPV6_EXTHDR_ISSET_FH(p) 0
#define IPV6_EXTHDR_DUPL_RH
#define IPV6_EXTHDR_RH_TYPE_0
#define IPV6_EXTHDR_DUPL_HH
#define IPV6_EXTHDR_DUPL_DH
#define IPV6_EXTHDR_INVALID_OPTLEN
#define IPV6_EXTHDR_ZERO_LEN_PADN
#define IPV6_EXTHDR_DUPL_EH
#define IPV6_EXTHDR_DUPL_AH
#define IPV6_EXTHDR_AH_RES_NOT_NULL
#define IPV6_EXTHDR_USELESS_FH
#define IPV6_HOPOPTS_UNKNOWN_OPT
#define IPV6_DSTOPTS_UNKNOWN_OPT
#define IPV6_HOPOPTS_ONLY_PADDING
#define IPV6_DSTOPTS_ONLY_PADDING
#define IPV6_DATA_AFTER_NONE_HEADER
#define IPV6_TRUNC_EXTHDR
#define IPV6_WITH_ICMPV4
#define IPV6_UNKNOWN_NEXT_HEADER
#define IPV6_FH_NON_ZERO_RES_FIELD
#define PKT_IS_FRAGMENT (1 << 0)

#define IPV6OPT_PAD1 0
#define IPV6OPT_PADN 1
#define IPV6OPT_RA 5
#define IPV6OPT_JUMBO 194
#define IPV6OPT_HAO 201

#define IPPROTO_HIP 139
#define IPPROTO_SHIM6 140

#define SCNtohs(x) ntohs(x)
#define SCNtohl(x) ntohl(x)

void DecodeTCP(ThreadVars *tv, DecodeThreadVars *dtv, Packet *p, uint8_t *pkt, uint16_t len, PacketQueue *pq);
void DecodeUDP(ThreadVars *tv, DecodeThreadVars *dtv, Packet *p, uint8_t *pkt, uint16_t len, PacketQueue *pq);
void DecodeICMPV6(ThreadVars *tv, DecodeThreadVars *dtv, Packet *p, uint8_t *pkt, uint16_t len, PacketQueue *pq);
void DecodeSCTP(ThreadVars *tv, DecodeThreadVars *dtv, Packet *p, uint8_t *pkt, uint16_t len, PacketQueue *pq);
void DecodeIPv4inIPv6(ThreadVars *tv, DecodeThreadVars *dtv, Packet *p, uint8_t *pkt, uint16_t len, PacketQueue *pq);
void DecodeIPV6FragHeader(Packet *p, uint8_t *pkt, uint16_t hdrextlen, uint16_t plen, uint16_t prev_hdrextlen);