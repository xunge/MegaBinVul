#include <stdlib.h>
#include <string.h>

typedef struct COMPS_HSList COMPS_HSList;
typedef struct COMPS_HSListItem COMPS_HSListItem;
typedef struct COMPS_RTree COMPS_RTree;
typedef struct COMPS_RTreeData COMPS_RTreeData;

struct COMPS_HSList {
    COMPS_HSListItem *first;
    COMPS_HSListItem *last;
};

struct COMPS_HSListItem {
    void *data;
    COMPS_HSListItem *next;
    COMPS_HSListItem *prev;
};

struct COMPS_RTree {
    COMPS_HSList *subnodes;
    void *(*data_cloner)(void*);
};

struct COMPS_RTreeData {
    char *key;
    void *data;
    COMPS_HSList *subnodes;
};

COMPS_HSList* comps_hslist_create();
void comps_hslist_init(COMPS_HSList*, void*, void*, void*);
void comps_hslist_append(COMPS_HSList*, void*, int);
void comps_hslist_remove(COMPS_HSList*, COMPS_HSListItem*);
void comps_hslist_destroy(COMPS_HSList**);
void comps_rtree_set(COMPS_RTree*, char*, void*);