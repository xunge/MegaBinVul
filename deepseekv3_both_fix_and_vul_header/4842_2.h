#include <stdint.h>
#include <string.h>

#define MAX_APN_LENGTH 100
#define _U_

typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint8_t guint8;
typedef unsigned int guint;
typedef int gint;
typedef char gchar;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct expert_field expert_field;

extern int hf_gsm_a_gm_apn;
extern expert_field ei_gsm_a_gm_extraneous_data;

void tvb_memcpy(const tvbuff_t *tvb, void *target, guint32 offset, guint length);
void proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, const char *value);
void EXTRANEOUS_DATA_CHECK_EXPERT(guint len, guint consumed_len, packet_info *pinfo, expert_field *expert_field);