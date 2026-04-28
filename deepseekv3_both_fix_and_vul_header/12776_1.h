#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t jerry_value_t;
typedef uint32_t jerry_size_t;
typedef uint8_t jerry_char_t;

enum {
    JERRY_LOG_LEVEL_ERROR = 1,
    JERRY_ERROR_SYNTAX = 1
};

enum jerry_feature_t {
    JERRY_FEATURE_ERROR_MESSAGES
};

#define SYNTAX_ERROR_MAX_LINE_LENGTH 256

int jerry_value_is_error(jerry_value_t value);
jerry_value_t jerry_get_value_from_error(jerry_value_t value, bool flag);
int jerry_value_is_object(jerry_value_t value);
int jerry_value_is_string(jerry_value_t value);
int jerry_value_is_array(jerry_value_t value);
jerry_value_t jerry_value_to_string(jerry_value_t value);
jerry_size_t jerry_get_utf8_string_size(jerry_value_t value);
jerry_size_t jerry_string_to_utf8_char_buffer(jerry_value_t value, jerry_char_t* buffer, jerry_size_t size);
int jerry_is_feature_enabled(enum jerry_feature_t feature);
int jerry_get_error_type(jerry_value_t value);
jerry_value_t jerry_create_string(const jerry_char_t* str);
jerry_value_t jerry_get_property(jerry_value_t obj, jerry_value_t prop);
jerry_value_t jerry_get_property_by_index(jerry_value_t obj, uint32_t index);
uint32_t jerry_get_array_length(jerry_value_t array);
void jerry_release_value(jerry_value_t value);
void jerry_port_log(int level, const char* format, ...);
uint8_t* jerry_port_read_source(const char* path, size_t* size);
void jerry_port_release_source(uint8_t* source);