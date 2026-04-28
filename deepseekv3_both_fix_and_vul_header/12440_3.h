#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uintptr_t UDATA;
typedef uint8_t U_8;
typedef uint16_t U_16;
typedef bool BOOLEAN;
#define FALSE false

typedef struct J9UTF8 {
    uint16_t length;
    uint8_t data[1];
} J9UTF8;

typedef struct J9ROMNameAndSignature {
    J9UTF8 *name;
    J9UTF8 *signature;
} J9ROMNameAndSignature;

typedef struct J9NameAndSignature {
    J9UTF8 *name;
    J9UTF8 *signature;
} J9NameAndSignature;

typedef struct J9ROMMethodRef {
    uint16_t classRefCPIndex;
    J9ROMNameAndSignature nameAndSignature;
} J9ROMMethodRef;

typedef struct J9ROMClass {
    uint32_t modifiers;
    uint32_t *cpShapeDescription;
} J9ROMClass;

typedef struct J9JavaVM {
    UDATA hotSwapCount;
} J9JavaVM;

typedef struct J9VMThread {
    J9JavaVM *javaVM;
} J9VMThread;

typedef struct J9Class {
    J9ROMClass *romClass;
    UDATA initializeStatus;
} J9Class;

typedef struct J9Method {
    // Method structure fields
} J9Method;

typedef struct J9ConstantPool {
    J9ROMMethodRef *romConstantPool;
} J9ConstantPool;

typedef struct J9RAMStaticMethodRef {
    J9Method *method;
} J9RAMStaticMethodRef;

#define J9AccInterface 0x00000400
#define J9_ARE_ANY_BITS_SET(flags, bits) ((flags) & (bits))
#define J9_ARE_NO_BITS_SET(flags, bits) (!((flags) & (bits)))
#define J9_LOOK_NO_THROW 0x01
#define J9_LOOK_NO_JAVA 0x02
#define J9_LOOK_STATIC 0x04
#define J9_LOOK_CLCONSTRAINTS 0x08
#define J9_LOOK_INTERFACE 0x10
#define J9_LOOK_DIRECT_NAS 0x20
#define J9_LOOK_PARTIAL_SIGNATURE 0x40
#define J9_RESOLVE_FLAG_JIT_COMPILE_TIME 0x01
#define J9_RESOLVE_FLAG_REDEFINE_CLASS 0x02
#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x04
#define J9_RESOLVE_FLAG_JCL_CONSTANT_POOL 0x08
#define J9_RESOLVE_FLAG_NO_CLASS_INIT 0x10
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x20
#define J9CPTYPE_INTERFACE_STATIC_METHOD 0x01
#define J9CPTYPE_INTERFACE_INSTANCE_METHOD 0x02
#define J9CPTYPE_INTERFACE_METHOD 0x03
#define J2SE_V11 0x0B00
#define J2SE_VERSION(vm) (0)
#define J9ClassInitSucceeded 0
#define J9_CP_TYPE(desc, index) (0)
#define J9VMCONSTANTPOOL_JAVALANGINCOMPATIBLECLASSCHANGEERROR 0

#define Trc_VM_resolveStaticMethodRef_Entry(a,b,c,d)
#define Trc_VM_resolveStaticMethodRef_lookupMethod(a,b)
#define Trc_VM_resolveStaticMethodRef_Exit(a,b)

J9Class* resolveClassRef(J9VMThread*, J9ConstantPool*, UDATA, UDATA);
void checkForDecompile(J9VMThread*, J9ROMMethodRef*, bool);
J9Method* javaLookupMethod(J9VMThread*, J9Class*, J9ROMNameAndSignature*, J9Class*, UDATA);
void setCurrentException(J9VMThread*, int32_t, void*);
void initializeClass(J9VMThread*, J9Class*);
bool threadEventsPending(J9VMThread*);
bool isMethodHandleINL(U_8*, U_16);
J9Class* J9VMJAVALANGINVOKEMETHODHANDLE(J9JavaVM*);
J9Class* J9_CLASS_FROM_CP(J9ConstantPool*);
J9Class* J9_CLASS_FROM_METHOD(J9Method*);
J9ROMNameAndSignature* J9ROMMETHODREF_NAMEANDSIGNATURE(J9ROMMethodRef*);
J9UTF8* J9ROMNAMEANDSIGNATURE_NAME(J9ROMNameAndSignature*);
uint8_t* J9UTF8_DATA(J9UTF8*);
uint16_t J9UTF8_LENGTH(J9UTF8*);
uint32_t* J9ROMCLASS_CPSHAPEDESCRIPTION(J9ROMClass*);