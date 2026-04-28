#include <stdint.h>
#include <string.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int32_t gint;
typedef char gchar;

#define AMF0_STRING 0x02
#define AMF0_OBJECT 0x03

typedef struct tvbuff_t tvbuff_t;
typedef struct wmem_allocator_t wmem_allocator_t;
typedef struct proto_item proto_item;

static guint32 rtmpt_get_amf_length(tvbuff_t *tvb, gint offset, ...);
static wmem_allocator_t* wmem_packet_scope(void);
static guint32 tvb_reported_length_remaining(tvbuff_t *tvb, gint offset);
static guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
static guint16 tvb_get_ntohs(tvbuff_t *tvb, gint offset);
static gchar* tvb_get_string_enc(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint length, const char *enc);
static int tvb_strneql(tvbuff_t *tvb, gint offset, const gchar *str, size_t size);

#define ENC_ASCII "ASCII"