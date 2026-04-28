#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include <stdexcept>

extern "C" {
    int sgx_is_outside_enclave(const void *addr, size_t size);
    void sgx_lfence(void);
    void ocall_throw(const char *str);
}

void non_oblivious_sort_merge_join(uint8_t *join_expr, size_t join_expr_length,
                                  uint8_t *input_rows, size_t input_rows_length,
                                  uint8_t *join_row, size_t join_row_length,
                                  uint8_t **output_rows, size_t *output_rows_length);