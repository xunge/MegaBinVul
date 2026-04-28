#include <stdlib.h>

#define LIBETPAN_EXPORT

struct mailimap_mailbox_data_status {
    void* st_mailbox;
    void* st_info_list;
};

typedef void (*clist_func)(void*);
void clist_foreach(void* list, clist_func func, void* data);
void clist_free(void* list);
void mailimap_mailbox_free(void* mailbox);
void mailimap_status_info_free(void* status_info);