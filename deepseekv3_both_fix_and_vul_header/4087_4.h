#include <stdint.h>
#include <stddef.h>

#define FT_UINT8 0
#define FT_UINT16 1
#define FT_UINT32 2
#define FT_BYTES 3
#define FT_BOOLEAN 4
#define FT_STRING 5
#define FT_STRINGZ 6
#define FT_ETHER 7
#define FT_IPv4 8
#define FT_INT16 9

#define BASE_DEC 0
#define BASE_HEX 1
#define BASE_DEC_HEX 2
#define BASE_NONE 3

#define STR_UNICODE 0

#define PI_PROTOCOL 0
#define PI_WARN 1

#define EXPFILL 0
#define HFILL 0

#define HIQNET_FLAGS_MASK 0
#define HIQNET_REQACK_FLAG 0
#define HIQNET_ACK_FLAG 0
#define HIQNET_INFO_FLAG 0
#define HIQNET_ERROR_FLAG 0
#define HIQNET_GUARANTEED_FLAG 0
#define HIQNET_MULTIPART_FLAG 0
#define HIQNET_SESSION_NUMBER_FLAG 0
#define HIQNET_SUBSCRIPTION_TYPE_MASK 0
#define HIQNET_SUBSCRIPTION_FLAGS_MASK 0
#define HIQNET_CATEGORIES_MASK 0
#define HIQNET_APPLICATION_CAT 0
#define HIQNET_CONF_CAT 0
#define HIQNET_AUDIONET_CAT 0
#define HIQNET_CTRLNET_CAT 0
#define HIQNET_VENDNET_CAT 0
#define HIQNET_STARTUP_CAT 0
#define HIQNET_DSP_CAT 0
#define HIQNET_MISC_CAT 0
#define HIQNET_CTRLLOG_CAT 0
#define HIQNET_FOREIGNPROTO_CAT 0
#define HIQNET_DIGIO_CAT 0
#define HIQNET_CTRLSURF_CAT 0

typedef struct {
    const char *name;
    int value;
} value_string;

static value_string messageidnames[] = {{NULL, 0}};
static value_string networknames[] = {{NULL, 0}};
static value_string datatypenames[] = {{NULL, 0}};
static value_string actionnames[] = {{NULL, 0}};
static value_string timenames[] = {{NULL, 0}};
static value_string device_attributes_names[] = {{NULL, 0}};
static value_string eventcategorynames[] = {{NULL, 0}};
static value_string eventidnames[] = {{NULL, 0}};
static value_string prioritynames[] = {{NULL, 0}};
static value_string paritynames[] = {{NULL, 0}};
static value_string stopbitsnames[] = {{NULL, 0}};
static value_string flowcontrolnames[] = {{NULL, 0}};

#define VALS(x) (value_string*)(x)

typedef struct {
    void *field;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        value_string *strings;
        uint32_t mask;
        void *blurb;
        int hfinfo;
    } info;
} hf_register_info;

typedef struct {
    int *field;
    const char *name;
    int abbrev;
    int severity;
    const char *summary;
    int hfinfo;
} ei_register_info;

typedef struct expert_module_s expert_module_t;

