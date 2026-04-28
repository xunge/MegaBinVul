#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef int GF_Err;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned long long u64;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;
typedef struct GF_DataBox GF_DataBox;
typedef struct GF_ListItemBox GF_ListItemBox;
typedef struct __tag_GF_List GF_List;

#define GF_OK 0
#define GF_ISOM_INVALID_FILE 1
#define GF_NON_COMPLIANT_BITSTREAM 2
#define GF_LOG_ERROR 1
#define GF_LOG_CONTAINER 2
#define GF_ISOM_BOX_TYPE_DATA 0x64617461
#define GF_ISOM_BOX_TYPE_VOID 0x766F6964
#define GF_TRUE 1

struct GF_Box {
    u32 type;
    u64 size;
    GF_List *child_boxes;
};

struct GF_DataBox {
    GF_Box box;
    u16 dataSize;
    char *data;
    int qt_style;
};

struct GF_ListItemBox {
    GF_Box box;
    GF_DataBox *data;
    GF_List *child_boxes;
    u32 type;  // Added missing type member
    u64 size;  // Added missing size member
};

GF_Err gf_isom_box_parse(GF_Box **box, GF_BitStream *bs);
void gf_isom_box_del(GF_Box *box);
void gf_isom_box_del_parent(GF_List **list, GF_Box *box);
GF_Box *gf_isom_box_new_parent(GF_List **list, u32 type);
GF_Err gf_isom_box_array_read(GF_Box *s, GF_BitStream *bs, void *param);
void gf_isom_box_array_del(GF_List *list);
u32 gf_bs_peek_bits(GF_BitStream *bs, u32 numBits, u32 byte_offset);
u64 gf_bs_get_position(GF_BitStream *bs);
void gf_bs_seek(GF_BitStream *bs, u64 position);
u16 gf_bs_read_u16(GF_BitStream *bs);
u32 gf_bs_read_data(GF_BitStream *bs, char *data, u32 size);
const char *gf_4cc_to_str(u32 type);
GF_List *gf_list_new();
void gf_list_add(GF_List *list, void *item);
void *gf_malloc(size_t size);

#define ISOM_DECREASE_SIZE(ptr, amount) (ptr)->size -= (amount)

static void GF_LOG(int log_level, int log_type, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}