#include <stdlib.h>
#include <string.h>

typedef struct COMPS_HSList COMPS_HSList;
typedef struct COMPS_HSListItem COMPS_HSListItem;
typedef struct COMPS_ObjRTree COMPS_ObjRTree;
typedef struct COMPS_ObjRTreeData COMPS_ObjRTreeData;

struct COMPS_HSList {
    COMPS_HSListItem *first;
    COMPS_HSListItem *last;
};

struct COMPS_HSListItem {
    void *data;
    COMPS_HSListItem *next;
};

struct COMPS_ObjRTree {
    COMPS_HSList *subnodes;
};

struct COMPS_ObjRTreeData {
    char *key;
    void *data;
    COMPS_HSList *subnodes;
};

COMPS_HSList* comps_hslist_create();
void comps_hslist_init(COMPS_HSList*, void (*)(void*), void (*)(void*), void (*)(void*));
void comps_hslist_append(COMPS_HSList*, void*, unsigned char);
void comps_hslist_remove(COMPS_HSList*, COMPS_HSListItem*);
void comps_hslist_destroy(COMPS_HSList**);
void comps_objrtree_set(COMPS_ObjRTree*, const char*, void*);