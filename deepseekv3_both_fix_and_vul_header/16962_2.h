#include <stdint.h>
#include <stddef.h>

typedef struct {
    int* id;
    struct {
        const char* name;
        const char* abbrev;
        int type;
        int display;
        const void* strings;
        uint64_t bitmask;
        const char* blurb;
        int hf_hint;
    } info;
} hf_register_info;

typedef struct {
    int* id;
    struct {
        const char* expert_group;
        int severity;
        int summary;
        const char* text;
        int expand;
    } info;
} ei_register_info;

typedef struct _expert_module_t expert_module_t;
typedef int gint;
typedef void* dissector_handle_t;

extern int proto_cbor;
extern dissector_handle_t cbor_handle;
extern dissector_handle_t cborseq_handle;

extern int hf_cbor_item_major_type;
extern int hf_cbor_item_integer_size;
extern int hf_cbor_item_length_size;
extern int hf_cbor_item_length5;
extern int hf_cbor_item_length;
extern int hf_cbor_item_items5;
extern int hf_cbor_item_items;
extern int hf_cbor_item_pairs5;
extern int hf_cbor_item_pairs;
extern int hf_cbor_item_float_simple_type;
extern int hf_cbor_item_unsigned_integer;
extern int hf_cbor_item_negative_integer;
extern int hf_cbor_item_text_string;
extern int hf_cbor_item_byte_string;
extern int hf_cbor_item_array;
extern int hf_cbor_item_map;
extern int hf_cbor_item_tag;
extern int hf_cbor_item_float_simple;
extern int hf_cbor_type_uint5;
extern int hf_cbor_type_uint;
extern int hf_cbor_type_nint;
extern int hf_cbor_type_byte_string;
extern int hf_cbor_type_byte_string_indef;
extern int hf_cbor_type_text_string;
extern int hf_cbor_type_text_string_indef;
extern int hf_cbor_type_tag5;
extern int hf_cbor_type_tag;
extern int hf_cbor_type_simple_data5;
extern int hf_cbor_type_simple_data8;
extern int hf_cbor_type_float16;
extern int hf_cbor_type_float32;
extern int hf_cbor_type_float64;

extern int ett_cbor;
extern int ett_cbor_type;
extern int ett_cbor_unsigned_integer;
extern int ett_cbor_negative_integer;
extern int ett_cbor_byte_string;
extern int ett_cbor_byte_string_indef;
extern int ett_cbor_text_string;
extern int ett_cbor_text_string_indef;
extern int ett_cbor_array;
extern int ett_cbor_map;
extern int ett_cbor_tag;
extern int ett_cbor_float_simple;

extern int ei_cbor_invalid_minor_type;
extern int ei_cbor_invalid_element;
extern int ei_cbor_too_long_length;
extern int ei_cbor_max_recursion_depth_reached;

typedef struct {
    int value;
    const char *strptr;
} value_string;

typedef struct {
    uint64_t value;
    const char *strptr;
} value_string_val64;

extern const value_string major_type_vals[];
extern const value_string integer_size_vals[];
extern const value_string length_size_vals[];
extern const value_string float_simple_type_vals[];
extern const value_string tag32_vals[];
extern const value_string_val64 tag64_vals[];
extern const value_string vals_simple_data[];

#define FT_UINT8 0
#define FT_UINT64 1
#define FT_INT64 2
#define FT_BYTES 3
#define FT_STRING 4
#define FT_FLOAT 5
#define FT_DOUBLE 6
#define FT_NONE 7

#define BASE_DEC 0
#define BASE_NONE 1
#define BASE_VAL64_STRING 2
#define BASE_DECIMAL 3

#define VALS(x) x
#define VALS64(x) x

#define HFILL 0
#define EXPFILL 0
#define PI_MALFORMED 0
#define PI_WARN 1
#define PI_PROTOCOL 2

#define NULL ((void*)0)

int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
void proto_register_field_array(int proto, hf_register_info *hf, int count);
void proto_register_subtree_array(gint **ett, int count);
expert_module_t* expert_register_protocol(int proto);
void expert_register_field_array(expert_module_t *em, ei_register_info *ei, int count);
dissector_handle_t register_dissector(const char *name, void (*dissector)(void *, void *, void *), int proto);
size_t array_length(const void *array);

void dissect_cbor(void *, void *, void *);
void dissect_cborseq(void *, void *, void *);