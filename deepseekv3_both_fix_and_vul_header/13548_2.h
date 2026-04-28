#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_DIMENSION 10
#define KEY_COMMENT " /* key field */"
#define ENC_ASCII 0

typedef int32_t gint;
typedef uint32_t guint;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef int32_t gint32;
typedef int8_t gint8;

struct proto_tree;
struct tvbuff_t;
struct proto_item;
struct wmem_strbuf_t;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct proto_item proto_item;
typedef struct wmem_strbuf_t wmem_strbuf_t;

#define RTI_CDR_TK_NULL 0
#define RTI_CDR_TK_SHORT 1
#define RTI_CDR_TK_LONG 2
#define RTI_CDR_TK_USHORT 3
#define RTI_CDR_TK_ULONG 4
#define RTI_CDR_TK_FLOAT 5
#define RTI_CDR_TK_DOUBLE 6
#define RTI_CDR_TK_BOOLEAN 7
#define RTI_CDR_TK_CHAR 8
#define RTI_CDR_TK_OCTET 9
#define RTI_CDR_TK_STRUCT 10
#define RTI_CDR_TK_UNION 11
#define RTI_CDR_TK_ENUM 12
#define RTI_CDR_TK_STRING 13
#define RTI_CDR_TK_SEQUENCE 14
#define RTI_CDR_TK_ARRAY 15
#define RTI_CDR_TK_ALIAS 16
#define RTI_CDR_TK_LONGLONG 17
#define RTI_CDR_TK_ULONGLONG 18
#define RTI_CDR_TK_LONGDOUBLE 19
#define RTI_CDR_TK_WCHAR 20
#define RTI_CDR_TK_WSTRING 21
#define RTI_CDR_TK_VALUE 22
#define RTI_CDR_TK_VALUE_PARAM 23

#define LONG_ALIGN(offset) offset = ((offset) + 3) & ~3
#define SHORT_ALIGN(offset) offset = ((offset) + 1) & ~1

static int hf_rtps_union;
static int hf_rtps_union_case;
static int hf_rtps_struct;
static int hf_rtps_member_name;
static int hf_rtps_sequence;
static int hf_rtps_array;
static int hf_rtps_bitfield;
static int hf_rtps_datatype;

static void *wmem_epan_scope(void) { return NULL; }
static void *wmem_packet_scope(void) { return NULL; }
static void *wmem_alloc(void *scope, size_t size) { return malloc(size); }
static char *tvb_get_string_enc(void *scope, tvbuff_t *tvb, int offset, int length, int enc) { return NULL; }
static guint32 tvb_get_guint32(tvbuff_t *tvb, int offset, guint encoding) { return 0; }
static guint16 tvb_get_guint16(tvbuff_t *tvb, int offset, guint encoding) { return 0; }
static guint8 tvb_get_guint8(tvbuff_t *tvb, int offset) { return 0; }
static proto_item *proto_tree_add_string_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *value, const char *format, ...) { return NULL; }
static proto_item *proto_tree_add_uint_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value, const char *format, ...) { return NULL; }
static void proto_item_set_len(proto_item *item, int length) {}
static wmem_strbuf_t *wmem_strbuf_create(void *scope) { return NULL; }
static void wmem_strbuf_append_printf(wmem_strbuf_t *buf, const char *fmt, ...) {}
static const char *wmem_strbuf_get_str(wmem_strbuf_t *buf) { return NULL; }
static size_t g_strlcpy(char *dest, const char *src, size_t dest_size) { return strlcpy(dest, src, dest_size); }

static const char *rtps_util_typecode_id_to_string(guint32 tk_id) { return ""; }
static gint check_offset_addition(gint offset, gint addition, proto_tree *tree, proto_item *item, tvbuff_t *tvb) { return 0; }