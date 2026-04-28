#include <stdint.h>
#include <string.h>

#define EINVAL 22
#define IEEE80211_RADIOTAP_EXT 31
#define RADIOTAP_SUPPORT_OVERRIDES

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;

struct ieee80211_radiotap_header {
    guint8 it_version;
    guint8 it_pad;
    guint16 it_len;
    guint32 it_present;
};

struct ieee80211_radiotap_vendor_namespaces {
    const char *name;
    guint16 id;
    guint16 vendor_oui;
    guint16 vendor_subns;
};

struct ieee80211_radiotap_iterator {
    struct ieee80211_radiotap_header *_rtheader;
    int _max_length;
    int _arg_index;
    guint32 _bitmap_shifter;
    guint8 *_arg;
    int _reset_on_ext;
    guint8 *_next_ns_data;
    guint32 *_next_bitmap;
    const struct ieee80211_radiotap_vendor_namespaces *_vns;
    const struct ieee80211_radiotap_vendor_namespaces *current_namespace;
    int is_radiotap_ns;
#ifdef RADIOTAP_SUPPORT_OVERRIDES
    int n_overrides;
    void *overrides;
#endif
    guint8 *this_arg;
};

static const struct ieee80211_radiotap_vendor_namespaces radiotap_ns = {0};

static inline guint16 get_unaligned_le16(const void *p)
{
    const guint8 *ptr = p;
    return ptr[0] | (ptr[1] << 8);
}

static inline guint32 get_unaligned_le32(const void *p)
{
    const guint8 *ptr = p;
    return ptr[0] | (ptr[1] << 8) | (ptr[2] << 16) | (ptr[3] << 24);
}

#define ITERATOR_VALID(iterator, size) \
    ((iterator)->_arg + (size) <= (guint8 *)(iterator)->_rtheader + (iterator)->_max_length)