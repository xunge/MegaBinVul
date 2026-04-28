#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include <setjmp.h>

typedef int gint32;
#define G_MAXINT32 INT_MAX
#define _U_ __attribute__((unused))
#define ENC_NA 0

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef void* wmem_allocator_t;

typedef struct lbmpdm_offset_table_t {
    gint32 num_flds;
    gint32 *min_set_offset;
    gint32 *offset_list;
} lbmpdm_offset_table_t;

extern int hf_lbmpdm_segment;
extern int hf_lbmpdm_segment_next_hdr;
extern int hf_lbmpdm_segment_flags;
extern int hf_lbmpdm_segment_res;
extern int hf_lbmpdm_segment_len;
extern int hf_lbmpdm_offset_entry;
extern int hf_lbmpdm_offset_entry_id;
extern int hf_lbmpdm_offset_entry_offset;
extern int ett_lbmpdm_segment;
extern int ett_lbmpdm_offset_entry;

#define O_LBMPDM_SEG_HDR_T_NEXT_HDR 0
#define L_LBMPDM_SEG_HDR_T_NEXT_HDR 1
#define O_LBMPDM_SEG_HDR_T_FLAGS 1
#define L_LBMPDM_SEG_HDR_T_FLAGS 1
#define O_LBMPDM_SEG_HDR_T_RES 2
#define L_LBMPDM_SEG_HDR_T_RES 2
#define O_LBMPDM_SEG_HDR_T_LEN 4
#define L_LBMPDM_SEG_HDR_T_LEN 4
#define L_LBMPDM_SEG_HDR_T 8
#define O_LBMPDM_OFFSET_ENTRY_T_ID 0
#define L_LBMPDM_OFFSET_ENTRY_T_ID 4
#define O_LBMPDM_OFFSET_ENTRY_T_OFFSET 4
#define L_LBMPDM_OFFSET_ENTRY_T_OFFSET 4
#define L_LBMPDM_OFFSET_ENTRY_T 8

#define ReportedBoundsError 1
#define THROW(x) longjmp(ex_buf, x)

extern jmp_buf ex_buf;
extern int lbmpdm_get_segment_length(tvbuff_t *tvb, int offset, int encoding, int *datalen);
extern unsigned int lbmpdm_fetch_uint32_encoded(tvbuff_t *tvb, int offset, int encoding);
extern proto_item* proto_tree_add_none_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *format);
extern proto_tree* proto_item_add_subtree(proto_item *item, int ett);
extern proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
extern void* wmem_alloc(wmem_allocator_t *allocator, size_t size);
extern wmem_allocator_t* wmem_packet_scope(void);
extern void* wmem_new0(wmem_allocator_t *allocator, size_t size);

#define wmem_alloc_array(allocator, type, count) ((type*)wmem_alloc(allocator, sizeof(type)*(count)))
#define wmem_new(allocator, type) ((type*)wmem_new0(allocator, sizeof(type)))