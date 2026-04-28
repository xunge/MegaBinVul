#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ogs_tlv_s {
    struct ogs_tlv_s *next;
} ogs_tlv_t;

#define OGS_LOG_FATAL 1

ogs_tlv_t *ogs_tlv_get(void);
uint8_t *tlv_get_element(ogs_tlv_t *curr, uint8_t *pos, uint8_t mode);
void ogs_assert(bool condition);
void ogs_fatal(const char *fmt, ...);
void ogs_log_hexdump(int level, void *data, size_t length);
void ogs_assert_if_reached(void);