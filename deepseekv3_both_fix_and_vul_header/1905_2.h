#include <stdlib.h>

typedef struct GF_Box GF_Box;
typedef struct GF_ISOFile GF_ISOFile;

struct GF_ISOFile {
    void *movieFileMap;
    void *editFileMap;
    char *finalName;
    void *TopBoxes;
    void *moof_list;
    void *mfra;
    void *sidx_pts_store;
    void *sidx_pts_next_store;
    void *main_sidx;
    void *block_buffer;
    void *emsgs;
    void *last_producer_ref_time;
    char *fileName;
};

void gf_isom_datamap_del(void *ptr);
void gf_isom_box_array_del(void *ptr);
void gf_isom_box_del(GF_Box *box);
void gf_free(void *ptr);