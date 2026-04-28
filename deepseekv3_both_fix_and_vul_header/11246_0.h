#include <stdlib.h>

#define FREE_IF(ptr) do { if (ptr) free(ptr); } while (0)

typedef enum {
    DWG_SUPERTYPE_OBJECT,
    DWG_SUPERTYPE_ENTITY
} Dwg_SuperType;

typedef struct {
    void* raw;
    void* data;
    unsigned int size;
} Dwg_EED;

typedef struct {
    unsigned int num_eed;
    Dwg_EED* eed;
} Dwg_Object_Object;

typedef struct {
    unsigned int num_eed;
    Dwg_EED* eed;
} Dwg_Object_Entity;

typedef struct {
    Dwg_SuperType supertype;
    union {
        Dwg_Object_Object* object;
        Dwg_Object_Entity* entity;
    } tio;
} Dwg_Object;