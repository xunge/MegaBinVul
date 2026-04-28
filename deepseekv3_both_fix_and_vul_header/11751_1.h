#include <stdint.h>

typedef uint32_t guint;
typedef struct tvbuff tvbuff_t;
typedef struct _packet_info packet_info;
typedef struct _einfo expert_field;

extern expert_field ei_mmse_oversized_uintvar;

guint tvb_get_guint8(tvbuff_t *tvb, guint offset);
guint tvb_get_guintvar(tvbuff_t *tvb, guint offset, guint *byte_count, packet_info *pinfo, expert_field *ei);