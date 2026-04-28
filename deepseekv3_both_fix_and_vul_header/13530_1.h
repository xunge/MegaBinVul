#include <stddef.h>
#include <stdint.h>

typedef unsigned char u8;
typedef struct sc_card_t sc_card_t;
typedef struct sc_apdu_t sc_apdu_t;
typedef struct sc_context_t sc_context_t;

struct sc_apdu_t {
    int apdu_case;
    unsigned char cla, ins, p1, p2;
    const unsigned char *data;
    size_t lc;
    size_t le;
    unsigned char *resp;
    size_t resplen;
};

struct sc_card_t {
    int type;
    sc_context_t *ctx;
};

#define SC_MAX_APDU_BUFFER_SIZE 256
#define SC_APDU_CASE_2_SHORT 1
#define SC_CARD_TYPE_CARDOS_M4_3 1
#define SC_CARD_TYPE_CARDOS_M4_4 2

int sc_transmit_apdu(sc_card_t *card, sc_apdu_t *apdu);
void sc_format_apdu(sc_card_t *card, sc_apdu_t *apdu, int case_type, int ins, int p1, int p2);
const u8 *sc_asn1_find_tag(sc_context_t *ctx, const u8 *in, size_t inlen, u8 tag, size_t *outlen);
int LOG_TEST_RET(sc_context_t *ctx, int r, const char *msg);