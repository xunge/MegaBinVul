#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef int gboolean;

typedef struct _usb_conv_info_t {
    void *class_data;
    int class_data_type;
} usb_conv_info_t;

typedef struct _usb_ms_conv_info_t {
    void *itl;
    void *itlq;
} usb_ms_conv_info_t;

typedef struct _itl_nexus_t {
    int cmdset;
    void *conversation;
} itl_nexus_t;

typedef struct _itlq_nexus_t {
    int lun;
    int scsi_opcode;
    int task_flags;
    guint32 data_length;
    guint32 bidir_data_length;
    void *fc_time;
    int first_exchange_frame;
    int last_exchange_frame;
    int flags;
    int alloc_len;
    void *extra_data;
} itlq_nexus_t;

typedef struct _tvbuff_t {
    // tvbuff structure placeholder
} tvbuff_t;

typedef struct _packet_info {
    int srcport;
    void *cinfo;
    int num;
    void *abs_ts;
} packet_info;

typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;

#define NO_ENDPOINT 0
#define USB_CONV_MASS_STORAGE 0
#define SCSI_DEV_UNKNOWN 0
#define SCSI_DATA_READ 1
#define SCSI_DATA_WRITE 2
#define COL_PROTOCOL 0
#define COL_INFO 0
#define ENC_LITTLE_ENDIAN 0

extern int proto_usb_ms;
extern int ett_usb_ms;
extern int hf_usb_ms_dCBWSignature;
extern int hf_usb_ms_dCBWTag;
extern int hf_usb_ms_dCBWDataTransferLength;
extern int hf_usb_ms_dCBWFlags;
extern int hf_usb_ms_dCBWTarget;
extern int hf_usb_ms_dCBWLUN;
extern int hf_usb_ms_dCBWCBLength;
extern int hf_usb_ms_dCSWSignature;
extern int hf_usb_ms_dCSWDataResidue;
extern int hf_usb_ms_dCSWStatus;

static inline void *wmem_new(void *scope, size_t size) { return malloc(size); }
static inline void *wmem_file_scope(void) { return NULL; }
static inline void *wmem_tree_new(void *scope) { return NULL; }
static inline void *wmem_tree_lookup32(void *tree, guint32 key) { return NULL; }
static inline void *wmem_tree_lookup32_le(void *tree, guint32 key) { return NULL; }
static inline void wmem_tree_insert32(void *tree, guint32 key, void *value) {}
static inline void col_set_str(void *cinfo, int column, const char *str) {}
static inline void col_clear(void *cinfo, int column) {}
static inline proto_item *proto_tree_add_protocol_format(proto_tree *tree, int proto, tvbuff_t *tvb, int start, int length, const char *format) { return NULL; }
static inline proto_tree *proto_item_add_subtree(proto_item *item, int ett) { return NULL; }
static inline guint32 tvb_get_letohl(tvbuff_t *tvb, int offset) { return 0; }
static inline guint8 tvb_get_guint8(tvbuff_t *tvb, int offset) { return 0; }
static inline int tvb_reported_length(tvbuff_t *tvb) { return 0; }
static inline int tvb_captured_length(tvbuff_t *tvb) { return 0; }
static inline int tvb_captured_length_remaining(tvbuff_t *tvb, int offset) { return 0; }
static inline tvbuff_t *tvb_new_subset(tvbuff_t *tvb, int offset, int length, int reported_length) { return NULL; }
static inline void proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding) {}
static inline void dissect_scsi_cdb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int scsi_device_type, itlq_nexus_t *itlq, itl_nexus_t *itl) {}
static inline void dissect_scsi_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, itlq_nexus_t *itlq, itl_nexus_t *itl, guint8 status) {}
static inline void dissect_scsi_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean is_request, itlq_nexus_t *itlq, itl_nexus_t *itl, int offset) {}

#define wmem_new(scope, type) ((type*)malloc(sizeof(type)))