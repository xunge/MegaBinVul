#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uintptr_t UDATA;
typedef void* j9object_t;

struct J9ROMConstantPoolItem {
    UDATA data;
};

struct J9Method {
    // Method structure fields
    UDATA modifiers;
    UDATA bytecodes;
};

struct J9VMThread {
    struct J9JavaVM* javaVM;
};

struct J9ConstantPool {
    struct J9ROMConstantPoolItem* romConstantPool;
};

struct J9RAMInterfaceMethodRef {
    UDATA methodIndexAndArgCount;
    UDATA interfaceClass;
};

struct J9ROMMethodRef {
    UDATA classRefCPIndex;
    UDATA nameAndSignature;
};

struct J9Class {
    struct J9ROMClass* romClass;
    struct J9Method* ramMethods;
};

struct J9ROMNameAndSignature {
    UDATA name;
    UDATA signature;
};

struct J9JavaVM {
    struct MemoryManagerFunctions {
        j9object_t (*j9gc_createJavaLangString)(struct J9VMThread*, uint8_t*, UDATA, UDATA);
    } *memoryManagerFunctions;
};

struct J9ROMMethod {
    UDATA modifiers;
};

struct J9UTF8 {
    uint8_t* data;
    UDATA length;
};

struct J9ROMClass {
    UDATA modifiers;
    struct J9UTF8* className;
};

#define J9_ARE_ANY_BITS_SET(value, bits) ((value) & (bits))
#define J9_ARE_NO_BITS_SET(value, bits) (!((value) & (bits)))
#define J9_RESOLVE_FLAG_JIT_COMPILE_TIME 0x01
#define J9_RESOLVE_FLAG_REDEFINE_CLASS 0x02
#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x04
#define J9_RESOLVE_FLAG_JCL_CONSTANT_POOL 0x08
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x10
#define J9_LOOK_NO_THROW 0x01
#define J9_LOOK_NO_JAVA 0x02
#define J9_LOOK_INTERFACE 0x04
#define J9_LOOK_CLCONSTRAINTS 0x08
#define J9AccInterface 0x00000200
#define J9AccPrivate 0x00000002
#define J9AccPublic 0x00000001
#define J2SE_VERSION(vm) (0)
#define J2SE_V11 (0x0B00)
#define J9_ITABLE_INDEX_SHIFT 8
#define J9_ITABLE_INDEX_METHOD_INDEX 0x01
#define J9_ITABLE_INDEX_OBJECT 0x02
#define J9_STR_XLAT 0
#define J9VMCONSTANTPOOL_JAVALANGINCOMPATIBLECLASSCHANGEERROR 0
#define J9VMJAVALANGOBJECT_OR_NULL(vm) NULL

#define J9ROMCLASS_CLASSNAME(romClass) ((romClass)->className)
#define J9ROMFIELDREF_NAMEANDSIGNATURE(romRef) ((struct J9ROMNameAndSignature*)(romRef)->nameAndSignature)
#define J9_CLASS_FROM_CP(cp) ((struct J9Class*)((UDATA)(cp) + sizeof(struct J9ConstantPool)))
#define J9_CLASS_FROM_METHOD(method) ((struct J9Class*)((UDATA)(method) - offsetof(struct J9Class, ramMethods)))
#define J9_ROM_METHOD_FROM_RAM_METHOD(method) ((struct J9ROMMethod*)((UDATA)(method) - sizeof(struct J9ROMMethod)))
#define J9UTF8_DATA(utf8) ((utf8)->data)
#define J9UTF8_LENGTH(utf8) ((utf8)->length)
#define J9ROMMETHOD_HAS_VTABLE(romMethod) ((romMethod)->modifiers & 0x1000)

void Trc_VM_resolveInterfaceMethodRef_Entry(struct J9VMThread*, struct J9ConstantPool*, UDATA, UDATA);
void Trc_VM_resolveInterfaceMethodRef_lookupMethod(struct J9VMThread*, struct J9Method*);
void Trc_VM_resolveInterfaceMethodRef_Exit(struct J9VMThread*, struct J9Method*);
void checkForDecompile(struct J9VMThread*, struct J9ROMMethodRef*, bool);
struct J9Class* resolveClassRef(struct J9VMThread*, struct J9ConstantPool*, UDATA, UDATA);
void* javaLookupMethod(struct J9VMThread*, struct J9Class*, struct J9ROMNameAndSignature*, struct J9Class*, UDATA);
UDATA getITableIndexForMethod(struct J9Method*, struct J9Class*);
UDATA getVTableOffsetForMethod(struct J9Method*, struct J9Class*, struct J9VMThread*);
void setCurrentException(struct J9VMThread*, UDATA, UDATA*);
void setIllegalAccessErrorNonPublicInvokeInterface(struct J9VMThread*, struct J9Method*);
void Assert_VM_true(bool);