#include <stdint.h>
#include <stddef.h>

#define PI_PROTOCOL 0
#define PI_WARN 0
#define PI_CHAT 0
#define PI_UNDECODED 0
#define FT_UINT32 0
#define FT_STRING 0
#define FT_UINT64 0
#define FT_UINT8 0
#define FT_UINT24 0
#define FT_BOOLEAN 0
#define FT_DOUBLE 0
#define FT_STRINGZ 0
#define BASE_DEC 0
#define BASE_HEX 0
#define BASE_NONE 0
#define HFILL 0
#define EXPFILL 0
#define ENTRY_FLAG_MOVIE 0

typedef int gint;

typedef struct hf_register_info {
    int *hf_field;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        int bitmask;
        const void *blurb;
        int hfinfo;
    } info;
} hf_register_info;

typedef struct ei_register_info {
    int *expert_field;
    struct {
        const char *name;
        int severity;
        int summary;
        const char *description;
        int expert_info;
    } info;
} ei_register_info;

typedef struct expert_module_t expert_module_t;

static int hf_mp4_box_size;
static int hf_mp4_box_type_str;
static int hf_mp4_box_largesize;
static int hf_mp4_full_box_ver;
static int hf_mp4_full_box_flags;
static int hf_mp4_full_box_flags_media_data_location;
static int hf_mp4_ftyp_brand;
static int hf_mp4_ftyp_ver;
static int hf_mp4_ftyp_add_brand;
static int hf_mp4_stsz_sample_size;
static int hf_mp4_stsz_sample_count;
static int hf_mp4_stsz_entry_size;
static int hf_mp4_mvhd_creat_time;
static int hf_mp4_mvhd_mod_time;
static int hf_mp4_mvhd_timescale;
static int hf_mp4_mvhd_duration;
static int hf_mp4_mvhd_rate;
static int hf_mp4_mvhd_vol;
static int hf_mp4_mvhd_next_tid;
static int hf_mp4_mfhd_seq_num;
static int hf_mp4_tkhd_creat_time;
static int hf_mp4_tkhd_mod_time;
static int hf_mp4_tkhd_track_id;
static int hf_mp4_tkhd_duration;
static int hf_mp4_tkhd_width;
static int hf_mp4_tkhd_height;
static int hf_mp4_hdlr_type;
static int hf_mp4_hdlr_name;
static int hf_mp4_dref_entry_cnt;
static int hf_mp4_stsd_entry_cnt;

static int ett_mp4;
static int ett_mp4_box;

static int ei_mp4_box_too_large;
static int ei_mp4_too_many_rec_lvls;
static int ei_mp4_mvhd_next_tid_unknown;

static int proto_mp4;

static inline unsigned int array_length(const void *array) {
    return 0;
}

int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
void proto_register_field_array(int proto, const hf_register_info *hf, unsigned int size);
void proto_register_subtree_array(const int *ett, unsigned int size);
expert_module_t *expert_register_protocol(int proto);
void expert_register_field_array(expert_module_t *em, const ei_register_info *ei, unsigned int size);