static int hf_hiqnet_version;
static int hf_hiqnet_headerlen;
static int hf_hiqnet_messagelen;
static int hf_hiqnet_sourcedev;
static int hf_hiqnet_sourceaddr;
static int hf_hiqnet_destdev;
static int hf_hiqnet_destaddr;
static int hf_hiqnet_messageid;
static int hf_hiqnet_flags;
static int hf_hiqnet_reqack_flag;
static int hf_hiqnet_ack_flag;
static int hf_hiqnet_info_flag;
static int hf_hiqnet_error_flag;
static int hf_hiqnet_guaranteed_flag;
static int hf_hiqnet_multipart_flag;
static int hf_hiqnet_session_number_flag;
static int hf_hiqnet_hopcnt;
static int hf_hiqnet_seqnum;
static int hf_hiqnet_errcode;
static int hf_hiqnet_errstr;
static int hf_hiqnet_startseqno;
static int hf_hiqnet_rembytes;
static int hf_hiqnet_sessnum;
static int hf_hiqnet_cost;
static int hf_hiqnet_sernumlen;
static int hf_hiqnet_sernum;
static int hf_hiqnet_maxmsgsize;
static int hf_hiqnet_keepaliveperiod;
static int hf_hiqnet_netid;
static int hf_hiqnet_macaddr;
static int hf_hiqnet_dhcp;
static int hf_hiqnet_ipaddr;
static int hf_hiqnet_subnetmsk;
static int hf_hiqnet_gateway;
static int hf_hiqnet_flagmask;
static int hf_hiqnet_paramcount;
static int hf_hiqnet_paramid;
static int hf_hiqnet_datatype;
static int hf_hiqnet_value;
static int hf_hiqnet_vdobject;
static int hf_hiqnet_subtype;
static int hf_hiqnet_sensrate;
static int hf_hiqnet_subflags;
static int hf_hiqnet_subcount;
static int hf_hiqnet_pubparmid;
static int hf_hiqnet_subaddr;
static int hf_hiqnet_subparmid;
static int hf_hiqnet_reserved0;
static int hf_hiqnet_reserved1;
static int hf_hiqnet_attrcount;
static int hf_hiqnet_attrid;
static int hf_hiqnet_datalen;
static int hf_hiqnet_string;
static int hf_hiqnet_wrkgrppath;
static int hf_hiqnet_numvds;
static int hf_hiqnet_vdaddr;
static int hf_hiqnet_vdclassid;
static int hf_hiqnet_stract;
static int hf_hiqnet_strnum;
static int hf_hiqnet_scope;
static int hf_hiqnet_recact;
static int hf_hiqnet_recnum;
static int hf_hiqnet_strlen;
static int hf_hiqnet_time;
static int hf_hiqnet_maxdatasize;
static int hf_hiqnet_catfilter;
static int hf_hiqnet_app_cat;
static int hf_hiqnet_conf_cat;
static int hf_hiqnet_audionet_cat;
static int hf_hiqnet_ctrlnet_cat;
static int hf_hiqnet_vendnet_cat;
static int hf_hiqnet_startup_cat;
static int hf_hiqnet_dsp_cat;
static int hf_hiqnet_misc_cat;
static int hf_hiqnet_ctrlog_cat;
static int hf_hiqnet_foreignproto_cat;
static int hf_hiqnet_digio_cat;
static int hf_hiqnet_ctrlsurf_cat;
static int hf_hiqnet_entrieslen;
static int hf_hiqnet_category;
static int hf_hiqnet_eventid;
static int hf_hiqnet_priority;
static int hf_hiqnet_eventseqnum;
static int hf_hiqnet_eventtime;
static int hf_hiqnet_eventdate;
static int hf_hiqnet_eventinfo;
static int hf_hiqnet_eventadddata;
static int hf_hiqnet_objcount;
static int hf_hiqnet_paramval;
static int hf_hiqnet_ifacecount;
static int hf_hiqnet_comid;
static int hf_hiqnet_baudrate;
static int hf_hiqnet_parity;
static int hf_hiqnet_stopbits;
static int hf_hiqnet_databits;
static int hf_hiqnet_flowcontrol;
static int hf_hiqnet_devaddr;
static int hf_hiqnet_newdevaddr;

static int ett_hiqnet;
static int ett_hiqnet_flags;
static int ett_hiqnet_cats;

static int ei_hiqnet_datatype;

static int proto_hiqnet;

typedef int gint;

static size_t array_length(void *arr) { return 0; }
static int proto_register_protocol(const char *name, const char *short_name, const char *filter_name) { return 0; }
static void proto_register_field_array(int parent_proto, hf_register_info *hf, size_t size) {}
static void proto_register_subtree_array(int **ett, size_t size) {}
static expert_module_t *expert_register_protocol(int proto) { return NULL; }
static void expert_register_field_array(expert_module_t *em, ei_register_info *ei, size_t size) {}