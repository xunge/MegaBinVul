#include <stdlib.h>
#include <string.h>

typedef unsigned long long ut64;
typedef unsigned int ut32;
typedef unsigned char ut8;

typedef struct RListIter {
    void *data;
    struct RListIter *n;
} RListIter;

typedef struct RList {
    RListIter *head;
} RList;

typedef struct RBinSection {
    char *name;
    ut64 paddr;
    ut64 size;
} RBinSection;

typedef struct RBinAddr {
    // 根据使用情况可能需要补充字段
} RBinAddr;

typedef struct RBinFile {
    void *buf;
    // 其他必要字段
} RBinFile;

enum {
    R_BIN_ENTRY_TYPE_FINI,
    R_BIN_ENTRY_TYPE_INIT,
    R_BIN_ENTRY_TYPE_PREINIT
};

#define r_list_foreach(list, it, pos) \
    for ((it) = (list)->head; (it) && ((pos) = (it)->data); (it) = (it)->n)

RList *sections(RBinFile *bf);
RBinAddr *newEntry(ut64 paddr, ut64 addr, int type, int bits);
int r_buf_read_at(void *buf, ut64 addr, void *data, int size);
ut32 r_read_le32(const void *src);
ut64 r_read_le64(const void *src);
void r_list_free(RList *list);
void r_list_append(RList *list, void *data);