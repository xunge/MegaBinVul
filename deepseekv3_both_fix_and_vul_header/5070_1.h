#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include <stdexcept>

extern "C" {
int sgx_is_outside_enclave(const void *addr, size_t size);
void sgx_lfence(void);
void ocall_throw(const char *what);
void find_range_bounds(uint8_t *sort_order, size_t sort_order_length,
                      uint32_t num_partitions,
                      uint8_t *input_rows, size_t input_rows_length,
                      uint8_t **output_rows, size_t *output_rows_length);
}