#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint32_t jerry_value_t;
typedef uint32_t jerry_size_t;
typedef uint8_t jerry_char_t;
typedef enum {
  JERRY_ENCODING_UTF8,
} jerry_encoding_t;
typedef enum {
  JERRY_LOG_LEVEL_ERROR,
} jerry_log_level_t;
typedef enum {
  JERRY_ERROR_SYNTAX,
} jerry_error_t;
typedef enum {
  JERRY_FEATURE_ERROR_MESSAGES,
} jerry_feature_t;

#define JERRYX_PRINT_BUFFER_SIZE 256
#define JERRYX_SYNTAX_ERROR_MAX_LINE_LENGTH 256
#define JERRY_VLA(type, name, size) type name[size]

int jerry_value_is_exception(jerry_value_t value);
int jerry_value_is_object(jerry_value_t value);
int jerry_value_is_string(jerry_value_t value);
int jerry_value_is_array(jerry_value_t value);
jerry_value_t jerry_exception_value(jerry_value_t exception, bool flag);
jerry_value_t jerry_value_to_string(jerry_value_t value);
jerry_size_t jerry_string_to_buffer(jerry_value_t string, jerry_encoding_t encoding, jerry_char_t* buffer, jerry_size_t buffer_size);
int jerry_feature_enabled(jerry_feature_t feature);
jerry_error_t jerry_error_type(jerry_value_t value);
jerry_char_t* jerry_port_source_read(const char* path, jerry_size_t* size);
void jerry_port_source_free(jerry_char_t* source);
void jerry_log(jerry_log_level_t level, const char* format, ...);
void jerry_value_free(jerry_value_t value);
jerry_value_t jerry_object_get_sz(jerry_value_t object, const char* key);
uint32_t jerry_array_length(jerry_value_t array);
jerry_value_t jerry_object_get_index(jerry_value_t object, uint32_t index);