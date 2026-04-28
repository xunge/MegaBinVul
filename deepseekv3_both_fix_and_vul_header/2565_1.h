#include <stdint.h>
#include <arpa/inet.h>

typedef struct netdissect_options netdissect_options;

#define ND_PRINT(args)
#define ND_TCHECK2(ptr, len)
#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))
#define EXTRACT_32BITS(p) ((uint32_t)ntohl(*(const uint32_t *)(p)))

#define ISIS_SUBTLV_SPB_MCID 1
#define ISIS_SUBTLV_SPB_DIGEST 2
#define ISIS_SUBTLV_SPB_BVID 3
#define ISIS_SUBTLV_SPB_MCID_MIN_LEN 32
#define ISIS_SUBTLV_SPB_DIGEST_MIN_LEN 33
#define ISIS_SUBTLV_SPB_BVID_MIN_LEN 6

struct isis_subtlv_spb_mcid {
    uint8_t mcid[16];
    uint8_t aux_mcid[16];
};

extern const char *tstr;
extern const char *tok2str(const char * const *, const char *, int);
extern void isis_print_mcid(netdissect_options *, const uint8_t *);