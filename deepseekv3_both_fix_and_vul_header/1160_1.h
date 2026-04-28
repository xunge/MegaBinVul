#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef int gint;
typedef char gchar;
typedef int gboolean;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_item proto_item;
typedef struct wmem_tree_t wmem_tree_t;

typedef struct _rtmpt_conv_t {
    wmem_tree_t *txids[2];
} rtmpt_conv_t;

typedef struct _rtmpt_packet_t {
    guint8 cmd;
    guint32 len;
    guint32 txid;
    gboolean isresponse;
    gint otherframe;
} rtmpt_packet_t;

#define RTMPT_TYPE_CHUNK_SIZE 0x01
#define RTMPT_TYPE_ABORT_MESSAGE 0x02
#define RTMPT_TYPE_ACKNOWLEDGEMENT 0x03
#define RTMPT_TYPE_WINDOW 0x05
#define RTMPT_TYPE_PEER_BANDWIDTH 0x06
#define RTMPT_TYPE_UCM 0x04
#define RTMPT_TYPE_COMMAND_AMF0 0x14
#define RTMPT_TYPE_COMMAND_AMF3 0x11
#define RTMPT_TYPE_DATA_AMF0 0x12
#define RTMPT_TYPE_DATA_AMF3 0x0F

#define RTMPT_UCM_STREAM_BEGIN 0x00
#define RTMPT_UCM_STREAM_EOF 0x01
#define RTMPT_UCM_STREAM_DRY 0x02
#define RTMPT_UCM_STREAM_ISRECORDED 0x04
#define RTMPT_UCM_SET_BUFFER 0x03

#define TRUE 1
#define FALSE 0

static const struct {
    int value;
    const char *str;
} rtmpt_opcode_vals[] = {{0, NULL}};

static const struct {
    int value;
    const char *str;
} rtmpt_limit_vals[] = {{0, NULL}};

static const struct {
    int value;
    const char *str;
} rtmpt_ucm_vals[] = {{0, NULL}};

#define RTMPT_DEBUG(fmt, ...)
#define wmem_packet_scope() NULL
#define wmem_strdup_printf(scope, fmt, ...) strdup("")
#define val_to_str(val, array, unknown) ""
#define try_val_to_str(val, array) NULL
#define tvb_get_ntohl(tvb, offset) 0
#define tvb_get_ntohs(tvb, offset) 0
#define tvb_get_guint8(tvb, offset) 0
#define tvb_get_string_enc(scope, tvb, offset, len, enc) strdup("")
#define GPOINTER_TO_INT(p) (gint)(p)
#define wmem_tree_lookup32(tree, key) NULL