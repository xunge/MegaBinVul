#include <stdlib.h>

typedef unsigned int u32;
typedef struct GF_Box {
    u32 type;
} GF_Box;
typedef struct GF_HintMediaHeaderBox {
    u32 type;
    u32 subType;
} GF_HintMediaHeaderBox;
typedef struct GF_SampleDescriptionBox {
    struct GF_List *child_boxes;
} GF_SampleDescriptionBox;
typedef struct GF_SampleTableBox {
    GF_SampleDescriptionBox *SampleDescription;
} GF_SampleTableBox;
typedef struct GF_MediaInformationBox {
    GF_Box *InfoHeader;
    GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;
typedef struct GF_MediaBox {
    GF_MediaInformationBox *information;
} GF_MediaBox;
typedef struct GF_TrackBox {
    GF_MediaBox *Media;
} GF_TrackBox;
typedef struct GF_List {
    void *items;
} GF_List;

#define GF_ISOM_BOX_TYPE_HMHD 0