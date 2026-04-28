#include <stdlib.h>
#include <string.h>

typedef unsigned char GF_Bool;
#define GF_FALSE 0
#define GF_TRUE 1

typedef unsigned short u16;
typedef unsigned int u32;
typedef int GF_Err;

typedef struct __tag_bitstream GF_BitStream;

typedef struct {
    u16 len;
    char *text;
    struct {
        u32 entry_count;
        void *styles;
    } *styles;
    void *others;
    void *cur_karaoke;
    void *highlight_color;
    void *scroll_delay;
    void *box;
    void *wrap;
    GF_Bool is_forced;
} GF_TextSample;

typedef struct {
    u32 type;
} GF_Box;

typedef struct {
    GF_Box box;
    u32 entry_count;
    void *styles;
} GF_TextStyleBox;

typedef struct {
    /* style record fields */
} GF_StyleRecord;

typedef struct {
    GF_Box box;
} GF_TextKaraokeBox;

typedef struct {
    GF_Box box;
} GF_TextHighlightColorBox;

typedef struct {
    GF_Box box;
} GF_TextScrollDelayBox;

typedef struct {
    GF_Box box;
} GF_TextBoxBox;

typedef struct {
    GF_Box box;
} GF_TextWrapBox;

#define GF_EXPORT
#define GF_ISOM_BOX_TYPE_STYL 0x7374796C
#define GF_ISOM_BOX_TYPE_KROK 0x6B726F6B
#define GF_ISOM_BOX_TYPE_HLIT 0x686C6974
#define GF_ISOM_BOX_TYPE_HREF 0x68726566
#define GF_ISOM_BOX_TYPE_BLNK 0x626C6E6B
#define GF_ISOM_BOX_TYPE_HCLR 0x68636C72
#define GF_ISOM_BOX_TYPE_DLAY 0x646C6179
#define GF_ISOM_BOX_TYPE_TBOX 0x74626F78
#define GF_ISOM_BOX_TYPE_TWRP 0x74777270
#define GF_QT_BOX_TYPE_FRCD   0x66726364

GF_TextSample *gf_isom_new_text_sample(void);
void *gf_malloc(size_t size);
void *gf_realloc(void *ptr, size_t size);
u16 gf_bs_read_u16(GF_BitStream *bs);
int gf_bs_available(GF_BitStream *bs);
void gf_bs_read_data(GF_BitStream *bs, char *data, u32 size);
GF_Err gf_isom_box_parse(GF_Box **box, GF_BitStream *bs);
void gf_isom_box_del(GF_Box *box);
void gf_list_add(void *list, void *item);