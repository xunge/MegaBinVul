#include <stdlib.h>
#include <string.h>

typedef struct COMPS_HSList COMPS_HSList;
typedef struct COMPS_HSListItem COMPS_HSListItem;
typedef struct COMPS_ObjListIt COMPS_ObjListIt;
typedef struct COMPS_ObjMRTree COMPS_ObjMRTree;
typedef struct COMPS_ObjMRTreeData COMPS_ObjMRTreeData;

struct COMPS_HSList {
    COMPS_HSListItem *first;
    COMPS_HSListItem *last;
};

struct COMPS_HSListItem {
    void *data;
    COMPS_HSListItem *next;
};

struct COMPS_ObjListIt {
    void *comps_obj;
    COMPS_ObjListIt *next;
};

struct COMPS_ObjMRTree {
    COMPS_HSList *subnodes;
};

struct COMPS_ObjMRTreeData {
    char *key;
    COMPS_HSList *subnodes;
    COMPS_HSList *data;
};

COMPS_HSList* comps_hslist_create();
void comps_hslist_init(COMPS_HSList*, void*, void*, void*);
void comps_hslist_append(COMPS_HSList*, void*, int);
void comps_hslist_remove(COMPS_HSList*, COMPS_HSListItem*);
void comps_hslist_destroy(COMPS_HSList**);
void comps_objmrtree_set(COMPS_ObjMRTree*, char*, void*);