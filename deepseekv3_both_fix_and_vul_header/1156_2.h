#include <stdint.h>
#include <stddef.h>

#define MAX_AMF_ITERATIONS 1000

typedef uint32_t guint32;
typedef int32_t gint;
typedef uint8_t guint8;
typedef uint32_t guint;
typedef uint16_t guint16;

enum {
    AMF0_NUMBER,
    AMF0_BOOLEAN,
    AMF0_STRING,
    AMF0_OBJECT,
    AMF0_NULL,
    AMF0_UNDEFINED,
    AMF0_UNSUPPORTED,
    AMF0_ECMA_ARRAY,
    AMF0_END_OF_OBJECT,
    AMF0_DATE,
    AMF0_LONG_STRING,
    AMF0_XML,
    AMF0_INT64
};

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

extern expert_field ei_amf_loop;

guint32 tvb_reported_length_remaining(tvbuff_t *tvb, gint offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, gint offset);
guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
guint32 tvb_get_ntohl(tvbuff_t *tvb, gint offset);
void expert_add_info(void *null, proto_item *pi, expert_field *field);