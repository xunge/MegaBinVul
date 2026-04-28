#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define IEEE_MAX_IE_SIZE 256
#define MWIFIEX_AUTO_IDX_MASK 0xffff
#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22

typedef uint8_t u8;
typedef uint16_t u16;

struct ieee_types_header {
    u8 element_id;
    u8 len;
};

struct mwifiex_ie {
    u16 ie_index;
    u16 mgmt_subtype_mask;
    u16 ie_length;
    u8 ie_buffer[IEEE_MAX_IE_SIZE];
};

static inline u16 le16_to_cpu(u16 val) { return val; }
static inline u16 cpu_to_le16(u16 val) { return val; }
static inline void le16_unaligned_add_cpu(u16 *p, u16 val) { *p += val; }

static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
const u8 *cfg80211_find_vendor_ie(unsigned int oui, u8 oui_type, const u8 *ies, int ies_len);