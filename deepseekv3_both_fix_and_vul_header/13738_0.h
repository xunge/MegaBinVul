#include <stdlib.h>
#include <string.h>

#define CAC_MAX_SIZE 256
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef unsigned char u8;
typedef struct sc_card_t sc_card_t;
typedef struct sc_apdu_t sc_apdu_t;
typedef struct sc_context_t sc_context_t;

struct sc_apdu_t {
    u8 *resp;
    size_t le;
    size_t resplen;
    u8 sw1;
    u8 sw2;
};

struct sc_context_t {
    int dummy;
};

struct sc_card_t {
    sc_context_t *ctx;
};

#define SC_APDU_CASE_2_SHORT 0
#define CAC_INS_GET_CERTIFICATE 0
#define SC_SUCCESS 0
#define SC_ERROR_INTERNAL 1
#define SC_ERROR_OUT_OF_MEMORY 2

#define SC_FUNC_CALLED(ctx, level) 
#define SC_FUNC_RETURN(ctx, level, r) return r

static int sc_transmit_apdu(sc_card_t *card, sc_apdu_t *apdu);
static int sc_check_sw(sc_card_t *card, u8 sw1, u8 sw2);
static void sc_format_apdu(sc_card_t *card, sc_apdu_t *apdu, int case_type, int ins, int p1, int p2);