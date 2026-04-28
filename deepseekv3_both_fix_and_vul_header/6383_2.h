#include <stdint.h>

typedef struct bitfile bitfile;

typedef struct NeAACDecStruct {
    uint8_t object_type;
    uint8_t sf_index;
} NeAACDecStruct;

typedef struct ic_stream {
    uint8_t window_sequence;
    uint8_t window_shape;
    uint8_t max_sfb;
    uint8_t scale_factor_grouping;
    uint8_t num_swb;
    uint8_t predictor_data_present;
    struct {
        uint8_t limit;
        uint8_t predictor_reset;
        uint8_t predictor_reset_group_number;
        uint8_t prediction_used[16];
    } pred;
    struct {
        uint8_t data_present;
    } ltp;
    struct {
        uint8_t data_present;
    } ltp2;
} ic_stream;

#define DEBUGVAR(a,b,c)
#define LD_DEC
#define MAIN_DEC
#define LTP_DEC
#define ERROR_RESILIENCE
#define ER_OBJECT_START 0
#define LD 0
#define MAIN 1
#define ONLY_LONG_SEQUENCE 0
#define EIGHT_SHORT_SEQUENCE 1

static uint8_t faad_get1bit(bitfile *ld);
static uint8_t faad_getbits(bitfile *ld, int bits);
static uint8_t window_grouping_info(NeAACDecStruct *hDecoder, ic_stream *ics);
static uint8_t max_pred_sfb(uint8_t sf_index);
static uint8_t ltp_data(NeAACDecStruct *hDecoder, ic_stream *ics, void *ltp, bitfile *ld);

#define min(a,b) ((a) < (b) ? (a) : (b))