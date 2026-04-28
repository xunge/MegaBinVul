#include <stdint.h>
#include <stddef.h>

#define FALSE 0
#define TRUE 1

typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef int32_t gint32;
typedef int16_t gint16;
typedef int8_t gint8;
typedef int gint;
typedef unsigned int guint;
typedef int gboolean;

typedef float gfloat;

#define ENC_NA 0
#define ENC_LITTLE_ENDIAN 1
#define ENC_BIG_ENDIAN 2

#define COL_INFO 0

typedef struct {
    const char *strptr;
    guint32 value;
} value_string;

typedef struct {
    value_string *strings;
    guint32 nr_entries;
} value_string_ext;

typedef struct {
    const char *name;
    int type;
    int display;
    int strings;
    guint32 bitmask;
    const char *blurb;
} header_field_info;

typedef struct {
    guint32 fnum;
    guint16 address_word;
    guint8 commmand_code;
    guint8 *requested_points;
} request_frame;

typedef struct {
    void *request_frame_data;
} cp2179_conversation;

typedef struct {
    int num;
    void *cinfo;
} packet_info;

typedef struct {} tvbuff_t;
typedef struct {} proto_tree;
typedef struct {} proto_item;
typedef struct {} wmem_list_frame_t;

extern int proto_cp2179;
extern int ett_cp2179_header;
extern int ett_cp2179_addr;
extern int ett_cp2179_fc;
extern int ett_cp2179_data;
extern int ett_cp2179_event;
extern int ett_cp2179_subdata;

extern int hf_cp2179_rtu_address;
extern int hf_cp2179_master_address;
extern int hf_cp2179_function_code;
extern int hf_cp2179_nop_flag;
extern int hf_cp2179_rst_flag;
extern int hf_cp2179_status_byte;
extern int hf_cp2179_port_status_byte;
extern int hf_cp2179_number_characters;
extern int hf_cp2179_request_frame;
extern int hf_cp2179_sbo_request_point;
extern int hf_cp2179_resetacc_request_point;
extern int hf_cp2179_specialcalc;
extern int hf_cp2179_analog_16bit;
extern int hf_cp2179_accumulator;
extern int hf_cp2179_simplestatusbit;
extern int hf_cp2179_2bitstatus;
extern int hf_cp2179_timetag_moredata;
extern int hf_cp2179_timetag_numsets;
extern int hf_cp2179_timetag_event_type;
extern int hf_cp2179_timetag_event_date_hundreds;
extern int hf_cp2179_timetag_event_date_tens;
extern int hf_cp2179_timetag_event_hour;
extern int hf_cp2179_timetag_event_minute;
extern int hf_cp2179_timetag_event_second;
extern int hf_cp2179_crc;

extern const value_string FunctionCodenames[];
extern value_string_ext cp2179_CommandCodeNames_ext;

extern header_field_info *cp2179_simplestatus_bits[];
extern header_field_info *cp2179_2bitstatus_bits[];

#define SBO_SELECT_RESPONSE 1
#define SBO_OPERATE_RESPONSE 2
#define RESET_ACC_RESPONSE 3
#define INIT_RTU_RESPONSE 4
#define SPECIAL_CALC_RESPONSE 5
#define SCAN_INCLUSIVE_16_ANALOG_RESPONSE 6
#define BASIC_SCAN_RESPONSE 7
#define TIMETAG_INFO_RESPONSE 8

#define SPECIAL_CALC_ALL 1
#define SPECIAL_CALC_RANGE 2
#define ANALOG_16_BIT 3
#define ACCUMULATOR_16_BIT 4
#define SIMPLE_STATUS_DATA 5
#define TWO_BIT_STATUS 6