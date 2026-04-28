#include <stdint.h>
#include <stddef.h>

typedef struct scsi_task_data_t scsi_task_data_t;
typedef struct scsi_osd_extra_data_t scsi_osd_extra_data_t;
typedef struct itlq_t itlq_t;

struct itlq_t {
    void *extra_data;
};

struct scsi_task_data_t {
    itlq_t *itlq;
};

struct scsi_osd_extra_data_t {
    uint16_t svcaction;
    uint32_t continuation_length;
};

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;

typedef struct packet_info packet_info;
typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

extern int hf_scsi_osd2_cdb_continuation_format;
extern int hf_scsi_osd2_continued_service_action;
extern int hf_scsi_osd2_cdb_continuation_descriptor_type;
extern int hf_scsi_osd2_cdb_continuation_descriptor_pad_length;
extern int hf_scsi_osd2_cdb_continuation_descriptor_length;
extern expert_field ei_osd2_cdb_continuation_format_unknown;
extern expert_field ei_osd2_continued_service_action_mismatch;
extern expert_field ei_osd2_cdb_continuation_descriptor_type_unknown;
extern expert_field ei_osd2_cdb_continuation_descriptor_length_invalid;

#define ENC_BIG_ENDIAN 0

proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *expert_field);
void dissect_osd2_query_list_descriptor(packet_info *pinfo, tvbuff_t *tvb, guint32 offset, proto_tree *tree, guint32 length);