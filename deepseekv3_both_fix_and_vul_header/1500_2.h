#include <stdlib.h>

typedef struct RzList RzList;
typedef struct RzBinFile {
    struct {
        void *bin_obj;
    } *o;
} RzBinFile;

typedef struct {
    RzList *string_list;
} LuacBinInfo;

#define GET_INTERNAL_BIN_INFO_OBJ(bf) ((LuacBinInfo *)(bf)->o->bin_obj)