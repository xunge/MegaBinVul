#include <stdlib.h>

typedef struct GF_List GF_List;
typedef struct GF_Box GF_Box;
typedef struct GF_SampleTableBox {
    GF_List* child_boxes;
} GF_SampleTableBox;
typedef struct TrackWriter {
    GF_SampleTableBox* stbl;
    GF_Box* stco;
    GF_Box* stsc;
} TrackWriter;

unsigned int gf_list_count(GF_List* list);
void* gf_list_get(GF_List* list, unsigned int index);
void gf_list_del_item(GF_List* list, void* item);
void gf_list_rem(GF_List* list, unsigned int index);
void gf_isom_box_del(GF_Box* box);
void gf_free(void* ptr);