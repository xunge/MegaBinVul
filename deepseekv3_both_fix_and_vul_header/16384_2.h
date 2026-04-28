#include <stddef.h>

typedef struct expert_module_t expert_module_t;

typedef struct {
    int* ei;
    const char* name;
    int severity;
    int level;
    const char* description;
    int fill;
} ei_register_info;

static int ei_kafka_request_missing;
static int ei_kafka_unknown_api_key;
static int ei_kafka_unsupported_api_version;
static int ei_kafka_bad_string_length;
static int ei_kafka_bad_bytes_length;
static int ei_kafka_bad_array_length;
static int ei_kafka_bad_record_length;
static int ei_kafka_bad_varint;
static int ei_kafka_bad_message_set_length;
static int ei_kafka_bad_decompression_length;
static int ei_kafka_unknown_message_magic;
static int ei_kafka_pdu_length_mismatch;

#define PI_UNDECODED 0
#define PI_WARN 0
#define PI_MALFORMED 0
#define EXPFILL 0

#define array_length(arr) (sizeof(arr)/sizeof(arr[0]))

expert_module_t* expert_register_protocol(int proto);
void expert_register_field_array(expert_module_t* module, ei_register_info* ei, size_t count);