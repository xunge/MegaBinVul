#include <stdint.h>
#include <sys/time.h>
#include <stddef.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

struct netdissect_options {
    int ndo_vflag;
};

typedef struct netdissect_options netdissect_options;

#define ND_TCHECK2(p, l)
#define ND_PRINT(args)
#define EXTRACT_32BITS(p) (*(uint32_t*)p)
#define MFR_BEC_MASK 0xC0
#define MFR_CTRL_FRAME 0x40
#define MFR_FRAG_FRAME 0x00
#define MFR_B_BIT 0x80
#define MFR_CTRL_IE_MAGIC_NUM 1
#define MFR_CTRL_IE_BUNDLE_ID 2
#define MFR_CTRL_IE_LINK_ID 3
#define MFR_CTRL_IE_TIMESTAMP 4
#define MFR_CTRL_IE_VENDOR_EXT 5
#define MFR_CTRL_IE_CAUSE 6
#define MFR_ID_STRING_MAXLEN 32

struct ie_tlv_header_t {
    uint8_t type;
    uint8_t length;
};

const char *bittok2str(const char *strings, const char *none, int value);
const char *tok2str(const char *strings, const char *fmt, int value);
void safeputchar(netdissect_options *ndo, char c);
void ts_print(netdissect_options *ndo, const struct timeval *tv);
void print_unknown_data(netdissect_options *ndo, const uint8_t *data, const char *prefix, int len);
void fr_print(netdissect_options *ndo, const u_char *p, u_int length);

static const char *frf_flag_values[] = { NULL };
static const char *mfr_ctrl_msg_values[] = { NULL };
static const char *mfr_ctrl_ie_values[] = { NULL };