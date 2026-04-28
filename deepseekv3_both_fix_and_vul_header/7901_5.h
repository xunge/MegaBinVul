#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int gint;
typedef unsigned int guint;
typedef unsigned char guint8;
typedef unsigned short guint16;
typedef unsigned int guint32;
typedef int gboolean;

typedef struct module_t module_t;
typedef struct expert_module_t expert_module_t;

typedef struct {
    const char *name;
    int value;
} value_string;

typedef struct {
    int *p_id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const value_string *strings;
        guint32 bitmask;
        const char *blurb;
        int hf_flags;
    } hfinfo;
} hf_register_info;

typedef struct {
    int *p_id;
    struct {
        const char *name;
        const char *abbrev;
        int severity;
        const char *summary;
        const char *description;
        int flags;
    } einfo;
} ei_register_info;

static int proto_umts_mac;
static int ett_mac;
static int ett_mac_fach;
static int ett_mac_rach;
static int ett_mac_dch;
static int ett_mac_pch;
static int ett_mac_edch;
static int ett_mac_hsdsch;
static int ett_mac_edch_type2;
static int ett_mac_edch_type2_sdu;

static int hf_mac_rach_fdd_tctf;
static int hf_mac_fach_fdd_tctf;
static int hf_mac_ct;
static int hf_mac_ueid_type;
static int hf_mac_crnti;
static int hf_mac_urnti;
static int hf_mac_channel;
static int hf_mac_macdflowd_id;
static int hf_mac_lch_id;
static int hf_mac_trch_id;
static int hf_mac_edch_type2_ss;
static int hf_mac_edch_type2_ss_interpretation;
static int hf_mac_edch_type2_tsn;
static int hf_mac_edch_type2_sdu;
static int hf_mac_edch_type2_sdu_data;
static int hf_mac_is_reasmin;
static int hf_mac_is_fraglink;

static int ei_mac_per_frame_info_missing;
static int ei_mac_unknown_content;
static int ei_mac_rach_tctf_unknown;
static int ei_mac_cs_dtch_not_implemented;
static int ei_mac_fach_content_type_unknown;
static int ei_mac_no_logical_channel;
static int ei_mac_faked_logical_channel_id;
static int ei_mac_macis_sdu_reassembled;
static int ei_mac_macis_sdu_first;
static int ei_mac_macis_sdu_middle;
static int ei_mac_macis_sdu_last;
static int ei_mac_macis_sdu_complete;
static int ei_mac_reserved_c_t;

static const value_string rach_fdd_tctf_vals[] = {{NULL, 0}};
static const value_string fach_fdd_tctf_vals[] = {{NULL, 0}};
static const value_string ueid_type_vals[] = {{NULL, 0}};
static const value_string mac_logical_channel_vals[] = {{NULL, 0}};
static const value_string tsn_size_enumvals[] = {{NULL, 0}};

static int global_mac_tsn_size;

enum {
    FT_UINT8 = 1,
    FT_UINT16,
    FT_UINT32,
    FT_NONE,
    FT_BYTES,
    FT_FRAMENUM,
    FT_STRING
};

enum {
    BASE_HEX = 1,
    BASE_DEC,
    BASE_NONE
};

enum {
    PI_MALFORMED = 1,
    PI_ERROR,
    PI_DEBUG,
    PI_UNDECODED,
    PI_WARN,
    PI_PROTOCOL,
    PI_REASSEMBLE,
    PI_CHAT
};

#define HFILL 0
#define VALS(x) x
#define EXPFILL 0
#define FALSE 0
#define TRUE 1

void dissect_mac_fdd_rach(void);
void dissect_mac_fdd_fach(void);
void dissect_mac_fdd_pch(void);
void dissect_mac_fdd_dch(void);
void dissect_mac_fdd_edch(void);
void dissect_mac_fdd_edch_type2(void);
void dissect_mac_fdd_hsdsch(void);
void mac_init(void);
void mac_cleanup(void);
size_t array_length(const void *array);
int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
void proto_register_field_array(int parent, hf_register_info *hf, size_t size);
void proto_register_subtree_array(gint **ett, size_t size);
expert_module_t* expert_register_protocol(int proto);
void expert_register_field_array(expert_module_t *em, ei_register_info *ei, size_t size);
void register_dissector(const char *name, void (*dissector)(void), int proto);
void register_init_routine(void (*func)(void));
void register_cleanup_routine(void (*func)(void));
module_t* prefs_register_protocol(int id, void (*apply_cb)(void));
void prefs_register_enum_preference(module_t *module, const char *name, const char *title, const char *description, int *var, const value_string *enumvals, gboolean radio_buttons);