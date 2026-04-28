#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef uint32_t guint32;

typedef struct {
    const char *name;
    const char *abbrev;
    int type;
    int display;
    const void *strings;
    guint32 bitmask;
    const char *blurb;
    int hf_id;
} header_field_info;

typedef struct {
    int *p_id;
    header_field_info hfinfo;
} hf_register_info;

typedef struct {
    int *p_id;
    const char *name;
    int severity;
    const char *description;
    int fill;
} ei_register_info;

typedef struct {
    guint32 value;
    const char *strptr;
} value_string;

typedef struct {
    int dummy;
} expert_module_t;

#define FT_UINT8      0
#define FT_UINT16     1
#define FT_UINT32     2
#define FT_INT16      3
#define FT_INT32      4
#define FT_INT64      5
#define FT_UINT64     6
#define FT_STRING     7
#define FT_DOUBLE     8

#define BASE_NONE     0
#define BASE_DEC      1
#define BASE_HEX      2

#define HFILL         0
#define EXPFILL       0

#define PI_PROTOCOL   0
#define PI_ERROR      1

#define VALS(x)       (x)

static int proto_thrift;
static int hf_thrift_version;
static int hf_thrift_mtype;
static int hf_thrift_str_len;
static int hf_thrift_method;
static int hf_thrift_seq_id;
static int hf_thrift_type;
static int hf_thrift_fid;
static int hf_thrift_i16;
static int hf_thrift_i32;
static int hf_thrift_utf7str;
static int hf_thrift_num_list_item;
static int hf_thrift_num_map_item;
static int hf_thrift_bool;
static int hf_thrift_byte;
static int hf_thrift_i64;
static int hf_thrift_u64;
static int hf_thrift_double;
static int ei_thrift_wrong_type;

static gint ett_thrift;

static const value_string thrift_mtype_vals[] = {
    {0, NULL}
};

static const value_string thrift_type_vals[] = {
    {0, NULL}
};

static const value_string thrift_bool_vals[] = {
    {0, NULL}
};

static inline unsigned array_length(const void *array) {
    const char **ptr = (const char **)array;
    unsigned count = 0;
    while (*ptr++) count++;
    return count;
}

int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
void proto_register_field_array(int parent, hf_register_info *hf, unsigned size);
void proto_register_subtree_array(gint **ett, unsigned size);
expert_module_t* expert_register_protocol(int proto_id);
void expert_register_field_array(expert_module_t* em, ei_register_info *ei, unsigned size);