#include <stdint.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint;
typedef int32_t gint32;
typedef int gint;

typedef enum {
    TLV_LEN_LEN8,
    TLV_LEN_LEN16
} tlv_len_len_e;

#define THREAD_MC_INVALID_CHAN_COUNT 0
#define THREAD_TLV_LENGTH_ESC 0xFF
#define THREAD_MC_TLV_CHANNEL_MASK 0x0A

typedef struct tvbuff_t tvbuff_t;

static int tvb_offset_exists(tvbuff_t *tvb, guint offset);
static guint8 tvb_get_guint8(tvbuff_t *tvb, guint offset);
static guint16 tvb_get_ntohs(tvbuff_t *tvb, guint offset);
static int count_bits_in_byte(guint8 byte);