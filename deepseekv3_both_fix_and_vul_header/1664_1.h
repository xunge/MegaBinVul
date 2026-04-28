#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ogs_tlv_s {
    struct ogs_tlv_s *next;
} ogs_tlv_t;

extern ogs_tlv_t *ogs_tlv_get(void);
extern uint8_t *tlv_get_element(ogs_tlv_t *curr, uint8_t *pos, uint8_t mode);
extern void ogs_fatal(const char *fmt, ...);
extern void ogs_log_hexdump(int level, void *data, uint32_t length);
extern void ogs_assert_if_reached(void);

#define ogs_assert(expr) assert(expr)
#define OGS_LOG_FATAL 1