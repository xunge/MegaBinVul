#include <stdio.h>
#include <string.h>

typedef unsigned int u32;
typedef int GF_Err;
#define GF_OK 0

typedef struct GF_Box GF_Box;
typedef struct GF_HandlerBox {
    GF_Box *box;
    u32 handlerType;
    u32 reserved1;
    char reserved2[12];
    char *nameUTF8;
} GF_HandlerBox;

const char *gf_4cc_to_str(u32 type);
void gf_isom_box_dump_start(GF_Box *a, const char *name, FILE *trace);
void gf_isom_box_dump_done(const char *name, GF_Box *a, FILE *trace);
void dump_data(FILE *trace, const char *data, int length);