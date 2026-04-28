#include <stdint.h>
#include <string.h>

#define ERR_DECODE (-1)

struct ntlm_ctx;
struct ntlm_buffer {
    uint8_t *data;
    size_t length;
};

struct wire_av_pair {
    uint16_t av_id;
    uint16_t av_len;
    uint8_t value[];
};

#define MSV_AV_EOL 0
#define MSV_AV_NB_COMPUTER_NAME 1
#define MSV_AV_NB_DOMAIN_NAME 2
#define MSV_AV_DNS_COMPUTER_NAME 3
#define MSV_AV_DNS_DOMAIN_NAME 4
#define MSV_AV_DNS_TREE_NAME 5
#define MSV_AV_FLAGS 6
#define MSV_AV_TIMESTAMP 7
#define MSV_AV_SINGLE_HOST 8
#define MSV_AV_TARGET_NAME 9
#define MSV_AV_CHANNEL_BINDINGS 10

static inline uint16_t le16toh(uint16_t v) { return v; }
static inline uint32_t le32toh(uint32_t v) { return v; }
static inline uint64_t le64toh(uint64_t v) { return v; }

#define safefree(ptr) free(ptr)

int ntlm_decode_av_pair_u16l_str(struct ntlm_ctx *ctx, struct wire_av_pair *av_pair, char **str);