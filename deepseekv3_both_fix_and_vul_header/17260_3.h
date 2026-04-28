#include <stdint.h>
#include <stddef.h>

#define NO_MORE_DATA_CHECK(len) \
    if ((uint32_t)(curr_offset - offset) >= len) \
        return (len);

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint32_t guint;
typedef char gchar;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

#define ENC_BIG_ENDIAN 0
#define ENC_NA 1

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;
typedef struct {
    int dummy;
} expert_field;
#define EI_INIT {0}

static int hf_gsm_a_extension = -1;
static int hf_gsm_a_dtap_type_of_sub_addr = -1;
static int hf_gsm_a_dtap_odd_even_ind = -1;
static int hf_gsm_a_spare_bits = -1;
static int hf_gsm_a_dtap_afi = -1;
static int hf_gsm_a_dtap_subaddress = -1;
static int hf_gsm_a_dtap_subaddress_information = -1;

static expert_field ei_gsm_a_dtap_invalid_ia5_character = EI_INIT;

void IA5_7BIT_decode(gchar *output, guint8 *input, guint32 length);
void *wmem_alloc(void *scope, size_t size);
void *wmem_packet_scope(void);
void *tvb_memdup(void *scope, const tvbuff_t *tvb, int offset, int length);
guint8 tvb_get_guint8(const tvbuff_t *tvb, int offset);
void proto_tree_add_item(proto_tree *tree, int hfindex, const tvbuff_t *tvb, int start, int length, int encoding);
void proto_tree_add_bits_item(proto_tree *tree, int hfindex, const tvbuff_t *tvb, int bit_offset, int no_of_bits, int encoding);
proto_item *proto_tree_add_string(proto_tree *tree, int hfindex, const tvbuff_t *tvb, int start, int length, const char *str);
void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *expert);