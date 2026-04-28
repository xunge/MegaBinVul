#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define BGP_AIGP_TLV_METRIC 1
#define BGP_AIGP_TLV_METRIC_LEN 11
#define BGP_AIGP_TLV_METRIC_DESC "AIGP Metric"

extern void zlog_err(const char *format, ...);
extern void ptr_get_be16(uint8_t *p, uint16_t *val);