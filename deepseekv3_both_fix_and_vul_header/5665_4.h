#include <stdint.h>
#include <stddef.h>

#define WCP_CMD 0
#define WCP_EXT_CMD 0
#define WCP_SEQ 0
#define WCP_OFFSET_MASK 0

#define FT_UINT8 1
#define FT_UINT16 2
#define FT_NONE 3
#define FT_BYTES 4
#define BASE_HEX 1
#define BASE_DEC 2
#define BASE_NONE 3
#define PI_MALFORMED 1
#define PI_ERROR 2

typedef int gint;

typedef struct {
    int* hf;
    struct {
        const char* name;
        const char* abbrev;
        int type;
        int display;
        const void* strings;
        uint32_t bitmask;
        const char* blurb;
        int hfill;
    } info;
} hf_register_info;

typedef struct {
    int* ei;
    struct {
        const char* name;
        int severity;
        int expert_group;
        const char* description;
        int expfill;
    } info;
} ei_register_info;

typedef struct {
    int dummy;
} expert_module_t;

typedef struct {
    const char* strings[256];
} VALS;

#define HFILL 0
#define EXPFILL 0
#define VALS(x) &vals

static int proto_wcp;
static int hf_wcp_cmd;
static int hf_wcp_ext_cmd;
static int hf_wcp_seq;
static int hf_wcp_chksum;
static int hf_wcp_tid;
static int hf_wcp_rev;
static int hf_wcp_init;
static int hf_wcp_seq_size;
static int hf_wcp_alg_cnt;
static int hf_wcp_alg_a;
static int hf_wcp_alg_b;
static int hf_wcp_alg_c;
static int hf_wcp_alg_d;
static int hf_wcp_alg;
static int hf_wcp_hist_size;
static int hf_wcp_ppc;
static int hf_wcp_pib;
static int hf_wcp_compressed_data;
static int hf_wcp_comp_bits;
static int hf_wcp_offset;
static int hf_wcp_short_len;
static int hf_wcp_long_len;
static int hf_wcp_long_run;
static int hf_wcp_short_run;
static gint ett_wcp;
static gint ett_wcp_comp_data;
static gint ett_wcp_field;
static int ei_wcp_compressed_data_exceeds;
static int ei_wcp_uncompressed_data_exceeds;
static int ei_wcp_invalid_window_offset;
static int ei_wcp_invalid_match_length;

static const char* cmd_string = "";
static const char* ext_cmd_string = "";

static VALS vals = {{0}};

int proto_register_protocol(const char* name, const char* short_name, const char* filter_name);
void proto_register_field_array(int proto, hf_register_info* hf, int count);
void proto_register_subtree_array(gint** ett, int count);
expert_module_t* expert_register_protocol(int proto);
void expert_register_field_array(expert_module_t* em, ei_register_info* ei, int count);
size_t array_length(const void* array);