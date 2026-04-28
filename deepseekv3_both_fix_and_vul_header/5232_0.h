#include <stdlib.h>
#include <string.h>

typedef struct COMPS_HSList COMPS_HSList;
typedef struct COMPS_HSListItem COMPS_HSListItem;
typedef struct COMPS_MRTree COMPS_MRTree;
typedef struct COMPS_MRTreeData COMPS_MRTreeData;

struct COMPS_HSList {
    COMPS_HSListItem *first;
    COMPS_HSListItem *last;
};

struct COMPS_HSListItem {
    void *data;
    COMPS_HSListItem *next;
    COMPS_HSListItem *prev;
};

struct COMPS_MRTree {
    COMPS_HSList *subnodes;
};

struct COMPS_MRTreeData {
    char *key;
    COMPS_HSList *data;
    COMPS_HSList *subnodes;
};

COMPS_HSList* comps_hslist_create();
void comps_hslist_init(COMPS_HSList*, void*, void*, void*);
void comps_hslist_append(COMPS_HSList*, void*, int);
void comps_hslist_remove(COMPS_HSList*, COMPS_HSListItem*);
void comps_hslist_destroy(COMPS_HSList**);
void comps_mrtree_set(COMPS_MRTree*, char*, void*);