#include <stdint.h>
#include <string.h>
#include <stddef.h>

#define USBREDIR_VISIBLE
#define USB_REDIR_CAPS_SIZE 32
#define USBREDIRPARSER_SERIALIZE_MAGIC 0x12345678

struct usbredirparser;
struct usbredirparser_priv;
struct usbredirparser_buf {
    uint8_t *buf;
    int pos;
    int len;
    struct usbredirparser_buf *next;
};

struct usbredirparser_priv {
    int32_t our_caps[USB_REDIR_CAPS_SIZE];
    int32_t peer_caps[USB_REDIR_CAPS_SIZE];
    int have_peer_caps;
    int to_skip;
    uint8_t header[64];
    int header_read;
    uint8_t type_header[64];
    int type_header_read;
    uint8_t data[4096];
    int data_read;
    struct usbredirparser_buf *write_buf;
};

int serialize_int(struct usbredirparser_priv *parser, uint8_t **state, uint8_t **pos, uint32_t *remain, uint32_t value, const char *name);
int serialize_data(struct usbredirparser_priv *parser, uint8_t **state, uint8_t **pos, uint32_t *remain, uint8_t *data, uint32_t len, const char *name);