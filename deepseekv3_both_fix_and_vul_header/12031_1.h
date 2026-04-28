#include <stdint.h>
#include <limits.h>

typedef int gint;
typedef uint32_t guint32;
#define G_MAXUINT32 UINT32_MAX

typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct tvbuff_t tvbuff_t;
typedef struct expert_field expert_field;

extern expert_field ei_rtps_value_too_large;
extern int ReportedBoundsError;

#define THROW(x) /* implementation depends on your error handling */