#include <stdint.h>
#include <stdlib.h>

typedef struct _fluid_list_t {
    void *data;
    struct _fluid_list_t *next;
} fluid_list_t;

typedef union {
    short sword;
    unsigned short uword;
    struct {
        unsigned char lo;
        unsigned char hi;
    } range;
} SFGenAmount;

typedef struct _SFGen {
    unsigned short id;
    SFGenAmount amount;
} SFGen;

typedef struct _SFZone {
    fluid_list_t *gen;
    void *instsamp;
} SFZone;

typedef struct _SFPreset {
    char *name;
    fluid_list_t *zone;
} SFPreset;

typedef struct _SFData {
    fluid_list_t *preset;
} SFData;

#define SF_GEN_SIZE 4
#define FALSE 0
#define TRUE 1
#define FLUID_ERR 1
#define FLUID_WARN 2
#define FLUID_INT_TO_POINTER(x) ((void*)(intptr_t)(x))

enum {
    Gen_KeyRange,
    Gen_VelRange,
    Gen_Instrument
};

#define READW(sf, val) 
#define READB(sf, val) 
#define FSKIP(sf, size) 
#define FSKIPW(sf) 
#define SLADVREM(list, item) 
#define FLUID_NEW(type) malloc(sizeof(type))
#define FLUID_LOG(level, msg, ...) 

static fluid_list_t* fluid_list_next(fluid_list_t* list) { return list ? list->next : NULL; }
static fluid_list_t* fluid_list_prepend(fluid_list_t* list, void* data) {
    fluid_list_t* new_item = malloc(sizeof(fluid_list_t));
    new_item->data = data;
    new_item->next = list;
    return new_item;
}
static void* fluid_list_get(fluid_list_t* list) { return list ? list->data : NULL; }
static fluid_list_t* fluid_list_remove(fluid_list_t* list, void* data) {
    fluid_list_t *prev = NULL, *curr = list;
    while(curr) {
        if(curr->data == data) {
            if(prev) prev->next = curr->next;
            else list = curr->next;
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return list;
}
static int valid_preset_genid(unsigned short genid) { return 1; }
static fluid_list_t* find_gen_by_id(unsigned short genid, fluid_list_t* list) {
    while(list) {
        SFGen* g = (SFGen*)list->data;
        if(g && g->id == genid) return list;
        list = list->next;
    }
    return NULL;
}
static void delete_zone(SFZone* zone) { free(zone); }