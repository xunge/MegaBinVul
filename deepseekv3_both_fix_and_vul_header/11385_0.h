#include <stdbool.h>
#include <string.h>
#include <stddef.h>

typedef bool cJSON_bool;

typedef struct cJSON {
    int type;
    char *valuestring;
    /* other members omitted */
} cJSON;

typedef struct printbuffer {
    unsigned char *buffer;
    bool noalloc;
    struct {
        void (*deallocate)(void *);
    } hooks;
    /* other members omitted */
} printbuffer;

typedef enum {
    cJSON_NULL,
    cJSON_False,
    cJSON_True,
    cJSON_Number,
    cJSON_Raw,
    cJSON_String,
    cJSON_Array,
    cJSON_Object
} cJSON_type;

static unsigned char* ensure(printbuffer * const output_buffer, size_t needed);
static cJSON_bool print_number(const cJSON * const item, printbuffer * const output_buffer);
static cJSON_bool print_string(const cJSON * const item, printbuffer * const output_buffer);
static cJSON_bool print_array(const cJSON * const item, printbuffer * const output_buffer);
static cJSON_bool print_object(const cJSON * const item, printbuffer * const output_buffer);