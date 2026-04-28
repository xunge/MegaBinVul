#include <stdint.h>
#include <stddef.h>

typedef uint16_t U_16;
typedef uintptr_t UDATA;

struct J9Method;
struct J9ROMClass;

struct J9InitialMethods {
    void *initialSpecialMethod;
};

struct J9JavaVM {
    struct J9InitialMethods initialMethods;
};

struct J9Class {
    struct J9ROMClass *romClass;
    struct J9Method **specialSplitMethodTable;
};

struct J9ConstantPool {
    struct J9Class *ramClass;
};

struct J9VMThread {
    struct J9JavaVM *javaVM;
};

#define J9ROMCLASS_SPECIALSPLITMETHODREFINDEXES(romClass) ((uint8_t*)(romClass) + 0)
#define J9_ARE_NO_BITS_SET(flags, bits) (((flags) & (bits)) == 0)
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x1

struct J9Method *resolveSpecialMethodRefInto(struct J9VMThread *vmStruct, struct J9ConstantPool *ramCP, U_16 cpIndex, UDATA resolveFlags, void *unused);