#include <string.h>

#define SC_MAX_SERIALNR 32
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SC_SUCCESS 0
#define SC_ERROR_FILE_NOT_FOUND 1
#define SC_LOG_DEBUG_NORMAL 0
#define SC_FUNC_CALLED(ctx, level)
#define SC_FUNC_RETURN(ctx, level, ret) return ret

typedef struct {
    size_t len;
    unsigned char value[SC_MAX_SERIALNR];
} sc_serial_number_t;

typedef struct {
    size_t cac_id_len;
    unsigned char cac_id[SC_MAX_SERIALNR];
} cac_private_data_t;

typedef struct {
    void *ctx;
    sc_serial_number_t serialnr;
    cac_private_data_t *drv_data;
} sc_card_t;

#define CAC_DATA(card) ((cac_private_data_t *)(card)->drv_data)