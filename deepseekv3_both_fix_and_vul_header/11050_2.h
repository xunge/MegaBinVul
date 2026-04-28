#include <stdbool.h>

typedef int GF_Err;
typedef bool Bool;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;
typedef struct GF_MediaInformationBox GF_MediaInformationBox;
typedef struct GF_DataInformationBox GF_DataInformationBox;
typedef struct GF_FullBox GF_FullBox;

#define GF_LOG_ERROR 0
#define GF_LOG_CONTAINER 0
#define GF_ISOM_BOX_TYPE_DINF 0
#define GF_ISOM_BOX_TYPE_DREF 0
#define GF_ISOM_BOX_TYPE_URL 0
#define GF_OUT_OF_MEM 0
#define GF_ISOM_INVALID_FILE 0
#define GF_FALSE false
#define GF_TRUE true

extern GF_Err gf_isom_box_array_read(GF_Box *s, GF_BitStream *bs, GF_Err (*)(GF_Box*, GF_Box*));
extern GF_Err minf_AddBox(GF_Box *parent, GF_Box *child);
extern void GF_LOG(int level, int category, const char *format, ...);
extern GF_Box *gf_isom_box_new(int type);
extern int gf_list_find(void *list, void *item);
extern GF_Err dinf_AddBox(GF_Box *dinf, GF_Box *dref);
extern GF_Err gf_isom_box_add_default(GF_Box *dref, GF_Box *url);
extern void gf_list_add(void *list, void *item);
extern void *gf_list_new();

struct GF_MediaInformationBox {
    GF_DataInformationBox *dataInformation;
    GF_Box *InfoHeader;
    GF_Box *sampleTable;
    void *other_boxes;
};

struct GF_DataInformationBox {
    void *other_boxes;
};

struct GF_FullBox {
    unsigned int flags;
};

struct GF_Box {
    void *other_boxes;
};