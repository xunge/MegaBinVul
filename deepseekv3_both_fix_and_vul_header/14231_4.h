#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int64_t secs;
    int32_t nsecs;
} nstime_t;

typedef struct {
    bool request_found;
    unsigned req_frame_num;
    nstime_t req_time;
    uint16_t num_reg;
    uint8_t register_format;
    uint16_t reg_base;
} modbus_pkt_info_t;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    nstime_t abs_ts;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

#define TRUE true
#define FALSE false

#define READ_COILS 1
#define READ_DISCRETE_INPUTS 2
#define READ_HOLDING_REGS 3
#define READ_INPUT_REGS 4
#define WRITE_SINGLE_COIL 5
#define WRITE_SINGLE_REG 6
#define READ_EXCEPT_STAT 7
#define DIAGNOSTICS 8
#define GET_COMM_EVENT_CTRS 11
#define GET_COMM_EVENT_LOG 12
#define WRITE_MULT_COILS 15
#define WRITE_MULT_REGS 16
#define READ_FILE_RECORD 20
#define WRITE_FILE_RECORD 21
#define MASK_WRITE_REG 22
#define READ_WRITE_REG 23
#define READ_FIFO_QUEUE 24
#define ENCAP_INTERFACE_TRANSP 43
#define REPORT_SLAVE_ID 17

#define RETURN_QUERY_DATA 0x0000
#define RESTART_COMMUNICATION_OPTION 0x0001
#define RETURN_DIAGNOSTIC_REGISTER 0x0002
#define CHANGE_ASCII_INPUT_DELIMITER 0x0003
#define CLEAR_COUNTERS_AND_DIAG_REG 0x0004
#define RETURN_BUS_MESSAGE_COUNT 0x0005
#define RETURN_BUS_COMM_ERROR_COUNT 0x0006
#define RETURN_BUS_EXCEPTION_ERROR_COUNT 0x0007
#define RETURN_SLAVE_MESSAGE_COUNT 0x0008
#define RETURN_SLAVE_NO_RESPONSE_COUNT 0x0009
#define RETURN_SLAVE_NAK_COUNT 0x000A
#define RETURN_SLAVE_BUSY_COUNT 0x000B
#define RETURN_BUS_CHAR_OVERRUN_COUNT 0x000C
#define CLEAR_OVERRUN_COUNTER_AND_FLAG 0x000D
#define FORCE_LISTEN_ONLY_MODE 0x000E

#define READ_DEVICE_ID 0x0E
#define CANOPEN_REQ_RESP 0x0D

#define REMOTE_DEVICE_RECV_EVENT_MASK 0x80
#define REMOTE_DEVICE_SEND_EVENT_MASK 0x40
#define REMOTE_DEVICE_SEND_EVENT_VALUE 0x40

#define ENC_BIG_ENDIAN 0
#define ENC_LITTLE_ENDIAN 1
#define ENC_NA 2
#define ENC_ASCII 4

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int gint;

extern int hf_modbus_request_frame;
extern int hf_modbus_response_time;
extern int hf_modbus_bytecnt;
extern int hf_modbus_reference;
extern int hf_modbus_padding;
extern int hf_modbus_diag_sf;
extern int hf_modbus_diag_return_query_data_echo;
extern int hf_modbus_diag_restart_communication_option;
extern int hf_modbus_diag_return_diag_register;
extern int hf_modbus_diag_ascii_input_delimiter;
extern int hf_modbus_diag_clear_ctr_diag_reg;
extern int hf_modbus_diag_return_bus_message_count;
extern int hf_modbus_diag_return_bus_comm_error_count;
extern int hf_modbus_diag_return_bus_exception_error_count;
extern int hf_modbus_diag_return_slave_message_count;
extern int hf_modbus_diag_return_no_slave_response_count;
extern int hf_modbus_diag_return_slave_nak_count;
extern int hf_modbus_diag_return_slave_busy_count;
extern int hf_modbus_diag_return_bus_char_overrun_count;
extern int hf_modbus_status;
extern int hf_modbus_event_count;
extern int hf_modbus_message_count;
extern int hf_modbus_event;
extern int hf_modbus_event_recv_comm_err;
extern int hf_modbus_event_recv_char_over;
extern int hf_modbus_event_recv_lo_mode;
extern int hf_modbus_event_recv_broadcast;
extern int hf_modbus_event_send_read_ex;
extern int hf_modbus_event_send_slave_abort_ex;
extern int hf_modbus_event_send_slave_busy_ex;
extern int hf_modbus_event_send_slave_nak_ex;
extern int hf_modbus_event_send_write_timeout;
extern int hf_modbus_event_send_lo_mode;
extern int hf_modbus_bitcnt;
extern int hf_modbus_wordcnt;
extern int hf_modbus_reftype;
extern int hf_modbus_lreference;
extern int hf_modbus_lbytecnt;
extern int hf_modbus_andmask;
extern int hf_modbus_ormask;
extern int hf_modbus_mei;
extern int hf_modbus_read_device_id;
extern int hf_modbus_conformity_level;
extern int hf_modbus_more_follows;
extern int hf_modbus_next_object_id;
extern int hf_modbus_num_objects;
extern int hf_modbus_object_id;
extern int hf_modbus_list_object_len;
extern int hf_modbus_object_str_value;
extern int hf_modbus_object_value;

extern int ett_events;
extern int ett_events_recv;
extern int ett_events_send;
extern int ett_group_hdr;
extern int ett_device_id_objects;
extern int ett_device_id_object_items;

extern uint8_t tvb_get_guint8(tvbuff_t *tvb, int offset);
extern uint16_t tvb_get_ntohs(tvbuff_t *tvb, int offset);
extern proto_item* proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, uint32_t value);
extern proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
extern proto_item* proto_tree_add_time(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, nstime_t *value_ptr);
extern proto_item* proto_tree_add_uint_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, uint32_t value, const char *format, ...);
extern proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int start, int length, int ett, proto_item **tree_item, const char *text);
extern proto_tree* proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, int start, int length, int ett, proto_item **tree_item, const char *format, ...);
extern proto_tree* proto_item_add_subtree(proto_item *item, int ett);
extern void proto_item_set_generated(proto_item *item);
extern void nstime_delta(nstime_t *delta, const nstime_t *time1, const nstime_t *time0);
extern int tvb_captured_length(tvbuff_t *tvb);
extern void dissect_modbus_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, uint8_t function_code, int offset, int len, uint8_t register_format, uint16_t reg_base, uint16_t num_reg);