#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum {
    OK_CSV_RECORD_START,
    OK_CSV_FIELD_START,
    OK_CSV_ESCAPED_FIELD,
    OK_CSV_NONESCAPED_FIELD
} ok_csv_decoder_state;

typedef struct {
    uint8_t *data;
    size_t start;
    size_t length;
    size_t capacity;
} ok_csv_circular_buffer;

typedef struct {
    char ***fields;
    size_t *num_fields;
    size_t num_records;
    size_t records_capacity;
} ok_csv;

typedef struct {
    ok_csv *csv;
    ok_csv_circular_buffer input_buffer;
    void *input_data;
    size_t (*input_read_func)(void *, uint8_t *, size_t);
} ok_csv_decoder;