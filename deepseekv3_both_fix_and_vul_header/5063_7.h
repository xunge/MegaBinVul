#include <stdint.h>
#include <stddef.h>

void ocall_throw(const char* what);
void non_oblivious_aggregate_step2(
  uint8_t *agg_op, size_t agg_op_length,
  uint8_t *input_rows, size_t input_rows_length,
  uint8_t *next_partition_first_row, size_t next_partition_first_row_length,
  uint8_t *prev_partition_last_group, size_t prev_partition_last_group_length,
  uint8_t *prev_partition_last_row, size_t prev_partition_last_row_length,
  uint8_t **output_rows, size_t *output_rows_length);

typedef struct {
  const char* (*what)(void);
} runtime_error;

#define try do {
#define catch(x) } while(0); if (0) {} else
runtime_error e;