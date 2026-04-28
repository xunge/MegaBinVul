#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define COAP_OBJECT_SECURITY_NON_COMPRESSED_MASK 0x01
#define COAP_OBJECT_SECURITY_EXPAND_MASK 0x02
#define COAP_OBJECT_SECURITY_SIGNATURE_MASK 0x04
#define COAP_OBJECT_SECURITY_KID_CONTEXT_MASK 0x08
#define COAP_OBJECT_SECURITY_KID_MASK 0x10
#define COAP_OBJECT_SECURITY_PIVLEN_MASK 0xE0

#define FALSE false
#define TRUE true
#define NULL ((void*)0)
#define ENC_BIG_ENDIAN 0
#define ENC_NA 1

typedef uint8_t guint8;
typedef int32_t gint;
typedef bool gboolean;

static const char *nullstr = "(null)";

typedef struct {
    guint8 *piv;
    guint8 piv_len;
    guint8 *kid_context;
    guint8 kid_context_len;
    guint8 *kid;
    guint8 kid_len;
} oscore_info;

typedef struct {
    gboolean object_security;
    oscore_info *oscore_info;
} coap_info;

typedef struct {
    struct {
        int opt_object_security_non_compressed;
        int opt_object_security_expand;
        int opt_object_security_signature;
        int opt_object_security_kid_context_present;
        int opt_object_security_kid_present;
        int opt_object_security_piv_len;
        int opt_object_security_piv;
        int opt_object_security_kid_context_len;
        int opt_object_security_kid_context;
        int opt_object_security_kid;
    } hf;
    struct {
        int opt_object_security_bad;
    } ei;
} coap_common_dissect_t;

typedef struct tvbuff tvbuff_t;
typedef struct proto_item proto_item;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;

void proto_item_append_text(proto_item *item, const char *format, ...);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void expert_add_info_format(packet_info *pinfo, proto_tree *tree, int *ei, const char *format, ...);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
void *tvb_memdup(void *scope, tvbuff_t *tvb, int offset, int length);
char *bytes_to_str(void *scope, const guint8 *bytes, int len);