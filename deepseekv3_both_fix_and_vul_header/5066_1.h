#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <stdexcept>

extern "C" {
int sgx_is_outside_enclave(const void *addr, size_t size);
void sgx_lfence(void);
void ocall_throw(const char *what);
void non_oblivious_aggregate_step1(
    uint8_t *agg_op, size_t agg_op_length,
    uint8_t *input_rows, size_t input_rows_length,
    uint8_t **first_row, size_t *first_row_length,
    uint8_t **last_group, size_t *last_group_length,
    uint8_t **last_row, size_t *last_row_length);
}