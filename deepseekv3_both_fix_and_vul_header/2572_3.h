#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef unsigned char u_char;

struct netdissect_options {
    int ndo_vflag;
};

typedef struct netdissect_options netdissect_options;

#define LCPOPT_MIN 1
#define LCPOPT_MAX 21
#define LCPOPT_VEXT 1
#define LCPOPT_MRU 2
#define LCPOPT_ACCM 3
#define LCPOPT_AP 4
#define LCPOPT_QP 5
#define LCPOPT_MN 6
#define LCPOPT_PFC 7
#define LCPOPT_ACFC 8
#define LCPOPT_LD 9
#define LCPOPT_CBACK 13
#define LCPOPT_MLMRRU 17
#define LCPOPT_MLED 19

#define PPP_CHAP 0xc223
#define PPP_PAP 0xc023
#define PPP_EAP 0xc227
#define PPP_SPAP 0xc027
#define PPP_SPAP_OLD 0xc123
#define PPP_LQM 0xc025

#define MEDCLASS_NULL 0
#define MEDCLASS_LOCAL 1
#define MEDCLASS_IPV4 2
#define MEDCLASS_MAC 3
#define MEDCLASS_MNB 4
#define MEDCLASS_PSNDN 5

#define ND_TCHECK2(a, b)
#define ND_TCHECK(a)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ((p)[0] << 8 | (p)[1])
#define EXTRACT_24BITS(p) ((p)[0] << 16 | (p)[1] << 8 | (p)[2])
#define EXTRACT_32BITS(p) ((p)[0] << 24 | (p)[1] << 16 | (p)[2] << 8 | (p)[3])

static const char *lcpconfopts[] = {NULL};
static const char *oui_values[] = {NULL};
static const char *ppptype2str[] = {NULL};
static const char *authalg_values[] = {NULL};
static const char *ppp_callback_values[] = {NULL};

static const char *tok2str(const char *str[], const char *fmt, int val) { return NULL; }
static const char *ipaddr_string(netdissect_options *ndo, const u_char *p) { return NULL; }
static const char *etheraddr_string(netdissect_options *ndo, const u_char *p) { return NULL; }
static void print_unknown_data(netdissect_options *ndo, const u_char *p, const char *s, int len) {}