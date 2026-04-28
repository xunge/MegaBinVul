#include <stdint.h>
#include <string.h>

struct ieee80211_radiotap_header {
    uint8_t it_version;
    uint8_t it_pad;
    uint16_t it_len;
    uint32_t it_present;
} __attribute__((packed));

struct ieee80211_radiotap_iterator {
    struct ieee80211_radiotap_header *_rtheader;
    int _max_length;
    int _arg_index;
    uint32_t _bitmap_shifter;
    uint8_t *_arg;
    uint8_t *_next_bitmap;
    uint8_t *_reset_on_ext;
    const struct ieee80211_radiotap_vendor_namespaces *_vns;
    const struct ieee80211_radiotap_namespace *current_namespace;
    uint8_t *this_arg;
    int is_radiotap_ns;
};

struct ieee80211_radiotap_vendor_namespaces {
    const char *vendor_namespace;
    uint16_t vendor_namespace_len;
    const struct ieee80211_radiotap_namespace *ns;
};

struct ieee80211_radiotap_namespace {
    const char *name;
    uint16_t align;
    uint16_t size;
    const struct ieee80211_radiotap_field *fields;
};

struct ieee80211_radiotap_field {
    uint32_t mask;
    uint16_t shift;
    uint8_t align;
    uint8_t size;
};

#define IEEE80211_RADIOTAP_EXT 31
#define EINVAL 22

static inline uint16_t get_unaligned_le16(const void *p)
{
    const uint8_t *ptr = p;
    return ptr[0] | (ptr[1] << 8);
}

static inline uint32_t get_unaligned_le32(const void *p)
{
    const uint8_t *ptr = p;
    return ptr[0] | (ptr[1] << 8) | (ptr[2] << 16) | (ptr[3] << 24);
}

extern const struct ieee80211_radiotap_namespace radiotap_ns;