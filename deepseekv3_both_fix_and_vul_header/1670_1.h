#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define ogs_assert assert
#define OGS_LOG_FATAL 0

typedef struct ogs_tlv_s ogs_tlv_t;
typedef struct ogs_tlv_desc_s ogs_tlv_desc_t;

struct ogs_tlv_s {
    ogs_tlv_t *next;
};

extern ogs_tlv_t *ogs_tlv_get(void);
extern void ogs_tlv_free_all(ogs_tlv_t *root);
extern uint8_t *tlv_get_element_desc(ogs_tlv_t *curr, uint8_t *pos, uint8_t msg_mode, ogs_tlv_desc_t *desc);
extern void ogs_error(const char *fmt, ...);
extern void ogs_log_hexdump(int level, void *data, int length);