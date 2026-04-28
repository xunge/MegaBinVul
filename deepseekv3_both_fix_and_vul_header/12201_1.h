#include <assert.h>
#include <string.h>
#include <stdint.h>

#define SC_MAX_APDU_BUFFER_SIZE 256
#define SC_SUCCESS 0
#define SC_ERROR_NOT_SUPPORTED 1
#define SC_ERROR_WRONG_LENGTH 2
#define SC_ERROR_WRONG_PADDING 3
#define SC_ERROR_BUFFER_TOO_SMALL 4

#define SC_ALGORITHM_AES 1
#define SC_ALGORITHM_AES_ECB 0x01
#define SC_ALGORITHM_AES_CBC 0x02
#define SC_ALGORITHM_AES_CBC_PAD 0x04

#define SC_APDU_CASE_4_SHORT 0x04

typedef uint8_t u8;

struct sc_card;
struct sc_context;
struct sc_apdu;

struct sc_card {
    struct sc_context *ctx;
    void *drv_data;
};

struct sc_context {
    void *unused;
};

struct sc_apdu {
    u8 cla;
    u8 ins;
    u8 p1;
    u8 p2;
    size_t le;
    size_t lc;
    size_t datalen;
    u8 *data;
    size_t resplen;
    u8 *resp;
    u8 sw1;
    u8 sw2;
};

typedef struct {
    int algorithm;
    int algorithm_flags;
    size_t sym_crypt_buffer_len;
    size_t sym_plain_buffer_len;
    u8 sym_crypt_buffer[SC_MAX_APDU_BUFFER_SIZE];
    u8 sym_plain_buffer[SC_MAX_APDU_BUFFER_SIZE];
} myeid_private_data_t;

#define LOG_FUNC_CALLED(ctx)
#define LOG_FUNC_RETURN(ctx, ret) return ret
#define LOG_TEST_RET(ctx, ret, msg) if (ret) return ret
#define sc_log(ctx, fmt, ...)

static size_t sc_get_max_send_size(struct sc_card *card) { return 0; }
static size_t sc_get_max_recv_size(struct sc_card *card) { return 0; }
static void sc_format_apdu(struct sc_card *card, struct sc_apdu *apdu, int case_type, int ins, int p1, int p2) {}
static int sc_transmit_apdu(struct sc_card *card, struct sc_apdu *apdu) { return 0; }
static int sc_check_sw(struct sc_card *card, u8 sw1, u8 sw2) { return 0; }