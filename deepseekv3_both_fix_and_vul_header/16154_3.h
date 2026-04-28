#include <assert.h>
#include <string.h>

typedef unsigned char u8;

#define SC_MAX_APDU_BUFFER_SIZE 256
#define SC_APDU_CASE_4_EXT 0
#define SC_APDU_CASE_4_SHORT 0
#define SC_ERROR_INVALID_ARGUMENTS 0
#define SC_ALGORITHM_RSA_PAD_PKCS1 0x01
#define SC_LOG_DEBUG_VERBOSE 0
#define SC_CARD_TYPE_TCOS_V3 1

typedef struct sc_context_t sc_context_t;
typedef struct sc_apdu_t sc_apdu_t;
typedef struct tcos_data tcos_data;
typedef struct sc_card_t sc_card_t;

struct sc_apdu_t {
    u8 *resp;
    size_t resplen;
    u8 *data;
    size_t datalen;
    size_t lc;
    size_t le;
    int sw1;
    int sw2;
};

struct tcos_data {
    unsigned int pad_flags;
};

struct sc_card_t {
    sc_context_t *ctx;
    int type;
    void *drv_data;
};

#define LOG_FUNC_CALLED(ctx)
#define LOG_TEST_RET(ctx, r, msg) if (r < 0) return r
#define SC_FUNC_RETURN(ctx, level, val) return val

static int sc_transmit_apdu(sc_card_t *card, sc_apdu_t *apdu);
static int sc_check_sw(sc_card_t *card, int sw1, int sw2);
static void sc_format_apdu(sc_card_t *card, sc_apdu_t *apdu, int case_type, int ins, int p1, int p2);
static void sc_log(sc_context_t *ctx, const char *fmt, ...);