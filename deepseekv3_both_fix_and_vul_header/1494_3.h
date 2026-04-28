#include <stdlib.h>

#define rz_return_val_if_fail(cond, val) if (!(cond)) return (val)
#define RZ_NEW0(type) (type*)calloc(1, sizeof(type))
#define rz_list_foreach(list, it, data) \
    for (it = rz_list_iterator(list); it && ((data = rz_list_iter_get_data(it)) || 1); rz_list_iter_next(it))

typedef struct rz_list_t RzList;
typedef struct rz_list_iter_t RzListIter;
typedef struct rz_bin_reloc_t RzBinReloc;
typedef struct qnx_obj_t QnxObj;
typedef struct rz_bin_file_t RzBinFile;

struct rz_bin_file_t {
    struct {
        QnxObj *bin_obj;
    } *o;
};

struct qnx_obj_t {
    RzList *fixups;
};

struct rz_bin_reloc_t {
    unsigned long vaddr;
    unsigned long paddr;
    int type;
};

RzList *rz_list_newf(void (*free)(void*));
RzList *rz_list_clone(RzList *list);
void rz_list_append(RzList *list, void *data);
RzListIter *rz_list_iterator(RzList *list);
void *rz_list_iter_get_data(RzListIter *iter);
void rz_list_iter_next(RzListIter *iter);