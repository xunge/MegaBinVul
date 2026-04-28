#include <stdio.h>

typedef unsigned int GF_Err;
typedef unsigned int GF_4CC;
typedef struct GF_Box GF_Box;
typedef struct GF_UnknownBox GF_UnknownBox;
typedef struct GF_TrackGroupTypeBox GF_TrackGroupTypeBox;

#define GF_OK 0
#define GF_ISOM_BOX_TYPE_UNKNOWN 0
#define GF_ISOM_BOX_TYPE_UUID 1
#define GF_ISOM_BOX_TYPE_TRGT 2

#define GF_4CC(a,b,c,d) (((a)<<24)|((b)<<16)|((c)<<8)|(d))

struct GF_Box {
    unsigned int type;
};

struct GF_TrackGroupTypeBox {
    GF_Box box;
    unsigned int group_type;
    unsigned int track_group_id;
};

void gf_isom_box_dump_start(GF_Box *a, const char *name, FILE *trace);
void gf_isom_box_dump_done(const char *name, GF_Box *a, FILE *trace);
int gf_fprintf(FILE *trace, const char *format, ...);