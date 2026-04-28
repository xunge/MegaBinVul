#include <stdint.h>
#include <string.h>

#define FASTCALL
#define WORD_EOF (-1)
#define SLO 0
#define SLS 0
#define LIMIT_ONES 0
#define HYBRID_FLAG 0
#define HYBRID_BITRATE 0
#define CLEAR(x) memset(&(x), 0, sizeof(x))
#define GET_MED(x) 0
#define DEC_MED0()
#define INC_MED0()
#define DEC_MED1()
#define INC_MED1()
#define DEC_MED2()
#define INC_MED2()

struct entropy_data {
    int32_t median[3];
    int32_t slow_level;
    int32_t error_limit;
};

struct bs {
    uint8_t *ptr;
    uint8_t *end;
    uint32_t sr;
    int bc;
    void (*wrap)(struct bs*);
};

struct wavpack_header {
    uint32_t flags;
};

typedef struct WavpackStream {
    struct {
        struct entropy_data c[2];
        int32_t holding_zero;
        int32_t holding_one;
        uint32_t zeros_acc;
    } w;
    struct bs wvbits;
    struct bs wvcbits;
    struct wavpack_header wphdr;
} WavpackStream;

int getbit(struct bs *bs);
uint32_t read_code(struct bs *bs, uint32_t maxcode);
int bs_is_open(struct bs *bs);
int wp_log2(uint32_t value);
void update_error_limit(WavpackStream *wps);