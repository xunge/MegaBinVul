#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct J9VMThread {
    struct J9JavaVM *javaVM;
} J9VMThread;

typedef struct J9Method J9Method;

typedef struct J9ROMConstantPoolItem {
    uint32_t data1;
    uint32_t data2;
} J9ROMConstantPoolItem;

typedef struct J9ConstantPool {
    J9ROMConstantPoolItem *romConstantPool;
} J9ConstantPool;

typedef struct J9ROMFieldShape {
    uint32_t modifiers;
    struct J9UTF8 *signature;
} J9ROMFieldShape;

typedef struct J9RAMFieldRef {
    uint32_t valueOffset;
    uint32_t flags;
} J9RAMFieldRef;

typedef struct J9ROMFieldRef {
    uint16_t classRefCPIndex;
    uint8_t pad[2];
} J9ROMFieldRef;

typedef struct J9Class {
    struct J9ROMClass *romClass;
    struct J9ClassLoader *classLoader;
    struct J9FlattenedClassCache *flattenedClassCache;
    uint32_t packageID;
    uint32_t classFlags;
    struct J9ConstantPool *ramConstantPool;
} J9Class;

typedef struct J9JavaVM {
    struct J9ClassLoader *systemClassLoader;
    uint32_t runtimeFlags;
} J9JavaVM;

typedef struct J9ROMNameAndSignature {
    struct J9UTF8 *name;
    struct J9UTF8 *signature;
} J9ROMNameAndSignature;

typedef struct J9UTF8 {
    uint8_t *data;
    uint16_t length;
} J9UTF8;

typedef struct J9ClassLoader J9ClassLoader;
typedef struct J9FlattenedClassCache {
    struct J9FlattenedClassCacheEntry *entries;
} J9FlattenedClassCache;

typedef struct J9FlattenedClassCacheEntry {
    int32_t offset;
    struct J9ROMFieldShape *field;
    struct J9Class *clazz;
} J9FlattenedClassCacheEntry;

typedef struct J9ROMClass {
    uint32_t modifiers;
    bool isArray;
} J9ROMClass;

#define J9_ARE_ANY_BITS_SET(flags, bits) ((flags) & (bits))
#define J9_ARE_NO_BITS_SET(flags, bits) (!((flags) & (bits)))
#define J9_ARE_ALL_BITS_SET(flags, bits) (((flags) & (bits)) == (bits))
#define J9_CLASS_FROM_CP(cp) ((J9Class*)((uintptr_t)(cp) - offsetof(J9Class, ramConstantPool)))
#define J9_CURRENT_CLASS(clazz) (clazz)
#define J9ROMFIELDREF_NAMEANDSIGNATURE(ref) ((J9ROMNameAndSignature*)((uint8_t*)(ref) + sizeof(J9ROMFieldRef)))
#define J9ROMNAMEANDSIGNATURE_NAME(nas) ((nas)->name)
#define J9ROMNAMEANDSIGNATURE_SIGNATURE(nas) ((nas)->signature)
#define J9ROMFIELDSHAPE_SIGNATURE(field) ((field)->signature)
#define J9_VM_FCC_ENTRY_FROM_FCC(fcc, index) (&(fcc)->entries[index])
#define J9_VM_FCC_CLASS_FROM_ENTRY(entry) ((entry)->clazz)
#define J9_IS_J9CLASS_VALUETYPE(clazz) (0)
#define J9ROMCLASS_IS_ARRAY(romClass) ((romClass)->isArray)
#define J9UTF8_DATA(utf8) ((char*)((utf8)->data))
#define J9UTF8_LENGTH(utf8) ((utf8)->length)

#define J9_RESOLVE_FLAG_JIT_COMPILE_TIME 0x01
#define J9_RESOLVE_FLAG_REDEFINE_CLASS 0x02
#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x04
#define J9_RESOLVE_FLAG_WITH_FIELD 0x08
#define J9_RESOLVE_FLAG_FIELD_SETTER 0x10
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x20

#define J9_LOOK_NO_THROW 0x01
#define J9_LOOK_NO_JAVA 0x02
#define J9_LOOK_NO_NESTMATES 0x04

#define J9_VISIBILITY_NON_MODULE_ACCESS_ERROR (-1)
#define J9_VISIBILITY_ALLOWED 0

#define J9AccPrivate 0x0002
#define J9AccProtected 0x0004
#define J9AccStatic 0x0008
#define J9AccFinal 0x0010

#define J9FieldFlagResolved 0x80000000
#define J9FieldFlagPutResolved 0x40000000
#define J9FieldFlagFlattened 0x20000000

#define J9_RUNTIME_VERIFY 0x01
#define J9ClassIsFlattened 0x1000

#define J9VMCONSTANTPOOL_JAVALANGILLEGALACCESSERROR 1
#define J9VMCONSTANTPOOL_JAVALANGVERIFYERROR 2

#define UDATA_MAX UINT32_MAX
#define IDATA int32_t
#define UDATA uint32_t
#define I_32 int32_t

#define PORT_ACCESS_FROM_VMC(vmStruct)
#define Trc_VM_resolveInstanceFieldRef_Entry(vmStruct, method, ramCP, cpIndex, resolveFlags, resolvedField)
#define Trc_VM_resolveInstanceFieldRef_Exit(vmStruct, fieldOffset)
#define Assert_VM_false(expr)
#define issueWriteBarrier()

extern J9Class* resolveClassRef(J9VMThread*, J9ConstantPool*, UDATA, UDATA);
extern IDATA checkVisibility(J9VMThread*, J9Class*, J9Class*, UDATA, UDATA);
extern bool isSameOrSuperClassOf(J9Class*, J9Class*);
extern bool finalFieldSetAllowed(J9VMThread*, bool, J9Method*, J9Class*, J9Class*, J9ROMFieldShape*, bool);
extern IDATA j9bcv_checkClassLoadingConstraintsForSignature(J9VMThread*, J9ClassLoader*, J9ClassLoader*, J9UTF8*, J9UTF8*);
extern char* illegalAccessMessage(J9VMThread*, IDATA, J9Class*, J9Class*, IDATA);
extern void setCurrentExceptionUTF(J9VMThread*, UDATA, char*);
extern void setCurrentException(J9VMThread*, UDATA, void*);
extern void j9mem_free_memory(void*);
extern IDATA instanceFieldOffsetWithSourceClass(J9VMThread*, J9Class*, char*, UDATA, char*, UDATA, J9Class**, UDATA*, UDATA, J9Class*);
extern UDATA findIndexInFlattenedClassCache(J9FlattenedClassCache*, J9ROMNameAndSignature*);