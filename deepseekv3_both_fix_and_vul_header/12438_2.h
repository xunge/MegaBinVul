#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef uintptr_t UDATA;
typedef uint32_t U_32;
typedef uint16_t U_16;
typedef uint8_t U_8;
typedef intptr_t IDATA;
typedef void* j9object_t;

#define J9_ARE_ANY_BITS_SET(value, bits) ((value) & (bits))
#define J9_ARE_NO_BITS_SET(value, bits) (!((value) & (bits)))
#define J9_CP_TYPE(cpShapeDescription, index) 0
#define J9UTF8_LITERAL_EQUALS(data, length, literal) \
    ((length) == (sizeof(literal)-1) && (0 == memcmp((data), (literal), (length)))
#define J9UTF8_SET_LENGTH(utf8, length) ((utf8)->length = (length))
#define J9UTF8_DATA(utf8) ((utf8)->data)
#define J9UTF8_LENGTH(utf8) ((utf8)->length)
#define J9ROMFIELDREF_NAMEANDSIGNATURE(ref) (&(ref)->nameAndSignature)
#define J9ROMNAMEANDSIGNATURE_NAME(nas) ((J9UTF8*)(nas)->name)
#define J9ROMNAMEANDSIGNATURE_SIGNATURE(nas) ((J9UTF8*)(nas)->signature)
#define J9_CLASS_FROM_CP(cp) ((J9Class*)(cp)->ramClass)
#define J9ROMCLASS_CPSHAPEDESCRIPTION(romClass) ((U_32*)(romClass)->cpShapeDescription)
#define J9_ROM_METHOD_FROM_RAM_METHOD(method) ((J9ROMMethod*)(method)->romMethod)
#define J9ROMMETHOD_HAS_VTABLE(romMethod) ((romMethod)->modifiers & J9AccMethodVTable)
#define J9VTABLE_INVOKE_PRIVATE_OFFSET 0
#define MAX_STACK_SLOTS 255
#define NNSRP_SET(field, value) ((field) = (value))
#define J9STATIC_OBJECT_STORE(vmThread, clazz, address, value) (*(address) = (value))
#define J9_RESOLVE_FLAG_JIT_COMPILE_TIME 0x01
#define J9_RESOLVE_FLAG_REDEFINE_CLASS 0x02
#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x04
#define J9_RESOLVE_FLAG_JCL_CONSTANT_POOL 0x08
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x10
#define J9_LOOK_NO_THROW 0x01
#define J9_LOOK_NO_JAVA 0x02
#define J9_LOOK_VIRTUAL 0x04
#define J9_LOOK_CLCONSTRAINTS 0x08
#define J9_LOOK_DIRECT_NAS 0x10
#define J9_LOOK_PARTIAL_SIGNATURE 0x20
#define J9CPTYPE_HANDLE_METHOD 0
#define J9AccInterface 0x00000200
#define J9AccMethodVTable 0x00000010
#define J9VMCONSTANTPOOL_JAVALANGINCOMPATIBLECLASSCHANGEERROR 0
#define J9VMCONSTANTPOOL_JAVALANGLINKAGEERROR 0
#define J9VMCONSTANTPOOL_JAVALANGNULLPOINTEREXCEPTION 0
#define J9NLS_VM_TOO_MANY_ARGUMENTS 0

typedef struct J9VMThread J9VMThread;
typedef struct J9ConstantPool J9ConstantPool;
typedef struct J9RAMVirtualMethodRef J9RAMVirtualMethodRef;
typedef struct J9Method J9Method;
typedef struct J9Class J9Class;
typedef struct J9JavaVM J9JavaVM;
typedef struct J9ROMMethodRef J9ROMMethodRef;
typedef struct J9ROMNameAndSignature J9ROMNameAndSignature;
typedef struct J9UTF8 J9UTF8;
typedef struct J9ROMMethod J9ROMMethod;
typedef struct J9ROMClass J9ROMClass;
typedef struct J9RAMMethodRef J9RAMMethodRef;
typedef struct J9NameAndSignature J9NameAndSignature;

struct J9UTF8 {
    U_16 length;
    U_8 data[1];
};

struct J9ROMNameAndSignature {
    J9UTF8 *name;
    J9UTF8 *signature;
};

struct J9ROMMethodRef {
    U_16 classRefCPIndex;
    struct J9ROMNameAndSignature nameAndSignature;
};

struct J9JavaVM {
    void *memoryManagerFunctions;
};

struct J9VMThread {
    J9JavaVM *javaVM;
    void *currentException;
    void *returnValue;
};

struct J9ConstantPool {
    U_8 *romConstantPool;
    J9Class *ramClass;
};

struct J9Class {
    J9ROMClass *romClass;
    void *classLoader;
    void *methodTypes;
    void *varHandleMethodTypes;
    J9Class *superclass;
};

struct J9ROMClass {
    U_32 *cpShapeDescription;
    U_32 modifiers;
};

struct J9RAMVirtualMethodRef {
    J9Method *method;
    UDATA methodIndexAndArgCount;
};

struct J9Method {
    void *romMethod;
};

struct J9ROMMethod {
    U_32 modifiers;
};

#define Trc_VM_resolveVirtualMethodRef_Entry(vmStruct, ramCP, cpIndex, resolveFlags, resolvedMethod)
#define Trc_VM_resolveVirtualMethodRef_lookupMethod(vmStruct, method)
#define Trc_VM_resolveVirtualMethodRef_Exit(vmStruct, vTableOffset)
#define Trc_VM_Assert_ShouldNeverHappen()

static void checkForDecompile(J9VMThread *vmStruct, J9ROMMethodRef *romMethodRef, bool jitCompileTimeResolve) {}
static J9Class *resolveClassRef(J9VMThread *vmStruct, J9ConstantPool *ramCP, UDATA cpIndex, UDATA resolveFlags) { return NULL; }
static void *javaLookupMethod(J9VMThread *vmStruct, J9Class *resolvedClass, J9ROMNameAndSignature *nameAndSig, J9Class *cpClass, UDATA lookupOptions) { return NULL; }
static UDATA getVTableOffsetForMethod(J9Method *method, J9Class *resolvedClass, J9VMThread *vmStruct) { return 0; }
static j9object_t methodToString(J9VMThread *vmStruct, J9Method *method) { return NULL; }
static void setCurrentException(J9VMThread *vmStruct, UDATA exception, UDATA *data) {}
static void setCurrentExceptionNLS(J9VMThread *vmStruct, UDATA exception, UDATA nls) {}
static bool threadEventsPending(J9VMThread *vmStruct) { return false; }
static void sendFromMethodDescriptorString(J9VMThread *vmStruct, J9UTF8 *sigUTF, void *classLoader, J9Class *clazz) {}
static bool isMethodHandleINL(U_8* methodName, U_16 methodNameLength) { return false; }
static J9Class* J9VMJAVALANGINVOKEMETHODHANDLE(J9JavaVM *vm) { return NULL; }
static J9Class* J9VMJAVALANGINVOKEVARHANDLE_OR_NULL(J9JavaVM *vm) { return NULL; }
static U_32 VM_VMHelpers_lookupVarHandleMethodTypeCacheIndex(J9ROMClass *romClass, UDATA cpIndex) { return 0; }
static J9Class* VM_VMHelpers_getSuperclass(J9Class *clazz) { return clazz->superclass; }
static void VM_VMHelpers_clearException(J9VMThread *vmStruct) {}