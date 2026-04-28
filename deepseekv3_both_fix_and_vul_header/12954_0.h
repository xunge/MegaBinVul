#include <stdint.h>

typedef enum {
    LZW_OK,
    LZW_EOI_CODE,
    LZW_BAD_CODE
} lzw_result;

#define LZW_CODE_MAX 12

struct lzw_ctx {
    const uint8_t *input;
    uint8_t *stack_base;
    uint32_t clear_code;
    uint32_t eoi_code;
    uint32_t current_entry;
    uint8_t current_code_size;
    uint16_t current_code_size_max;
    uint32_t previous_code;
    uint8_t previous_code_first;
    struct lzw_dictionary_entry *table;
};

struct lzw_dictionary_entry {
    uint8_t last_value;
    uint8_t first_value;
    uint32_t previous_entry;
};

lzw_result lzw__next_code(const uint8_t **input, uint8_t code_size, uint32_t *code);
lzw_result lzw__clear_codes(struct lzw_ctx *ctx, const uint8_t **stack_pos_out);