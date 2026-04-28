#include <stdint.h>
#include <stdlib.h>

typedef struct _fluid_list_t {
    void *data;
    struct _fluid_list_t *next;
} fluid_list_t;

typedef struct _SFData {
    fluid_list_t *inst;
} SFData;

typedef struct _SFInst {
    fluid_list_t *zone;
    char *name;
} SFInst;

typedef struct _SFZone {
    fluid_list_t *gen;
    void *instsamp;
} SFZone;

typedef union {
    struct {
        unsigned char lo;
        unsigned char hi;
    } range;
    short sword;
    unsigned short uword;
} SFGenAmount;

typedef struct _SFGen {
    unsigned short id;
    SFGenAmount amount;
} SFGen;

typedef struct _SFPreset {
    char *name;
} SFPreset;

enum {
    Gen_KeyRange,
    Gen_VelRange,
    Gen_SampleId
};

#define FALSE 0
#define TRUE 1
#define FLUID_ERR 1
#define FLUID_WARN 2
#define SF_GEN_SIZE 4

#define FLUID_LOG(level, ...)
#define READW(sf, var)
#define READB(sf, var)
#define FSKIPW(sf)
#define FSKIP(sf, size)
#define FLUID_NEW(type) malloc(sizeof(type))
#define FLUID_INT_TO_POINTER(i) ((void*)(intptr_t)(i))
#define SLADVREM(list, item)
#define fluid_list_next(list) ((list)->next)
#define fluid_list_prepend(list, data) NULL
#define fluid_list_remove(list, data) NULL
#define fluid_list_get(list) ((list)->data)

static int valid_inst_genid(unsigned short genid) { return 0; }
static fluid_list_t* find_gen_by_id(unsigned short genid, fluid_list_t* list) { return NULL; }
static void delete_zone(SFZone* zone) {}