#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;

typedef struct {
    u32 type;
    u32 laser_strings;
    void *values;
} SMIL_AnimateValues;

typedef struct {
    void *far_ptr;
} GF_FieldInfo;

typedef struct {
    int last_error;
} GF_LASeRCodec;

typedef struct {
} GF_Node;

#define GF_LSR_READ_INT(a, b, c, d)
#define GF_TRUE 1
#define TAG_SVG_ATT_values 0

u32 lsr_read_vluimsbf5(GF_LASeRCodec *lsr, const char *str);
void *lsr_read_an_anim_value(GF_LASeRCodec *lsr, u32 type, const char *str);
int gf_node_get_attribute_by_tag(GF_Node *n, u32 tag, int flag, u32 index, GF_FieldInfo *info);
void gf_list_add(void *list, void *item);
void lsr_translate_anim_trans_values(void *ptr, u32 type);