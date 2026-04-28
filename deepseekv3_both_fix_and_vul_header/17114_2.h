#include <stdint.h>
#include <stddef.h>

#define FT_UINT8 1
#define FT_UINT16 2
#define FT_UINT24 3
#define FT_BOOLEAN 4
#define FT_BYTES 5
#define FT_ETHER 6
#define BASE_DEC 1
#define BASE_HEX 2
#define BASE_NONE 3
#define BASE_EXT_STRING 4
#define PI_UNDECODED 1
#define PI_WARN 2
#define EXPFILL 0
#define HFILL 0
#define LWAPP_FLAGS_T 0x01
#define LWAPP_FLAGS_F 0x02
#define LWAPP_FLAGS_FT 0x04

typedef int gint;

typedef struct hf_register_info {
    void *id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint32_t bitmask;
        const char *blurb;
        int hf_hint;
    } info;
} hf_register_info;

typedef struct ei_register_info {
    void *id;
    struct {
        const char *name;
        int severity;
        int summary;
        const char *description;
        int exp_hint;
    } info;
} ei_register_info;

typedef struct module_t module_t;
typedef struct expert_module_t expert_module_t;

static int proto_lwapp;
static int proto_lwapp_l3;
static int proto_lwapp_control;
static int hf_lwapp_version;
static int hf_lwapp_slotid;
static int hf_lwapp_flags;
static int hf_lwapp_flags_type;
static int hf_lwapp_flags_fragment;
static int hf_lwapp_flags_fragment_type;
static int hf_lwapp_fragment_id;
static int hf_lwapp_length;
static int hf_lwapp_rssi;
static int hf_lwapp_snr;
static int hf_lwapp_control_mac;
static int hf_lwapp_control_type;
static int hf_lwapp_control_seq_no;
static int hf_lwapp_control_length;
static gint ett_lwapp_l3;
static gint ett_lwapp;
static gint ett_lwapp_control;
static gint ett_lwapp_flags;
static int ei_lwapp_too_many_encap;
static int swap_frame_control;

static const char *control_msg_vals_ext[] = { NULL };
static const char *lwapp_flags_type[] = { "Type", NULL };
static const char *tfs_set_notset[] = { "Set", "Not set", NULL };

#define TFS(x) (x)

#define array_length(x) (sizeof(x) / sizeof((x)[0]))