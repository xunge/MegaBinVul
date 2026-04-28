#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <endian.h>

#define MAX_WCP_BUF_LEN 4096
#define MAX_WIN_BUF_LEN 8192
#define WCP_OFFSET_MASK 0x0FFF
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;

typedef enum {
    CIRCUIT_TYPE_A,
    CIRCUIT_TYPE_B
} circuit_type;

typedef struct {
    guint8 buffer[MAX_WIN_BUF_LEN];
    guint8 *buf_cur;
    guint32 initialized;
} wcp_window_t;

typedef struct {
    guint8 buffer[MAX_WCP_BUF_LEN];
    int len;
} wcp_pdata_t;

typedef struct tvbuff_t {
    int dummy;
} tvbuff_t;

typedef struct packet_info {
    struct {
        struct {
            int visited;
        } flags;
    } *fd;
} packet_info;

typedef struct proto_tree {
    int dummy;
} proto_tree;

typedef struct proto_item {
    int dummy;
} proto_item;

typedef struct wmem_allocator_t {
    int dummy;
} wmem_allocator_t;

extern int hf_wcp_compressed_data;
extern int hf_wcp_long_run;
extern int hf_wcp_short_run;
extern int hf_wcp_offset;
extern int hf_wcp_long_len;
extern int hf_wcp_short_len;
extern int hf_wcp_comp_bits;
extern int ett_wcp_comp_data;
extern int ett_wcp_field;
extern int ei_wcp_compressed_data_exceeds;
extern int ei_wcp_invalid_window_offset;
extern int ei_wcp_uncompressed_data_exceeds;
extern int proto_wcp;

extern int tvb_reported_length(tvbuff_t *tvb);
extern void *tvb_memcpy(tvbuff_t *tvb, void *dst, int offset, int length);
extern uint16_t pntoh16(const void *src);
extern proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, 
                                     int start, int length, int encoding);
extern proto_tree *proto_item_add_subtree(proto_item *item, int ett);
extern void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb,
                              int start, int length, guint32 value);
extern void expert_add_info_format(packet_info *pinfo, proto_item *item, 
                                  int *ei, const char *fmt, ...);
extern wcp_window_t *get_wcp_window_ptr(packet_info *pinfo, circuit_type ctype, guint32 circuit_id);
extern guint8 *decompressed_entry(guint8 *dst, guint16 data_offset, guint16 data_cnt, 
                                int *len, wcp_window_t *buf_ptr);
extern void *p_get_proto_data(wmem_allocator_t *scope, packet_info *pinfo, int proto, int id);
extern wmem_allocator_t *wmem_file_scope(void);
extern void REPORT_DISSECTOR_BUG(const char *msg);
extern void *wmem_new0(wmem_allocator_t *allocator, size_t size);
extern void p_add_proto_data(wmem_allocator_t *scope, packet_info *pinfo, int proto, int id, void *data);
extern tvbuff_t *tvb_new_child_real_data(tvbuff_t *parent, const guint8 *data, guint32 length, guint32 reported_length);
extern void add_new_data_source(packet_info *pinfo, tvbuff_t *tvb, const char *name);

#define wmem_new(allocator, type) ((type *)wmem_new0(allocator, sizeof(type)))