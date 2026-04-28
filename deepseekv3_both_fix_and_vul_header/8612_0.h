#include <stdint.h>
#include <stddef.h>

typedef struct hf_register_info {
    int *hf_id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint32_t bitmask;
        const char *blurb;
        int HFILL;
    } info;
} hf_register_info;

typedef struct value_string {
    unsigned int value;
    const char *strptr;
} value_string;

typedef int gint;

static int hf_pn_io_io_data_object;
static int hf_pn_io_io_data_object_info_module_diff;
static int hf_pn_io_io_data_object_info_moduleidentnumber;
static int hf_pn_io_io_data_object_info_submoduleidentnumber;
static int hf_pn_io_frame_info_type;
static int hf_pn_io_frame_info_vendor;
static int hf_pn_io_frame_info_nameofstation;
static int hf_pn_io_frame_info_gsd_found;
static int hf_pn_io_frame_info_gsd_error;
static int hf_pn_io_frame_info_gsd_path;
static int hf_pn_io_iocs;
static int hf_pn_io_iops;
static int hf_pn_io_ioxs_extension;
static int hf_pn_io_ioxs_res14;
static int hf_pn_io_ioxs_instance;
static int hf_pn_io_ioxs_datastate;
static int hf_pn_io_ps_sb;
static int hf_pn_io_ps_sb_toggelBitChanged;
static int hf_pn_io_ps_sb_toggelBitChange_slot_nr;
static int hf_pn_io_ps_sb_toggelBitChange_subslot_nr;
static int hf_pn_io_ps_cb;
static int hf_pn_io_ps_cb_toggelBitChanged;
static int hf_pn_io_ps_cb_toggelBitChange_slot_nr;
static int hf_pn_io_ps_cb_toggelBitChange_subslot_nr;
static int hf_pn_io_ps_sb_iparOK;
static int hf_pn_io_ps_sb_DeviceFault;
static int hf_pn_io_ps_sb_CECRC;
static int hf_pn_io_ps_sb_WDtimeout;
static int hf_pn_io_ps_sb_FVactivated;
static int hf_pn_io_ps_sb_Toggle_d;
static int hf_pn_io_ps_sb_ConsNr_reset;
static int hf_pn_io_ps_sb_res;
static int hf_pn_io_ps_cb_iparEN;
static int hf_pn_io_ps_cb_OAReq;
static int hf_pn_io_ps_cb_resetConsNr;
static int hf_pn_io_ps_cb_useTO2;
static int hf_pn_io_ps_cb_activateFV;
static int hf_pn_io_ps_cb_Toggle_h;
static int hf_pn_io_ps_cb_Chf_ACK;
static int hf_pn_io_ps_cb_loopcheck;
static int hf_pn_io_ps_f_dest_adr;
static int hf_pn_io_ps_f_data;

static gint ett_pn_io_rtc;
static gint ett_pn_io_ioxs;
static gint ett_pn_io_io_data_object;

static const value_string pn_io_ioxs_extension[] = { {0, NULL} };
static const value_string pn_io_ioxs_instance[] = { {0, NULL} };
static const value_string pn_io_ioxs_datastate[] = { {0, NULL} };

#define FT_NONE 0
#define FT_STRING 1
#define FT_UINT8 2
#define FT_UINT16 3
#define FT_UINT32 4
#define FT_UINT64 5
#define BASE_NONE 0
#define BASE_HEX 1
#define BASE_DEC 2
#define HFILL 0
#define VALS(x) x

static int proto_pn_io_rtc1;

static unsigned int array_length(const void *array);
static void proto_register_field_array(int proto, hf_register_info *hf, unsigned int length);
static void proto_register_subtree_array(gint **ett, unsigned int length);

typedef struct ei_register_info {
    int *ei;
    struct {
        const char *name;
        int severity;
        int summary;
        const char *description;
        int EXPFILL;
    } info;
} ei_register_info;

typedef struct expert_module_t expert_module_t;
static int ei_pn_io_too_many_data_objects;
#define PI_MALFORMED 0
#define PI_ERROR 0
#define EXPFILL 0

static expert_module_t* expert_register_protocol(int proto);
static void expert_register_field_array(expert_module_t *expert, ei_register_info *ei, unsigned int length);