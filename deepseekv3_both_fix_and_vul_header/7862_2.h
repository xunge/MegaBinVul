#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef int gint;
typedef char gchar;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

#define ENC_ASCII 0

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct dcm_tag_s {
    const gchar *vr;
    const gchar *description;
    gboolean is_retired;
    gboolean add_to_summary;
} dcm_tag_t;

typedef struct {
    guint16 grp;
    guint16 elm;
    gchar *vr;
    guint16 vl_1;
    guint16 vl_2;
    guint32 len_decoded;
    guint32 len_total;
    guint32 len_remaining;
    gboolean is_header_fragmented;
    gboolean is_value_fragmented;
    gchar *desc;
} dcm_open_tag_t;

typedef struct {
    gchar *sop_class_uid;
    gchar *sop_instance_uid;
} dcm_obj_start_t;

typedef struct dcm_state_pdv_s {
    gint syntax;
    dcm_open_tag_t open_tag;
    struct dcm_state_pdv_s *prev;
    gchar *desc;
    dcm_obj_start_t *obj_start;
} dcm_state_pdv_t;

#define MAX_BUF_LEN 1024
#define DCM_EBE 0
#define DCM_ILE 1

extern gboolean global_dcm_seq_subtree;
extern gboolean global_dcm_tag_subtree;
extern int ett_dcm_data_seq;
extern int ett_dcm_data_item;
extern int ett_dcm_data_tag;
extern int hf_dcm_tag;
extern int hf_dcm_tag_vr;
extern int hf_dcm_tag_vl;
extern int hf_dcm_tag_value_byte;

static void *wmem_packet_scope(void) { return NULL; }
static void *wmem_file_scope(void) { return NULL; }
static void *wmem_alloc0(void *scope, size_t size) { return calloc(1, size); }
static char *wmem_strdup(void *scope, const char *src) { return strdup(src); }
static void g_free(void *ptr) { free(ptr); }
static char *g_strdup(const char *str) { return strdup(str); }
static void g_strlcpy(char *dest, const char *src, size_t dest_size) { strncpy(dest, src, dest_size); }
static int g_snprintf(char *str, size_t size, const char *format, ...) { return snprintf(str, size, format); }
static char *g_strstrip(char *str) { return str; }

static guint16 tvb_get_letohs(tvbuff_t *tvb, guint32 offset) { return 0; }
static guint16 tvb_get_ntohs(tvbuff_t *tvb, guint32 offset) { return 0; }
static gchar *tvb_get_string_enc(void *scope, tvbuff_t *tvb, guint32 offset, guint32 length, int encoding) { return NULL; }

static proto_tree *proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, guint32 start, guint32 length, int ett, proto_item **ti, const gchar *text) { return NULL; }
static void proto_tree_add_uint_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, guint32 length, guint32 value, const char *format, ...) {}
static void proto_tree_add_string_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, guint32 length, const char *value, const char *format, ...) {}
static void proto_tree_add_bytes_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, guint32 length, const guint8 *value, const char *format, ...) {}
static void proto_item_append_text(proto_item *ti, const char *format, ...) {}

static gboolean dcm_tag_is_open(dcm_state_pdv_t *pdv, guint32 offset_tag, guint32 offset, guint32 endpos, guint32 len) { return FALSE; }
static dcm_tag_t *dcm_tag_lookup(guint16 grp, guint16 elm) { return NULL; }
static gchar *dcm_tag_summary(guint16 grp, guint16 elm, guint32 vl, const gchar *description, const gchar *vr, gboolean is_retired, gboolean is_implicit) { return NULL; }
static guint32 dissect_dcm_tag_value(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, dcm_state_pdv_t *pdv, guint32 offset, guint16 grp, guint16 elm, guint32 vl, guint32 vl_max, const gchar *vr, gchar **tag_value) { return 0; }
static dcm_obj_start_t *dcm_state_pdv_get_obj_start(dcm_state_pdv_t *pdv) { return NULL; }