#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define ABSOLUTE_TIME_LOCAL 0
#define TRUE 1
#define FALSE 0

typedef int32_t gint32;
typedef uint32_t guint32;
typedef int gint;
typedef unsigned int guint;
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef char gchar;
typedef int gboolean;

typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _packet_info packet_info;
typedef struct _tvbuff tvbuff_t;
typedef struct {
    int dummy;
} expert_field;

typedef enum {
    REPORT,
    NOTIF,
    STANAG, 
    IPM
} MsgType;

typedef enum {
    EXTENDED_NATIONAL,
    NATIONAL,
    NATO,
    EXTENDED_MISSION
} SecPol;

typedef enum {
    DMP_VERSION_1,
    DMP_VERSION_2
} DmpVersion;

typedef enum {
    ONLY_DMP_ID,
    X400_MSG_ID,
    NAT_MSG_ID
} MsgIdType;

typedef struct {
    MsgType msg_type;
    guint8 body_format;
    guint8 st_type;
    guint8 prec;
    guint8 notif_type;
    guint16 subj_id;
    guint32 subm_time;
    gboolean checksum;
    DmpVersion version;
    MsgIdType msg_id_type;
} dmp_info_t;

static dmp_info_t dmp;

static const struct {
    int value;
    const char *str;
} message_type_vals[] = {
    {0, "Message"},
    {1, "Reply"},
    {2, "Reserved"},
    {3, "Reserved"},
    {0, NULL}
};

static const struct {
    int value;
    const char *str;
} precedence[] = {
    {0, "Routine"},
    {1, "Priority"},
    {2, "Immediate"},
    {3, "Flash"},
    {4, "Flash Override"},
    {5, "Flash Override Override"},
    {6, "Reserved"},
    {7, "Reserved"},
    {0, NULL}
};

static const struct {
    int value;
    const char *str;
} importance[] = {
    {0, "Normal"},
    {1, "Low"},
    {2, "High"},
    {3, "Reserved"},
    {4, "Reserved"},
    {5, "Reserved"},
    {6, "Reserved"},
    {7, "Reserved"},
    {0, NULL}
};

static const struct {
    int value;
    const char *str;
} body_format_vals[] = {
    {0, "Unformatted"},
    {1, "Formatted"},
    {2, "Reserved"},
    {3, "Reserved"},
    {0, NULL}
};

static const struct {
    int value;
    const char *str;
} sec_class[] = {
    {0, "Unclassified"},
    {1, "Restricted"},
    {2, "Confidential"},
    {3, "Secret"},
    {4, "Top Secret"},
    {5, "Reserved"},
    {6, "Reserved"},
    {7, "Reserved"},
    {0, NULL}
};

static const struct {
    int value;
    const char *str;
} sec_pol[] = {
    {0, "NATO"},
    {1, "National"},
    {2, "Extended National"},
    {3, "Extended Mission"},
    {4, "Reserved"},
    {5, "Reserved"},
    {6, "Reserved"},
    {7, "Reserved"},
    {0, NULL}
};

static const struct {
    int value;
    const char *str;
} notif_type[] = {
    {0, "Delivery Notification"},
    {1, "Non-Delivery Notification"},
    {2, "Reserved"},
    {3, "Reserved"},
    {0, NULL}
};

static const struct {
    const char *true_string;
    const char *false_string;
} dtg_sign = {
    "future",
    "past"
};

static const guint32 DMP_TIME_NOT_PRESENT = 0xFFFFFFFF;
static const guint32 DMP_TIME_RESERVED = 0xFFFFFFFE;

static int use_seq_ack_analysis = 0;
static guint8 dmp_local_nation = 0;

static int hf_report_content = -1;
static int hf_notif_content = -1;
static int hf_message_content = -1;
static int hf_message_st_type = -1;
static int hf_reserved_0x20 = -1;
static int hf_message_precedence = -1;
static int hf_reserved_0xE0 = -1;
static int hf_message_importance = -1;
static int hf_message_body_format = -1;
static int hf_message_sec_class_val = -1;
static int hf_message_sec_pol = -1;
static int hf_message_heading_flags = -1;
static int hf_message_auth_users = -1;
static int hf_message_subject_disc = -1;
static int hf_notif_type = -1;
static int hf_reserved_0x02 = -1;
static int hf_message_national_policy_id = -1;
static int hf_message_mission_policy_id = -1;
static int hf_message_sec_label = -1;
static int hf_message_sec_cat_val = -1;
static int hf_message_sec_cat_bit7 = -1;
static int hf_message_sec_cat_bit6 = -1;
static int hf_message_sec_cat_bit5 = -1;
static int hf_message_sec_cat_bit4 = -1;
static int hf_message_sec_cat_bit3 = -1;
static int hf_message_sec_cat_bit2 = -1;
static int hf_message_sec_cat_bit1 = -1;
static int hf_message_sec_cat_bit0 = -1;
static int hf_message_exp_time = -1;
static int hf_message_exp_time_val = -1;
static int hf_message_dtg = -1;
static int hf_message_dtg_sign = -1;
static int hf_message_dtg_val = -1;
static int hf_message_subj_id = -1;
static int hf_dmp_id = -1;

static int ett_content = -1;
static int ett_message_st_type = -1;
static int ett_message_reserved = -1;
static int ett_message_precedence = -1;
static int ett_message_importance = -1;
static int ett_message_body_format = -1;
static int ett_message_sec_class = -1;
static int ett_message_sec_pol = -1;
static int ett_message_heading_flags = -1;
static int ett_notif_type = -1;
static int ett_message_exp_time = -1;
static int ett_message_dtg = -1;
static int ett_message_sec_cat = -1;

static expert_field ei_reserved_value;