#include <stdint.h>
#include <errno.h>
#include <stddef.h>

#define IEEE80211_RADIOTAP_EXT 31
#define IEEE80211_RADIOTAP_RADIOTAP_NAMESPACE 29
#define IEEE80211_RADIOTAP_VENDOR_NAMESPACE 30

#define ITERATOR_VALID(iterator, size) \
    ((iterator->_arg + (size) <= iterator->_next_ns_data) && \
     (iterator->_arg + (size) <= iterator->_max_length))

struct ieee80211_radiotap_namespace {
    int n_bits;
    struct {
        int align;
        int size;
    } *align_size;
};

struct ieee80211_radiotap_iterator {
    unsigned char *_rtheader;
    unsigned char *_next_bitmap;
    unsigned char *_arg;
    unsigned char *_next_ns_data;
    unsigned char *_max_length;
    struct ieee80211_radiotap_namespace *current_namespace;
    const struct ieee80211_radiotap_namespace * const radiotap_ns;
    uint32_t _bitmap_shifter;
    int _arg_index;
    int _reset_on_ext;
    int is_radiotap_ns;
    int this_arg_index;
    unsigned char *this_arg;
    int this_arg_size;
};

typedef uint32_t guint32;

extern struct ieee80211_radiotap_namespace radiotap_ns;
extern void find_ns(struct ieee80211_radiotap_iterator *iterator, guint32 oui, int subns);
extern uint16_t get_unaligned_le16(const void *p);
extern uint32_t get_unaligned_le32(const void *p);