#include <stdint.h>

#define AMF0_NUMBER 0

typedef struct tvbuff tvbuff_t;
typedef struct proto_item proto_item;

typedef uint32_t guint32;
typedef int32_t gint;
typedef uint8_t guint8;

guint32 tvb_reported_length_remaining(tvbuff_t *tvb, gint offset);
guint32 rtmpt_get_amf_length(tvbuff_t *tvb, gint offset, ...);
guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
double tvb_get_ntohieee_double(tvbuff_t *tvb, gint offset);