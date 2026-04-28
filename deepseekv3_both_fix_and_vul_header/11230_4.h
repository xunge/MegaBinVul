#include <stdint.h>
#include <stddef.h>

typedef struct hf_register_info {
    int* id;
    struct {
        const char* name;
        const char* abbrev;
        int type;
        int display;
        const void* strings;
        uint32_t bitmask;
        const char* blurb;
        int hf_hint;
    } info;
} hf_register_info;

typedef struct module_t module_t;

static int hf_bzr_packet_kind;
static int hf_bzr_packet_protocol_version;
static int hf_bzr_prefixed_bencode;
static int hf_bzr_prefixed_bencode_len;
static int hf_bzr_bytes;
static int hf_bzr_bytes_data;
static int hf_bzr_bytes_length;
static int hf_bzr_result;

static int ett_bzr;
static int ett_prefixed_bencode; 
static int ett_prefixed_bytes;

static int proto_bzr;
static int bzr_desegment;

struct value_string {
    unsigned int value;
    const char* strptr;
};

static const struct value_string message_part_kind[] = {{0, NULL}};
static const struct value_string message_results[] = {{0, NULL}};

void dissect_bzr(void);
int proto_register_protocol(const char* name, const char* short_name, const char* abbrev);
void register_dissector(const char* name, void (*dissector)(void), int proto);
void proto_register_field_array(int proto, hf_register_info* hf, int count);
void proto_register_subtree_array(int* ett, int count);
module_t* prefs_register_protocol(int proto, void* null);
void prefs_register_bool_preference(module_t* module, const char* name, const char* title, const char* description, int* var);

#define FT_UINT8 1
#define FT_STRING 2
#define FT_NONE 3
#define FT_UINT32 4
#define FT_BYTES 5
#define BASE_DEC 1
#define BASE_HEX 2
#define BASE_NONE 3
#define VALS(x) x
#define HFILL 0
#define array_length(x) (sizeof(x)/sizeof(x[0]))

typedef int gint;