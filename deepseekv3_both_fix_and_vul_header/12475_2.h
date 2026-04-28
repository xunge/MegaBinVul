#include <stdint.h>
#include <stdlib.h>

typedef struct _fluid_list_t {
    void *data;
    struct _fluid_list_t *next;
} fluid_list_t;

typedef struct {
    fluid_list_t *preset;
} SFData;

typedef struct {
    fluid_list_t *gen;
    void *instsamp;
} SFZone;

typedef struct {
    char *name;
    fluid_list_t *zone;
} SFPreset;

typedef union {
    short sword;
    unsigned short uword;
    struct {
        unsigned char lo;
        unsigned char hi;
    } range;
} SFGenAmount;

typedef struct {
    unsigned short id;
    SFGenAmount amount;
} SFGen;

#define FALSE 0
#define TRUE 1

#define FLUID_ERR 1
#define FLUID_WARN 2
#define FLUID_LOG(level, ...)

#define FLUID_NEW(type) malloc(sizeof(type))
#define FLUID_INT_TO_POINTER(i) ((void*)(intptr_t)(i))

#define SF_GEN_SIZE 4

#define Gen_KeyRange 0
#define Gen_VelRange 1
#define Gen_Instrument 2

#define READW(sf, val)
#define READB(sf, val)
#define FSKIPW(sf)
#define FSKIP(sf, size)

static fluid_list_t* fluid_list_next(fluid_list_t* list) { return list ? list->next : NULL; }
static fluid_list_t* fluid_list_prepend(fluid_list_t* list, void* data) {
    fluid_list_t* new = malloc(sizeof(fluid_list_t));
    new->data = data;
    new->next = list;
    return new;
}
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
static void* fluid_list_get(fluid_list_t* list) { return list ? list->data : NULL; }
static void SLADVREM(fluid_list_t** list, fluid_list_t* item) {
    fluid_list_t *prev = NULL, *curr = *list;
    while(curr) {
        if(curr == item) {
            if(prev) prev->next = curr->next;
            else *list = curr->next;
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}
static int valid_preset_genid(unsigned short genid) { return genid < 3; }
static fluid_list_t* find_gen_by_id(unsigned short genid, fluid_list_t* list) {
    while(list) {
        SFGen* g = list->data;
        if(g->id == genid) return list;
        list = list->next;
    }
    return NULL;
}
static void delete_zone(SFZone* zone) { free(zone); }