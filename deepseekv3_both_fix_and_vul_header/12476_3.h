#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct _fluid_list_t {
    void *data;
    struct _fluid_list_t *next;
} fluid_list_t;

typedef struct SFData {
    fluid_list_t *inst;
} SFData;

typedef struct SFInst {
    char *name;
    fluid_list_t *zone;
} SFInst;

typedef struct SFZone {
    fluid_list_t *gen;
    void *instsamp;
} SFZone;

typedef union SFGenAmount {
    struct {
        unsigned char lo;
        unsigned char hi;
    } range;
    short sword;
    unsigned short uword;
} SFGenAmount;

typedef struct SFGen {
    unsigned short id;
    SFGenAmount amount;
} SFGen;

typedef struct SFPreset {
    char *name;
} SFPreset;

#define FLUID_ERR 1
#define FLUID_WARN 2
#define FLUID_INT_TO_POINTER(x) ((void*)(intptr_t)(x))
#define FLUID_NEW(type) malloc(sizeof(type))
#define FALSE 0
#define TRUE 1
#define SF_GEN_SIZE 4

enum {
    Gen_KeyRange,
    Gen_VelRange,
    Gen_SampleId
};

#define READW(sf, var) /* implementation */
#define READB(sf, var) /* implementation */
#define FSKIPW(sf) /* implementation */
#define FSKIP(sf, size) /* implementation */

static void FLUID_LOG(int level, const char *msg, ...);
static int valid_inst_genid(unsigned short genid);
static fluid_list_t* find_gen_by_id(unsigned short genid, fluid_list_t* list);
static void delete_zone(SFZone* zone);
static void SLADVREM(fluid_list_t* list, fluid_list_t* item);
static fluid_list_t* fluid_list_next(fluid_list_t* list);
static fluid_list_t* fluid_list_prepend(fluid_list_t* list, void* data);
static void* fluid_list_get(fluid_list_t* list);
static fluid_list_t* fluid_list_remove(fluid_list_t* list, void* item);