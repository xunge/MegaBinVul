#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_DIMENSION 10
#define KEY_COMMENT " /* key field */"
#define RTI_CDR_TK_OCTET 10
#define RTI_CDR_TK_UNION 11
#define RTI_CDR_TK_ENUM 12
#define RTI_CDR_TK_STRUCT 13
#define RTI_CDR_TK_WSTRING 14
#define RTI_CDR_TK_STRING 15
#define RTI_CDR_TK_SEQUENCE 16
#define RTI_CDR_TK_ARRAY 17
#define RTI_CDR_TK_ALIAS 18
#define RTI_CDR_TK_VALUE_PARAM 19
#define RTI_CDR_TK_VALUE 20
#define ENC_ASCII 0

#define LONG_ALIGN(offset) offset = ((offset) + 3) & ~3
#define SHORT_ALIGN(offset) offset = ((offset) + 1) & ~1

typedef int32_t gint;
typedef uint32_t guint;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef int32_t gint32;
typedef int8_t gint8;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct proto_item proto_item;
typedef struct wmem_strbuf_t wmem_strbuf_t;

extern int hf_rtps_union;
extern int hf_rtps_union_case;
extern int hf_rtps_struct;
extern int hf_rtps_member_name;
extern int hf_rtps_sequence;
extern int hf_rtps_array;
extern int hf_rtps_bitfield;
extern int hf_rtps_datatype;

extern const char* rtps_util_typecode_id_to_string(guint32 tk_id);
extern void* wmem_alloc(void* scope, size_t size);
extern void* wmem_packet_scope(void);
extern void* wmem_epan_scope(void);
extern char* tvb_get_string_enc(void* scope, tvbuff_t* tvb, gint offset, gint length, int enc);
extern guint32 tvb_get_guint32(tvbuff_t* tvb, gint offset, guint encoding);
extern guint16 tvb_get_guint16(tvbuff_t* tvb, gint offset, guint encoding);
extern guint8 tvb_get_guint8(tvbuff_t* tvb, gint offset);
extern wmem_strbuf_t* wmem_strbuf_create(void* scope);
extern void wmem_strbuf_append_printf(wmem_strbuf_t* buf, const char* fmt, ...);
extern const char* wmem_strbuf_get_str(wmem_strbuf_t* buf);
extern size_t g_strlcpy(char* dest, const char* src, size_t dest_size);
extern void proto_tree_add_string_format(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, const char* value, const char* format, ...);
extern proto_item* proto_tree_add_uint_format(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, guint32 value, const char* format, ...);
extern void proto_item_set_len(proto_item* item, int length);