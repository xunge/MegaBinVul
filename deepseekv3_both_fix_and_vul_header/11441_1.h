#include <stddef.h>
#include <string.h>

#define SC_ERROR_INVALID_ARGUMENTS 1
#define SC_ERROR_CARD_CMD_FAILED 2
#define SC_SUCCESS 0
#define SC_FORMAT_LEN_SIZE_T "z"

typedef struct sc_context sc_context_t;

struct sc_card {
    void *drv_data;
    sc_context_t *ctx;
};

struct sc_apdu {
    unsigned char *resp;
    size_t resplen;
    unsigned char sw1;
    unsigned char sw2;
};

typedef struct {
    int sm;
} epass2003_exdata;

void LOG_FUNC_CALLED(sc_context_t *ctx);
void LOG_FUNC_RETURN(sc_context_t *ctx, int ret);
int sc_check_sw(struct sc_card *card, unsigned char sw1, unsigned char sw2);
void sc_log(sc_context_t *ctx, const char *fmt, ...);
int decrypt_response(struct sc_card *card, const unsigned char *resp, size_t resplen, unsigned char *plain, size_t *len);