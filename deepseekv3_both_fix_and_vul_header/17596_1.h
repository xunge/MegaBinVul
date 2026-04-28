#include <stdint.h>
#include <string.h>

typedef uint16_t u16;
typedef uint8_t u8;

#define MWIFIEX_MAX_VSIE_NUM 8
#define MWIFIEX_MAX_VSIE_LEN 256
#define TLV_TYPE_PASSTHROUGH 0x0000

struct mwifiex_ie_types_header {
    u16 type;
    u16 len;
};

struct mwifiex_ie_types_vendor_param_set {
    struct mwifiex_ie_types_header header;
    u8 ie[0];
};

struct mwifiex_vs_ie {
    u16 mask;
    u8 ie[MWIFIEX_MAX_VSIE_LEN];
};

struct mwifiex_adapter;
struct mwifiex_private {
    struct mwifiex_adapter *adapter;
    struct mwifiex_vs_ie vs_ie[MWIFIEX_MAX_VSIE_NUM];
};

struct mwifiex_adapter {
    int dummy;
};

#define ERROR 1
static inline void mwifiex_dbg(struct mwifiex_adapter *adapter, int level, const char *fmt, ...) {}

static inline u16 cpu_to_le16(u16 x) { return x; }
static inline u16 le16_to_cpu(u16 x) { return x; }