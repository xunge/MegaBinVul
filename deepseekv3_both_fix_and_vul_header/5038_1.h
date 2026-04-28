#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#define ENABLE_BGP_VNC 1

#define BGP_ATTR_ENCAP 1
#define BGP_ATTR_VNC 2
#define BGP_ENCAP_TYPE_MPLS 1

#define BGP_ATTR_FLAG_TRANS 0x40
#define BGP_ATTR_FLAG_OPTIONAL 0x80
#define BGP_ATTR_FLAG_EXTLEN 0x10

struct bgp;
struct peer;
struct stream;

struct bgp_attr_encap_subtlv {
    uint8_t type;
    uint16_t length;
    uint8_t *value;
    struct bgp_attr_encap_subtlv *next;
};

struct attr {
    uint16_t encap_tunneltype;
    struct bgp_attr_encap_subtlv *encap_subtlvs;
    struct bgp_attr_encap_subtlv *vnc_subtlvs;
};

void zlog_info(const char *format, ...);
void stream_putc(struct stream *s, uint8_t c);
void stream_putw(struct stream *s, uint16_t w);
void stream_put(struct stream *s, const void *p, size_t size);