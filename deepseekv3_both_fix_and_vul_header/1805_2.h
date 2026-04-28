#include <stdio.h>

typedef unsigned int u32;
typedef unsigned int GF_4CC;
typedef int GF_Err;

#define GF_OK 0
#define GF_ISOM_BOX_TYPE_UNKNOWN 0
#define GF_ISOM_BOX_TYPE_UUID 0
#define GF_ISOM_BOX_TYPE_GRPT 0

#define GF_4CC(a,b,c,d) (((a)<<24)|((b)<<16)|((c)<<8)|(d))

typedef struct GF_Box {
    GF_4CC type;
} GF_Box;

typedef struct GF_EntityToGroupTypeBox {
    GF_4CC grouping_type;
    u32 group_id;
    u32 entity_id_count;
    u32 *entity_ids;
    u32 size;
} GF_EntityToGroupTypeBox;

void gf_isom_box_dump_start(GF_Box *a, const char *name, FILE *trace);
void gf_isom_box_dump_done(const char *name, GF_Box *a, FILE *trace);
int gf_fprintf(FILE *trace, const char *format, ...);